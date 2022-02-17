
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http ://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CLASS/Form_Parallelogram.cpp

// ===== C ==================================================================

#define _USE_MATH_DEFINES

#include <assert.h>
#include <math.h>

// ===== CLASS ==============================================================
#include "Form_Parallelogram.h"

// Public
// //////////////////////////////////////////////////////////////////////////

Form_Parallelogram::Form_Parallelogram() : mAngle_deg(45.0), mBase_mm(1.0), mSide_mm(1.0)
{
}

// ===== Form ===============================================================

Form_Parallelogram::~Form_Parallelogram()
{
}

double Form_Parallelogram::GetArea() const
{
    double lAngle_rad = mAngle_deg * 2 * M_PI / 360;

    return mBase_mm * mSide_mm * sin(lAngle_rad);
}

double Form_Parallelogram::GetPerimeter() const
{
    return 2 * mBase_mm + 2 * mSide_mm;
}

unsigned int Form_Parallelogram::GetInfoCount() const
{
    return 3;
}

const char* Form_Parallelogram::GetInfoName(unsigned int aIndex) const
{
    const char* lResult = NULL;

    switch (aIndex)
    {
    case 0: lResult = "l'angle en deg."; break;
    case 1: lResult = "la base en mm"  ; break;
    case 2: lResult = "le cote en mm"  ; break;

    default: assert(false);
    }

    return lResult;
}

void Form_Parallelogram::SetInfo(unsigned int aIndex, double aValue)
{
    switch (aIndex)
    {
    case 0: mAngle_deg = aValue; break;
    case 1: mBase_mm   = aValue; break;
    case 2: mSide_mm   = aValue; break;

    default: assert(false);
    }
}
