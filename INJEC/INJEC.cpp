
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      INJEC/INJEC.cpp

// ===== C ==================================================================
#include <signal.h>

// ===== C++ ================================================================
#include <iostream>

// ====== INJECT ============================================================
#include "TempSensor.h"

// Static variable
// //////////////////////////////////////////////////////////////////////////

static bool sStop;

// Static function declarations
// //////////////////////////////////////////////////////////////////////////

static void _cdecl OnSigInt(int aSignal);

// Entry point
// //////////////////////////////////////////////////////////////////////////

int main(int aCount, const char ** aVector)
{
    if (2 > aCount)
    {
        std::cerr << "USER ERROR  You must pass the COM port name as first argument\n";
        return 1;
    }

    signal(SIGINT, OnSigInt);

    std::cout << "INSTRUCTION  Press Ctrl-C to stop\n";

    try
    {
        TempSensor lTS(aVector[1]);

        while (!sStop)
        {
            double lHumidity_pc;
            double lTemp_C;

            lTS.GetData(&lHumidity_pc, &lTemp_C);

            printf("Humidity: %.1f %%, Temperature: %.1f C\r", lHumidity_pc, lTemp_C);
        }

        std::cout << "Stopped\n";
    }
    catch (std::exception eE)
    {
        std::cerr << "EXCEPTION  " << eE.what() << "\n";
        return 2;
    }

    return 0;
}

// Static function
// //////////////////////////////////////////////////////////////////////////

void OnSigInt(int aSignal)
{
    std::cout << "\nCtrl-C\n";

    sStop = true;
}
