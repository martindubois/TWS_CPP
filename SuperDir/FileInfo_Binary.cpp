
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/FileInfo_Binary.cpp

#include "Component.h"

// ===== C ==================================================================
#include <stdio.h>

// ===== System =============================================================
#include <sys/stat.h>

// ===== Windows ============================================================
#include <Windows.h>

// ===== SuperDir ===========================================================
#include "FileInfo_Binary.h"

// Constants
// //////////////////////////////////////////////////////////////////////////

#define UNIT_QTY (4)

const char * UNITS[UNIT_QTY] = { "o  ", "Kio", "Mio", "Gio" };

// Public
// //////////////////////////////////////////////////////////////////////////

// ===== IFileInfo ==========================================================

void FileInfo_Binary::DisplayInformation(unsigned int aIndent) const
{
    FileInfo_Base::DisplayInformation(aIndent);

    uint64_t     lSize = mSize_byte;
    unsigned int lUnit = 0;

    for ( ; lUnit < UNIT_QTY; lUnit++)
    {
        if (1024 > lSize)
        {
            break;
        }

        lSize /= 1024;
    }

    std::cout << std::setw(6) << lSize << " " << UNITS[lUnit];
}

void FileInfo_Binary::RetrieveInformation()
{
    char lFileName[1024];

    RetrieveFileName(lFileName, sizeof(lFileName));

    struct _stat lData;

    int lRet = _stat(lFileName, &lData);
    if (0 == lRet)
    {
        mSize_byte = lData.st_size;
    }
}

// Protected
// //////////////////////////////////////////////////////////////////////////

FileInfo_Binary::FileInfo_Binary() : mSize_byte(0)
{
}
