
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/FileInfo_Other.cpp

#include "Component.h"

// ===== SuperDir ===========================================================
#include "FileInfo_Other.h"

// Public
// //////////////////////////////////////////////////////////////////////////

// ===== IFileInfo ==========================================================

void FileInfo_Other::DisplayInformation() const
{
    FileInfo_Binary::DisplayInformation();

    std::cout << "\n";
}
