
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CONST/CONST.cpp

// CONFIG _USE_POINTER_
// CONFIG _USE_SSCANF_
// #define _USE_POINTER_
#define _USE_SSCANF_

// ===== C ==================================================================
#include <assert.h>
#include <stdio.h>

// ===== C++ ================================================================
#include <iostream>

// Entry point
// //////////////////////////////////////////////////////////////////////////

int main(int aCount, const char** aVector)
{
    if (2 > aCount)
    {
        std::cerr << "ERREUR UTILISATEUR  Vous devez passer un nom de fichier C/C++ en argument.\n";
        return 1;
    }

    FILE* lFile;

    int lRet = fopen_s(&lFile, aVector[1], "r");
    if (0 != lRet)
    {
        std::cerr << "ERREUR  Impossible d'ouvrir le fichier\n";
        return 2;
    }

    unsigned int lCommentCount = 0;
    unsigned int lEmptyCount = 0;
    unsigned int lLineCount = 0;
    unsigned int lPreprocessorCount = 0;

    char lLine[1024];

    while (NULL != fgets(lLine, sizeof(lLine), lFile))
    {
        lLineCount++;

        #ifdef _USE_POINTER_
            const char* lPtr = lLine;

            while ((' ' == *lPtr) || ('\t' == *lPtr))
            {
                lPtr++;
            }

            switch (*lPtr)
            {
            case '\0':
            case '\n':
            case '\r':
                lEmptyCount++; break;

            case '#': lPreprocessorCount++; break;

            case '/':
                if ('/' == lPtr[1])
                {
                    lCommentCount++;
                }
                break;
            }
        #endif

        #ifdef _USE_SSCANF_
            char lSubLine[1024];

            if      (1 == sscanf_s(lLine, " //%s"       , lSubLine, sizeof(lSubLine))) { lCommentCount++; }
            else if (1 == sscanf_s(lLine, " #%s"        , lSubLine, sizeof(lSubLine))) { lPreprocessorCount++; }
            else if (1 != sscanf_s(lLine, " %[^ \n\r\t]", lSubLine, sizeof(lSubLine))) { lEmptyCount++; }
        #endif
    }

    std::cout << lLineCount << " lignes\n";
    std::cout << lEmptyCount << " lignes vide\n";
    std::cout << lCommentCount << " lignes de commentaire\n";
    std::cout << lPreprocessorCount << " lignes de commande au preprocesseur\n";

    lRet = fclose(lFile);
    assert(0 == lRet);

    return 0;
}
