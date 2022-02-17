
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http ://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      LISTE/Friend.h

#pragma once

// ===== C++ ================================================================
#include <string>

class Friend
{

public:

    Friend();

    void Display() const;

    const char* GetFirstName() const;
    const char* GetLastName () const;

    void Initialise(const char* aFirstName, const char* aLastName);

    Friend* Next_Get();

    void Next_Set(Friend* aNext);

private:

    Friend(const Friend&);

    Friend* mNext;

    std::string mFirstName;
    std::string mLastName;

};
