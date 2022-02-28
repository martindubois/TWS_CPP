
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/Functions.cpp

#include "Component.h"

// ===== C ==================================================================
#include <memory.h>
#include <stdio.h>

// ===== Windows ============================================================
#include <Windows.h>

// ===== SuperDir ===========================================================
#include "FileInfo_CPP.h"
#include "FileInfo_EXE.h"
#include "FileInfo_H.h"
#include "FileInfo_Other.h"

#include "Functions.h"

// Constants
// //////////////////////////////////////////////////////////////////////////

#define FILE_COUNT_MAX (100)

// Static function declarations
// //////////////////////////////////////////////////////////////////////////

static IFileInfo* CreateFileInfo(const WIN32_FIND_DATA & aData);

// Functions
// //////////////////////////////////////////////////////////////////////////

IFileInfo** FindFiles(const char* aFolder)
{
    assert(NULL != aFolder);

    IFileInfo** lResult = new IFileInfo * [FILE_COUNT_MAX];

    memset(lResult, 0, sizeof(IFileInfo*) * FILE_COUNT_MAX);

    char lPattern[1024];

    sprintf_s(lPattern, "%s\\*", aFolder);

    WIN32_FIND_DATA lData;

    HANDLE lHandle = FindFirstFile(lPattern, &lData);
    if (INVALID_HANDLE_VALUE != lHandle)
    {
        unsigned int lCount = 0;

        do
        {
            if (0 == (lData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
            {
                lResult[lCount] = CreateFileInfo(lData);
                assert(NULL != lResult[lCount]);

                lResult[lCount]->Init(aFolder, lData.cFileName);

                lCount++;
                if (FILE_COUNT_MAX <= lCount)
                {
                    break;
                }
            }
        }
        while (FindNextFile(lHandle, &lData));

        BOOL lRet = FindClose(lHandle);
        assert(lRet);
    }

    return lResult;
}

void DisplayInformation(IFileInfo** aFiles)
{
    assert(NULL != aFiles);

    for (unsigned int i = 0; i < FILE_COUNT_MAX; i++)
    {
        if (NULL == aFiles[i])
        {
            break;
        }

        aFiles[i]->DisplayInformation();
    }
}

void ReleaseMemory(IFileInfo** aFiles)
{
    assert(NULL != aFiles);

    for (unsigned int i = 0; i < FILE_COUNT_MAX; i++)
    {
        if (NULL == aFiles[i])
        {
            break;
        }

        delete aFiles[i];
    }

    delete[] aFiles;
}

void RetrieveInformation(IFileInfo** aFiles)
{
    assert(NULL != aFiles);

    for (unsigned int i = 0; i < FILE_COUNT_MAX; i++)
    {
        if (NULL == aFiles[i])
        {
            break;
        }

        aFiles[i]->RetrieveInformation();
    }
}

// Static functions
// //////////////////////////////////////////////////////////////////////////

IFileInfo* CreateFileInfo(const WIN32_FIND_DATA& aData)
{
    size_t lLen = strlen(aData.cFileName);

    IFileInfo* lResult;

    if      (0 == _stricmp(".cpp", aData.cFileName + lLen - 4)) { lResult = new FileInfo_CPP; }
    else if (0 == _stricmp(".exe", aData.cFileName + lLen - 4)) { lResult = new FileInfo_EXE; }
    else if (0 == _stricmp(".h"  , aData.cFileName + lLen - 2)) { lResult = new FileInfo_H  ; }
    else
    {
        lResult = new FileInfo_Other;
    }

    assert(NULL != lResult);

    return lResult;
}
