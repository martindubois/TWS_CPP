
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/FileInfo_Folder.cpp

#include "Component.h"

// ===== Windows ============================================================
#include <Windows.h>

// ===== SuperDir ===========================================================
#include "FileInfo_CPP.h"
#include "FileInfo_EXE.h"
#include "FileInfo_H.h"
#include "FileInfo_Other.h"
#include "ThreadList.h"

#include "FileInfo_Folder.h"

// Static function declarations
// //////////////////////////////////////////////////////////////////////////

static IFileInfo* CreateFileInfo(const WIN32_FIND_DATA& aData);

static DWORD WINAPI RetrieveInformation_Link(LPVOID aParam);

// Public
// //////////////////////////////////////////////////////////////////////////

// ===== IFileInfo ==========================================================

FileInfo_Folder::~FileInfo_Folder()
{
    for (IFileInfo* lFile : mFiles)
    {
        assert(NULL != lFile);

        delete lFile;
    }
}

void FileInfo_Folder::DisplayInformation(unsigned int aIndent) const
{
    FileInfo_Base::DisplayInformation(aIndent);

    std::cout << "Dossier\n";

    // COMMENTAIRE PEDAGOGIQUE
    // Pour simplifier le code de la boucle, j'effectue l'addition avant
    // celle-ci.
    unsigned int lIndent = aIndent + 4;

    for (IFileInfo* lFile : mFiles)
    {
        assert(NULL != lFile);

        lFile->DisplayInformation(lIndent);
    }
}

void FileInfo_Folder::RetrieveInformation()
{
    // COMMENTAIRE PEDAGOGIQUE
    // Pour voir les . et les .. dans la sortie de SuperDir, je cree les
    // instances de FileInfo_Folder pour ceux-ci mais je n'effectue pas la
    // recherche dans ceux-ci.
    if (IsFile(".") || IsFile(".."))
    {
        return;
    }

    char lPath[1024];

    RetrieveFileName(lPath, sizeof(lPath));

    char lPattern[1024];

    sprintf_s(lPattern, "%s\\*", lPath);

    WIN32_FIND_DATA lData;

    HANDLE lHandle = FindFirstFile(lPattern, &lData);
    if (INVALID_HANDLE_VALUE != lHandle)
    {
        do
        {
            IFileInfo* lInfo = CreateFileInfo(lData);
            assert(NULL != lInfo);

            lInfo->Init(lPath, lData.cFileName);

            mFiles.push_back(lInfo);
        }
        while (FindNextFile(lHandle, &lData));

        BOOL lRet = FindClose(lHandle);
        assert(lRet);
    }

    // COMMENTAIRE PEDAGOGIQUE
    // La methode RetrieveInformation etait un peu longue, j'ai donc deplace
    // l'appel de la methode RetrieveInformation des enfants dans une autre
    // methode.
    CallRetrieveInformations();
}

// Private
// //////////////////////////////////////////////////////////////////////////

void FileInfo_Folder::CallRetrieveInformations()
{
    bool lRoot = IsRoot();

    ThreadList lThreads;

    for (IFileInfo* lFile : mFiles)
    {
        assert(NULL != lFile);

        FileInfo_Folder* lFolder = dynamic_cast<FileInfo_Folder*>(lFile);
        if ((NULL != lFolder) && lRoot)
        {
            HANDLE lThread = CreateThread(NULL, 0, RetrieveInformation_Link, lFile, 0, NULL);
            assert(NULL != lThread);

            lThreads.push_back(lThread);
        }
        else
        {
            lFile->RetrieveInformation();
        }
    }

    lThreads.WaitAndClose();
}

// Static functions
// //////////////////////////////////////////////////////////////////////////

IFileInfo* CreateFileInfo(const WIN32_FIND_DATA& aData)
{
    size_t lLen = strlen(aData.cFileName);
    assert(0 < lLen);

    IFileInfo* lResult;

    if (0 != (aData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
    {
        lResult = new FileInfo_Folder;
    }
    else if (0 == _stricmp(".cpp", aData.cFileName + lLen - 4)) { lResult = new FileInfo_CPP; }
    else if (0 == _stricmp(".exe", aData.cFileName + lLen - 4)) { lResult = new FileInfo_EXE; }
    else if (0 == _stricmp(".h"  , aData.cFileName + lLen - 2)) { lResult = new FileInfo_H  ; }
    else
    {
        lResult = new FileInfo_Other;
    }

    assert(NULL != lResult);

    return lResult;
}

DWORD WINAPI RetrieveInformation_Link(LPVOID aParam)
{
    assert(NULL != aParam);
    
    FileInfo_Folder* lThis = reinterpret_cast<FileInfo_Folder*>(aParam);

    lThis->RetrieveInformation();

    return 0;
}
