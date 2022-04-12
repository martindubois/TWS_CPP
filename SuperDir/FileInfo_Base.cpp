
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

    mFile   = aFile;
    mFolder = aFolder;
}

void FileInfo_Base::DisplayInformation(unsigned int aIndent) const
{
    for (unsigned int i = 0; i < aIndent; i++)
    {
        std::cout << " ";
    }

    size_t lLen = mFile.length();
    assert(0 < lLen);

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
}

// COMMENTAIRE PEDAGOGIQUE
// Plutot que de rendre mFile accessible au classes derivees, j'ai prefere
// definir une fonction qui permettait de comparer la valeur.
bool FileInfo_Base::IsFile(const char* aFile) const
{
    assert(NULL != aFile);

    return 0 == strcmp(mFile.c_str(), aFile);
}

// COMMENTAIRE PEDAGOGIQUE
// Plutot que de rendre mFolder accessible au classes derivees, j'ai prefere
// definir une fonction qui permet de verifier si mFolder est vide.
bool FileInfo_Base::IsRoot() const
{
    return 0 == mFolder.length();
}

void FileInfo_Base::RetrieveFileName(char* aOut, unsigned int aOutSize_byte) const
{
    assert(NULL != aOut);
    assert(0 < aOutSize_byte);

    // COMMENTAIRE PEDAGOGIQUE
    // mFolder peut etre vide dans le cas du repertoire racine. Cette methode
    // doit en tenir compte. Nous voyons ici l'important d'avoir place ce
    // code dans une methode de la classe de base plutot que dans chacune des
    // classes derivees.
    if (0 == mFolder.length())
    {
        sprintf_s(aOut, aOutSize_byte, "%s", mFile.c_str());
    }
    else
    {
        sprintf_s(aOut, aOutSize_byte, "%s\\%s", mFolder.c_str(), mFile.c_str());
    }
}
