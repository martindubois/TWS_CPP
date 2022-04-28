
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      LIBDY/Rocket.h

#pragma once

// ===== Common =============================================================
#include <LIBDY/IRocket.h>

// ===== LIBDY ==============================================================
#include "AutoPilote.h"
#include "Motor.h"
#include "Tank.h"

class Rocket : public LIBDY::IRocket
{

public:

    Rocket();

    AutoPilote mAutoPilote;
    Motor      mMotor;
    Tank       mTank;

    // ===== LIBDY::Rocket ==================================================

    virtual void Destroy();

    virtual void Command(char aLetter);

    virtual double GetAltitude() const;
    virtual double GetSpeed   () const;

    virtual void Simulate();

private:

    void Pause();
    void Resume();

    bool mPause;

    double mAltitude_m;
    double mSpeed_m_s;

    uint64_t mTime_100ns;

};

std::ostream& operator << (std::ostream& aOut, const Rocket& aRocket);
