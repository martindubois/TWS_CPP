
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      MOON0/MOON0.cpp

#include "Component.h"

// ===== Moon0 ==============================================================
#include "Rocket.h"

int main()
{
    HANDLE lConsole = GetStdHandle(STD_INPUT_HANDLE);

    Rocket lRocket;

    while (0.0 < lRocket.GetAltitude())
    {
        DWORD lCount;
        INPUT_RECORD lRecord;

        if (PeekConsoleInput(lConsole, &lRecord, 1, &lCount) && (0 < lCount))
        {
            BOOL lRet = ReadConsoleInput(lConsole, &lRecord, 1, &lCount);
            assert(lRet);
            assert(1 == lCount);

            if (KEY_EVENT == lRecord.EventType)
            {
                lRocket.Command(lRecord.Event.KeyEvent.uChar.AsciiChar);
            }
        }

        lRocket.Simulate();

        // TODO std::cout << lRocket;
        printf("Altitude: %4.1f m - Speed: %3.1f m/s - Power: %3.1f %% - Fuel: %3.1f l - %s  \r",
            lRocket.GetAltitude(),
            lRocket.GetSpeed(),
            lRocket.mMotor.GetPower() * 100.0,
            lRocket.mTank.GetLevel(),
            lRocket.mAutoPilote.IsEnabled() ? "Auto" : "Manual");
    }

    double lFinalSpeed_m_s = lRocket.GetSpeed();
    std::cout << "\nLanding at " << lFinalSpeed_m_s << " m/s\n";

    if      (- 0.1 <= lFinalSpeed_m_s) { std::cout << "Perfect landing!\n"; }
    else if (- 0.2 <= lFinalSpeed_m_s) { std::cout << "Good landing!\n"; }
    else if (- 0.5 <= lFinalSpeed_m_s) { std::cout << "Hard landing!\n"; }
    else if (- 1.0 <= lFinalSpeed_m_s) { std::cout << "Minor damage!\n"; }
    else { std::cout << "Crash!\n"; }
}
