
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      NOON0/AutoPilote.h

#pragma once

// ===== MOON0 ==============================================================
class Motor;
class Tank;

class AutoPilote
{

public:

    AutoPilote();

    void Disable();
    void Enable ();

    bool IsEnabled() const;

    // QUESTION - Revision
    // Est-ce que ces deux methodes vous rapellent quelque chose ?
    void SetMotor(Motor* aMotor);
    void SetTank (Tank * aTank);

    void Simulate(double aAltitude_m, double aSpeed_m_s);

private:

    bool mEnable;

    Motor* mMotor;
    Tank * mTank;

};

// TODO
// Declarer l'operateur permettant d'afficher l'etat en utilisant la classe
// ostream.
