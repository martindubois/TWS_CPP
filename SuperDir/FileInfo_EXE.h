
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/FileInfo_EXE.h

#pragma once

// ===== SuperDir ===========================================================
#include "FileInfo_Binary.h"

class FileInfo_EXE : public FileInfo_Binary
{

public:

    // ===== IFileInfo ======================================================
    virtual void DisplayInformation(unsigned int aIndent = 0) const;

};
