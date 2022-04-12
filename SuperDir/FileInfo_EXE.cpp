
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

void FileInfo_EXE::DisplayInformation(unsigned int aIndent) const
{
    FileInfo_Binary::DisplayInformation(aIndent);

    std::cout << "  Executable\n";
}
