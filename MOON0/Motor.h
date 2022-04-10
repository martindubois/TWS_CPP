
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

    // TODO
    // Declarer les operateurs -- et ++. Ils changent la puissance par
    // increment de 0.1.

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

// TODO
// Declarer l'operateur permettant d'afficher le niveau de carburant en
// utilisant la class ostream.
