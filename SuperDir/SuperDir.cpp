
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/SuperDir.cpp

#include "Component.h"

// ===== SuperDir ===========================================================
#include "Functions.h"

// Entry point
// //////////////////////////////////////////////////////////////////////////

int main(int aCount, const char** aVector)
{
    assert(1 <= aCount);
    assert(NULL != aVector);

    if (2 > aCount)
    {
        std::cerr << "ERREUR UTILISATEUR  Vous devez passer un nom de repertoire en argument\n";
        return 1;
    }

    IFileInfo** lFiles = FindFiles(aVector[1]);

    RetrieveInformation(lFiles);

    DisplayInformation(lFiles);

    ReleaseMemory(lFiles);

    return 0;
}
