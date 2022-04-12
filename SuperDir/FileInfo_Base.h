
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/FileInfo_Base.h

#pragma once

// ===== SuperDir ===========================================================
#include "IFileInfo.h"

class FileInfo_Base : public IFileInfo
{

public:

    // ===== IFileInfo ======================================================
    virtual void Init(const char* aFolder, const char* aFile);
    virtual void DisplayInformation(unsigned int aIndent = 0) const;


protected:

    FileInfo_Base();

    bool IsFile(const char * aFile) const;

    bool IsRoot() const;

    void RetrieveFileName(char* aOut, unsigned int aOutSize_byte) const;

private:

    std::string mFile;
    std::string mFolder;

};
