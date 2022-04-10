
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      NOON0/Tank.cpp

#include "Component.h"

// ===== MOON0 ==============================================================
#include "Tank.h"

// Constant
// //////////////////////////////////////////////////////////////////////////

#define INITIAL_LEVEL_l (100.0)

// Public
// //////////////////////////////////////////////////////////////////////////

Tank::Tank() : mLevel_l(INITIAL_LEVEL_l)
{
}

// Cette methode retourne la proportion de carburant retournee par rapport a
// la demande. En generale, elle retourne 1.0 pour indiquer que tout le
// carburant disponible est disponible. Si le reservoire est vide et que le
// moteur demande du carburant, elle retourne 0.0 pour indiquer qu'il n'y a
// plus de carburant disponible.
double Tank::GetFuel(double aRequested_l)
{
    assert(0.0 <= aRequested_l);

    double lResult = 1.0;

    if (0.0 < aRequested_l)
    {
        if (mLevel_l <= aRequested_l)
        {
            // Oups! Pas assez de carburant.

            lResult = mLevel_l / aRequested_l;

            mLevel_l = 0.0;
        }
        else
        {
            mLevel_l -= aRequested_l;
        }
    }

    assert(0.0 <= mLevel_l);

    assert(0.0 <= lResult);
    assert(1.0 >= lResult);

    return lResult;
}

double Tank::GetLevel() const { return mLevel_l; }

// TODO
// Definir l'operateur d'affichage
