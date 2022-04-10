
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      NOON0/Motor.h

#include "Component.h"

// ===== MOON0 ==============================================================
#include "Tank.h"

#include "Motor.h"

// Constants
// //////////////////////////////////////////////////////////////////////////

#define ACCELERATION_MAX_m_s2 (3.0)

#define POWER_MAX_l_s (2.0)

// Remarquez que le moteur est a sa meilleur efficacite entre 60 et 80 % de
// puissance
const double EFFICIENCY[] =
{
    0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.0, 1.0, 0.95, 0.9
};

// Public
// //////////////////////////////////////////////////////////////////////////

Motor::Motor() : mPower(0.0), mTank(NULL)
{
}

double Motor::GetAcceleration(double aDelta_s)
{
    assert(0.0 < aDelta_s);

    assert(0.0 <= mPower);
    assert(1.0 >= mPower);
    
    double lFuel_l = mPower * POWER_MAX_l_s * aDelta_s;

    mPower *= mTank->GetFuel(lFuel_l);

    double lEfficiency = EFFICIENCY[static_cast<unsigned int>(10 * mPower)];

    return mPower * lEfficiency * ACCELERATION_MAX_m_s2;
}

double Motor::GetPower() const { return mPower; }

void Motor::FullPower() { mPower = 1.0; }
void Motor::HalfPower() { mPower = 0.5; }
void Motor::Off      () { mPower = 0.0; }

void Motor::SetTank(Tank* aTank) { mTank = aTank; }
