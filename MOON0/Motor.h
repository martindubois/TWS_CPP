
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      NOON0/Motor.h

#pragma once

// ===== MOON0 ==============================================================
class Tank;

class Motor
{

public:

    Motor();

    const Motor & operator ++ (int);
    const Motor & operator -- (int);

    double GetAcceleration(double aDelta_s);

    double GetPower() const;

    void FullPower();
    void HalfPower();

    void Off();

    void SetTank(Tank * aTank);

private:

    double mPower;

    Tank* mTank;

};

std::ostream& operator << (std::ostream& aOut, const Motor& aMotor);
