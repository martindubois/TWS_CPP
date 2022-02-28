
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CLASS/Form_Square.cpp

// ===== C ==================================================================
#include <assert.h>

// ===== CLASS ==============================================================
#include "Form_Square.h"

// Public
// //////////////////////////////////////////////////////////////////////////

Form_Square::Form_Square() : mBase_mm(1.0)
{
}

// ===== Form ===============================================================

Form_Square::~Form_Square()
{
}

double Form_Square::GetArea() const
{
    return mBase_mm * mBase_mm;
}

double Form_Square::GetPerimeter() const
{
    return 4 * mBase_mm;
}

unsigned int Form_Square::GetInfoCount() const
{
    return 1;
}

const char* Form_Square::GetInfoName(unsigned int aIndex) const
{
    const char* lResult = NULL;

    switch (aIndex)
    {
    case 0: lResult = "la base en mm"; break;

    default: assert(false);
    }

    return lResult;
}

void Form_Square::SetInfo(unsigned int aIndex, double aValue)
{
    switch (aIndex)
    {
    case 0: mBase_mm = aValue; break;

    default: assert(false);
    }
}
