
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/FileInfo_H.h

#pragma once

// ===== SuperDir ===========================================================
#include "FileInfo_Text.h"

class FileInfo_H : public FileInfo_Text
{

public:

    // ===== IFileInfo ======================================================
    virtual void DisplayInformation() const;

};
