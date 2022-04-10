
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      NOON0/Rocket.cpp

#include "Component.h"

// ===== MOON0 ==============================================================
#include "Rocket.h"

// Constants
// //////////////////////////////////////////////////////////////////////////

#define INITIAL_ALTITUDE_m (1000.0)
#define INITIAL_SPEED_m_s  (  -0.0)

#define MOON_G_m_s2 (-1.62)

// Public
// //////////////////////////////////////////////////////////////////////////

Rocket::Rocket() : mAltitude_m(INITIAL_ALTITUDE_m), mPause(true), mSpeed_m_s(INITIAL_SPEED_m_s)
{
    mAutoPilote.SetMotor(&mMotor);
    mAutoPilote.SetTank (&mTank);

    mMotor.SetTank(&mTank);
}

// Les commandes !
// -    Diminue la puissance de 0.1
// +    Augmente la puissance de 0.1
// *    Augmente la puissance a 1.0
// /    Place la puissance a 0.5
// 0    Diminue la puissance a 0
// A    Active l'auto pilote
// M    Desactive l'auto pilote
// P    Pause le jeu
// R    Resume le jeu
void Rocket::Command(char aLetter)
{
    switch (aLetter)
    {
    case '-': break; // TODO mMotor--;
    case '+': break; // TODO mMotor++;
    case '*': mMotor.FullPower(); break;
    case '/': mMotor.HalfPower(); break;

    case '0': mMotor.Off(); break;

    case 'A': case 'a': mAutoPilote.Enable (); break;
    case 'M': case 'm': mAutoPilote.Disable(); break;

    case 'P': case 'p': Pause (); break;
    case 'R': case 'r': Resume(); break;
    }
}

double Rocket::GetAltitude() const { return mAltitude_m; }
double Rocket::GetSpeed   () const { return mSpeed_m_s ; }

void Rocket::Simulate()
{
    if (!mPause)
    {
        uint64_t lNow_100ns;

        GetSystemTimeAsFileTime(reinterpret_cast<FILETIME*>(&lNow_100ns));

        uint64_t lDelta_100ns = lNow_100ns - mTime_100ns;
        if (0 < lDelta_100ns)
        {
            mAutoPilote.Simulate(mAltitude_m, mSpeed_m_s);

            double lDelta_s = static_cast<double>(lDelta_100ns); lDelta_s /= 10000000.0;

            double lAcceleration_m_s2 = MOON_G_m_s2;

            lAcceleration_m_s2 += mMotor.GetAcceleration(lDelta_s);

            mAltitude_m += mSpeed_m_s * lDelta_s + lAcceleration_m_s2 * lDelta_s * lDelta_s / 2;
            mSpeed_m_s += lAcceleration_m_s2 * lDelta_s;

            mTime_100ns = lNow_100ns;
        }
    }
}

// Private
// //////////////////////////////////////////////////////////////////////////

void Rocket::Pause()
{
    mPause = true;
}

void Rocket::Resume()
{
    GetSystemTimeAsFileTime(reinterpret_cast<FILETIME*>(&mTime_100ns));

    mPause = false;
}
