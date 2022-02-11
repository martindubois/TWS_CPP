
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CONST/ClassE.h

#pragma once

// ===== C++ ================================================================
#include <string>

class ClassE
{

public:

    const char* GetName() const;

    void SetName(const char* aIn);

private:

    std::string mName;

};
