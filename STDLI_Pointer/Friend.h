
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      STDLI_Pointer/Friend.h

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

private:

    Friend(const Friend&);

    std::string mFirstName;
    std::string mLastName;

};
