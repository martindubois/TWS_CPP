
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      MAIN0/MAIN0.cpp

// ===== C ==================================================================
#include <stdio.h>

// Entry point
// //////////////////////////////////////////////////////////////////////////

int main(int aCount, const char** aVector)
{
    if (1 >= aCount)
    {
        printf("S.V.P. passer votre prenom comme premier argument\n");
        return 1;
    }

    printf("Bonjour ");
    printf(aVector[1]);
    printf("\n");
    return 0;
}
