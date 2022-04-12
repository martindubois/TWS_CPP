
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/FileInfo_Text.cpp

#include "Component.h"

// ===== C ==================================================================
#include <stdio.h>

// ===== SuperDir ===========================================================
#include "FileInfo_Text.h"

// Public
// //////////////////////////////////////////////////////////////////////////

// ===== IFileInfo ==========================================================

void FileInfo_Text::DisplayInformation(unsigned int aIndent) const
{
    FileInfo_Base::DisplayInformation(aIndent);

    std::cout << std::setw(6) << mLineCount << " lignes";
}

void FileInfo_Text::RetrieveInformation()
{
    char lFileName[512];

    RetrieveFileName(lFileName, sizeof(lFileName));

    FILE* lFile;

    int lRet = fopen_s(&lFile, lFileName, "r");
    if (0 == lRet)
    {
        char lLine[1024];

        while (NULL != fgets(lLine, sizeof(lLine), lFile))
        {
            mLineCount++;
        }

        lRet = fclose(lFile);
        assert(0 == lRet);
    }
}

// Protected
// //////////////////////////////////////////////////////////////////////////

FileInfo_Text::FileInfo_Text() : mLineCount(0)
{
}
