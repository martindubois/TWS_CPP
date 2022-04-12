
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/FileInfo_Folder.h

#pragma once

// ===== SuperDir ===========================================================
#include "FileInfo_Base.h"

class FileInfo_Folder : public FileInfo_Base
{

public:

    // ===== IFileInfo ======================================================

    virtual ~FileInfo_Folder();

    virtual void DisplayInformation (unsigned int aIndent = 0) const;
    virtual void RetrieveInformation();

private:

    void CallRetrieveInformations();

    FileInfoList mFiles;

};
