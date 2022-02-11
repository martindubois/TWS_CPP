
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CONST/ClassE.cpp

// ===== C ==================================================================
#include <assert.h>

// ===== CONST ==============================================================
#include "ClassE.h"

// Public
// //////////////////////////////////////////////////////////////////////////

const char* ClassE::GetName() const
{
    return mName.c_str();
}

void ClassE::SetName(const char* aIn)
{
    assert(NULL != aIn);

    mName = aIn;
}
