
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CONST/ClassD.cpp

// ===== C ==================================================================
#include <assert.h>
#include <string.h>

// ===== CONST ==============================================================
#include "ClassD.h"

// Public
// //////////////////////////////////////////////////////////////////////////

ClassD::ClassD(const char* aName)
{
    SetName(aName);
}

// QUESTION Que fait le constructeur par copie de la classe ClassD ?
ClassD::ClassD(const ClassD& aIn)
{
    SetName(aIn.GetName());
}

ClassD::~ClassD()
{
    delete[] mName;
}

const char* ClassD::GetName() const
{
    return mName;
}

// Private
// //////////////////////////////////////////////////////////////////////////

void ClassD::SetName(const char* aName)
{
    assert(NULL != aName);

    unsigned int lLen = strlen(aName);

    mName = new char[lLen + 1];

    strcpy_s(mName, lLen + 1, aName);
}
