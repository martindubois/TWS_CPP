
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      NOON0/Rocket.h

#pragma once

// ===== MOON0 ==============================================================
#include "AutoPilote.h"
#include "Motor.h"
#include "Tank.h"

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

// TODO
// Declarer l'operateur permettant d'afficher les informations en utilisant
// la class ostream.
