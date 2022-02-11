
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CONST/ClassC.cpp

// ===== C ==================================================================
#include <assert.h>
#include <string.h>

// ===== CONST ==============================================================
#include "ClassC.h"

// Public
// //////////////////////////////////////////////////////////////////////////

ClassC::ClassC(const char* aName)
{
    assert(NULL != aName);

    unsigned int lLen = strlen(aName);

    mName = new char[lLen + 1];

    strcpy_s(mName, lLen + 1, aName);
}

ClassC::~ClassC()
{
    delete[] mName;
}

const char* ClassC::GetName() const
{
    return mName;
}
