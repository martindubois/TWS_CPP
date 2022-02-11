
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CONST/ClassD.h

#pragma once

class ClassD
{

public:

    ClassD(const char* aName);

    ClassD(const ClassD& aIn);

    ~ClassD();

    const char* GetName() const;

private:

    void SetName(const char* aName);

    char* mName;

};
