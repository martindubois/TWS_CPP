
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/FileInfo_H.cpp

#include "Component.h"

// ===== SuperDir ===========================================================
#include "FileInfo_H.h"

// Public
// //////////////////////////////////////////////////////////////////////////

// ===== IFileInfo ==========================================================

void FileInfo_H::DisplayInformation(unsigned int aIndent) const
{
    FileInfo_Text::DisplayInformation(aIndent);

    std::cout << "  Langage C/C++ - Fichier entete\n";
}

