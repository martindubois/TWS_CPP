
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/FileInfo_Base.cpp

#include "Component.h"

// ===== C ==================================================================
#include <string.h>

// ===== SuperDir ===========================================================
#include "FileInfo_Base.h"

// Public
// //////////////////////////////////////////////////////////////////////////

// ===== IFileInfo ==========================================================

void FileInfo_Base::Init(const char* aFolder, const char* aFile)
{
    assert(NULL != aFolder);
    assert(NULL != aFile);

    strncpy_s(mFile  , aFile  , sizeof(mFile  ) - 1);
    strncpy_s(mFolder, aFolder, sizeof(mFolder) - 1);
}

void FileInfo_Base::DisplayInformation() const
{
    size_t lLen = strlen(mFile);

    std::cout << mFile;

    if (30 > lLen)
    {
        std::cout << "                              " + lLen;
    }
}

// Protected
// //////////////////////////////////////////////////////////////////////////

FileInfo_Base::FileInfo_Base()
{
    memset(&mFile  , 0, sizeof(mFile  ));
    memset(&mFolder, 0, sizeof(mFolder));
}

void FileInfo_Base::RetrieveFileName(char* aOut, unsigned int aOutSize_byte) const
{
    assert(NULL != aOut);
    assert(0 < aOutSize_byte);

    sprintf_s(aOut, aOutSize_byte, "%s\\%s", mFolder, mFile);
}
