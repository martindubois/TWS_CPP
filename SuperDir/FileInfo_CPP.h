
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/FileInfo_CPP.h

#pragma once

// ===== SuperDir ===========================================================
#include "FileInfo_Text.h"

class FileInfo_CPP : public FileInfo_Text
{

public:

    // ===== IFileInfo ======================================================
    virtual void DisplayInformation(unsigned int aIndent = 0) const;

};
