
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http ://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      LISTE/Friend.cpp

// ===== C ==================================================================
#include <assert.h>

// ===== LISTE ==============================================================
#include "Friend.h"

// Public
// //////////////////////////////////////////////////////////////////////////

Friend::Friend()
{
}

void Friend::Display() const
{
    printf("%s %s\n", mFirstName.c_str(), mLastName.c_str());
}

const char* Friend::GetFirstName() const { return mFirstName.c_str(); }
const char* Friend::GetLastName () const { return mLastName .c_str(); }

void Friend::Initialise(const char* aFirstName, const char* aLastName)
{
    assert(NULL != aFirstName);
    assert(NULL != aLastName);

    mFirstName = aFirstName;
    mLastName  = aLastName;
}

Friend* Friend::Next_Get()
{
    return mNext;
}

void Friend::Next_Set(Friend* aNext)
{
    mNext = aNext;
}
