
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/IFileInfo.h

#pragma once

// ===== C++ ================================================================
#include <list>

class IFileInfo
{

public:

    virtual ~IFileInfo() = 0;

    virtual void Init(const char* aFolder, const char* aFile) = 0;

    virtual void DisplayInformation(unsigned int aIndent = 0) const = 0;

    virtual void RetrieveInformation() = 0;

};

typedef std::list<IFileInfo*> FileInfoList;
