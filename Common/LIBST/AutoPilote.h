
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      Common/LIBST/AutoPilote.h

#pragma once

namespace LIBST
{

    // ===== Common/LIBST ===================================================
    class Motor;
    class Tank;

    class AutoPilote
    {

    public:

        AutoPilote();

        void Disable();
        void Enable();

        bool IsEnabled() const;

        void SetMotor(Motor* aMotor);
        void SetTank(Tank* aTank);

        void Simulate(double aAltitude_m, double aSpeed_m_s);

        // internal

        double GetTargetSpeed() const;

    private:

        bool mEnable;

        Motor* mMotor;
        Tank* mTank;

        double mTargetSpeed_m_s;

    };

}

std::ostream& operator << (std::ostream& aOut, const LIBST::AutoPilote& aAuto);
