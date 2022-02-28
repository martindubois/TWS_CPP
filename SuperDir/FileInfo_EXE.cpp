
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/FileInfo_EXE.cpp

#include "Component.h"

// ===== SuperDir ===========================================================
#include "FileInfo_EXE.h"

// Public
// //////////////////////////////////////////////////////////////////////////

// ===== IFileInfo ==========================================================

void FileInfo_EXE::DisplayInformation() const
{
    FileInfo_Binary::DisplayInformation();

    std::cout << "  Executable\n";
}
