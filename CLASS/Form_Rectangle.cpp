
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http ://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CLASS/Form_Rectangle.cpp

// ===== C ==================================================================
#include <assert.h>

// ===== CLASS ==============================================================
#include "Form_Rectangle.h"

// Public
// //////////////////////////////////////////////////////////////////////////

Form_Rectangle::Form_Rectangle() : mBase_mm(1.0), mSide_mm(1.0)
{
}

// ===== Form ===============================================================

Form_Rectangle::~Form_Rectangle()
{
}

double Form_Rectangle::GetArea() const
{
    return mBase_mm * mSide_mm;
}

double Form_Rectangle::GetPerimeter() const
{
    return 2 * mBase_mm + 2 * mSide_mm;
}

unsigned int Form_Rectangle::GetInfoCount() const
{
    return 2;
}

const char* Form_Rectangle::GetInfoName(unsigned int aIndex) const
{
    const char* lResult = NULL;

    switch (aIndex)
    {
    case 0: lResult = "la base en mm"; break;
    case 1: lResult = "le cote en mm"; break;

    default: assert(false);
    }

    return lResult;
}

void Form_Rectangle::SetInfo(unsigned int aIndex, double aValue_mm)
{
    switch (aIndex)
    {
    case 0: mBase_mm = aValue_mm; break;
    case 1: mSide_mm = aValue_mm; break;

    default: assert(false);
    }
}
