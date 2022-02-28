
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      STDLI_Instance/Friend.h

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

    std::string mFirstName;
    std::string mLastName;

};
