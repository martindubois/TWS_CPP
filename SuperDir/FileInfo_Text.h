
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/FileInfo_Text.h

#pragma once

// ===== SuperDir ===========================================================
#include "FileInfo_Base.h"

class FileInfo_Text : public FileInfo_Base
{

public:

    // ===== IFileInfo ======================================================
    virtual void DisplayInformation () const;
    virtual void RetrieveInformation();

protected:

    FileInfo_Text();

private:

    unsigned int mLineCount;

};
