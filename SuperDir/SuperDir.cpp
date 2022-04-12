
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/SuperDir.cpp

#include "Component.h"

// ===== Windows ============================================================
#include <Windows.h>

// ===== SuperDir ===========================================================
#include "FileInfo_Folder.h"

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

    uint64_t lBegin;

    GetSystemTimePreciseAsFileTime(reinterpret_cast<FILETIME*>(&lBegin));

    FileInfo_Folder lRoot;

    lRoot.Init("", aVector[1]);

    lRoot.RetrieveInformation();

    uint64_t lEnd;

    GetSystemTimePreciseAsFileTime(reinterpret_cast<FILETIME*>(&lEnd));

    uint64_t lDuration_100ns = lEnd - lBegin;
    double lDuration_us = static_cast<double>(lDuration_100ns / 10);
    double lDuration_ms = lDuration_us / 1000;
    double lDuration_s = lDuration_ms / 1000;

    printf("Execution en %f s\n", lDuration_s);

    lRoot.DisplayInformation();

    return 0;
}
