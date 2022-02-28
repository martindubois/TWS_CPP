
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/IFileInfo.h

#pragma once

class IFileInfo
{

public:

    virtual ~IFileInfo() = 0;

    virtual void Init(const char* aFolder, const char* aFile) = 0;

    virtual void DisplayInformation() const = 0;

    virtual void RetrieveInformation() = 0;

};
