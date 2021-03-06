
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      INJEC/TempSensor.cpp

// ===== C ==================================================================
#include <assert.h>

// ===== INJEC ==============================================================
#include "TempSensor.h"

// Constants
// //////////////////////////////////////////////////////////////////////////

#define SYNC static_cast<int8_t>(0xff)

// Public
// //////////////////////////////////////////////////////////////////////////

TempSensor::TempSensor(const char* aComPortName)
{
    assert(NULL != aComPortName);

    mSum.mHumidity_pc = 0.0;
    mSum.mTemp_C      = 0.0;

    // Ouvrir le port COM
    mComPort = CreateFile(aComPortName, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (INVALID_HANDLE_VALUE == mComPort)
    {
        throw std::exception("CreateFile( , , , , , ,  ) failed");
    }

    // Obtenir la configuration actuel du port COM

    DCB lDCB;

    memset(&lDCB, 0, sizeof(lDCB));

    lDCB.DCBlength = sizeof(lDCB);

    if (!GetCommState(mComPort, &lDCB))
    {
        throw std::exception("GetCommState( ,  ) failed");
    }

    // Modifier le configuration du port COM

    lDCB.fBinary = true;
    lDCB.BaudRate = CBR_115200;
    lDCB.ByteSize = 8;
    lDCB.StopBits = ONESTOPBIT;
    lDCB.fParity = NOPARITY;

    if (!SetCommState(mComPort, &lDCB))
    {
        throw std::exception("SetCommState( ,  ) failed");
    }
}

TempSensor::~TempSensor()
{
    assert(INVALID_HANDLE_VALUE != mComPort);

    BOOL lRet = CloseHandle(mComPort);
    assert(lRet);

    (void)lRet;
}

// Cette fonction lit 3 octets du port COM. Le senseur transmet constament
// des donnees et il est impossible de savoir combien nous avons perdu
// d'octet avant de nous connecter. Il est facile de nous synchroniser car
// nous savons que le senseur envoit toujours une valeur de synchronisation
// (0xff) suivie du pourcentage d'humidite et de la temperature en Celcius.
// Les trois condition en fin de fonction dertermine la position de l'octet
// de synchronisation et par le fait meme la position des deux donnees. Si un
// ensemble de 3 octets ne contient pas d'octets de synchronisation, les
// donnees sont erronees.
void TempSensor::GetData(double* aHumidity_pc, double* aTemp_C)
{
    assert(NULL != aHumidity_pc);
    assert(NULL != aTemp_C);

    // La temperature peut etre negative, il faud donc utiliser un type
    // signe.
    int8_t lRaw[3];
    DWORD  lSize_byte;

    if (!ReadFile(mComPort, lRaw, sizeof(lRaw), &lSize_byte, NULL))
    {
        throw std::exception("ReadFile( , , , ,  ) failed");
    }

    assert(sizeof(lRaw) == lSize_byte);

    Data lData;

    if      (SYNC == lRaw[0]) { lData.mHumidity_pc = lRaw[1]; lData.mTemp_C = lRaw[2]; }
    else if (SYNC == lRaw[1]) { lData.mHumidity_pc = lRaw[2]; lData.mTemp_C = lRaw[0]; }
    else if (SYNC == lRaw[2]) { lData.mHumidity_pc = lRaw[0]; lData.mTemp_C = lRaw[1]; }
    else
    {
        throw std::exception("Corrupted data");
    }

    mSum.mHumidity_pc += lData.mHumidity_pc;
    mSum.mTemp_C      += lData.mTemp_C;

    mList.push_front(lData);

    unsigned int lLen = mList.size();
    if (10 < lLen)
    {
        mSum.mHumidity_pc -= mList.back().mHumidity_pc;
        mSum.mTemp_C      -= mList.back().mTemp_C;

        mList.pop_back();
        lLen--;
    }

    *aHumidity_pc = mSum.mHumidity_pc / lLen;
    *aTemp_C      = mSum.mTemp_C      / lLen;
}
