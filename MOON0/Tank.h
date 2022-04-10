
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      NOON0/Tank.h

#pragma once

class Tank
{

public:

    Tank();

    double GetFuel(double aRequested_l);

    double GetLevel() const;

private:

    double mLevel_l;

};

// TODO
// Declarer l'operateur permettant d'afficher la puissance en utilisant la
// class ostream.
