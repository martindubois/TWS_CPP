
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/FileInfo_CPP.cpp

#include "Component.h"

// ===== SuperDir ===========================================================
#include "FileInfo_CPP.h"

// Public
// //////////////////////////////////////////////////////////////////////////

// ===== IFileInfo ==========================================================

void FileInfo_CPP::DisplayInformation(unsigned int aIndent) const
{
    FileInfo_Text::DisplayInformation(aIndent);

    std::cout << "  Langage C++ - Fichier source\n";
}
