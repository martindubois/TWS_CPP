
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      Common/LIBST/Rocket.h

#pragma once

// ===== Common/LIBST ===================================================
#include <LIBST/AutoPilote.h>
#include <LIBST/Motor.h>
#include <LIBST/Tank.h>

namespace LIBST
{

    class Rocket
    {

    public:

        Rocket();

        void Command(char aLetter);

        double GetAltitude() const;
        double GetSpeed() const;

        void Simulate();

        AutoPilote mAutoPilote;
        Motor      mMotor;
        Tank       mTank;

    private:

        void Pause();
        void Resume();

        bool mPause;

        double mAltitude_m;
        double mSpeed_m_s;

        uint64_t mTime_100ns;

    };

}

std::ostream& operator << (std::ostream& aOut, const LIBST::Rocket& aRocket);
