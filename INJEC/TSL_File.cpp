
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      INJEC/TempSensor.cpp

// ===== C ==================================================================
#include <assert.h>

// ===== Windows ============================================================
#include <Windows.h>

// ===== INJEC ==============================================================
#include "TSL_File.h"

// Public
// //////////////////////////////////////////////////////////////////////////

TSL_File::TSL_File(const char* aFileName) : mFile(aFileName)
{
}

// ===== ITempSensorLink ====================================================

void TSL_File::GetData(double* aHumidity_pc, double* aTemp_C)
{
    assert(NULL != aHumidity_pc);
    assert(NULL != aTemp_C);

    // Si nous avons atteint la fin du fichier de donnees, nous retournons au
    // debut.
    if (mFile.eof())
    {
        mFile.seekg(0);
    }

    mFile >> *aHumidity_pc;
    mFile >> *aTemp_C;

    Sleep(1000);
}
