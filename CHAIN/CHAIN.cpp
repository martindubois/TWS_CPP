
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CHAIN/CHAIN.cpp

// ===== C ==================================================================
#include <assert.h>
#include <stdio.h>
#include <string.h>

// Static function declarations
// //////////////////////////////////////////////////////////////////////////

static unsigned int FindLetter(const char* aWord, unsigned int aLen, char* aCurrent, char aLetter);

static void VerifyResponse(const char* aWord, const char* aResponse);

// Entry point
// //////////////////////////////////////////////////////////////////////////

int main(int aCount, const char** aVector)
{
    assert(1 <= aCount);
    assert(NULL != aVector);

    if (2 > aCount)
    {
        fprintf(stderr, "ERREUR UTILISATEUR  Le mot a trouver doit etre passee en argument\n");
        return 1;
    }

    assert(NULL != aVector[1]);

    const char * lWord = aVector[1];

    unsigned int lLen = strlen(lWord);

    char* lCurrent = new char[lLen + 1];

    memset(lCurrent, '-', lLen);

    lCurrent[lLen] = '\0';

    unsigned int lErrCount = 0;
    unsigned int lFound = 0;

    int lResult = 0;

    for (;;)
    {
        printf("%u erreur, %u lettres trouvees sur %u\n", lErrCount, lFound, lLen);
        printf("%s\n", lCurrent);
        printf("Entrer une lettre ou le mot\n");

        char lResponse[1024];

        if (NULL == gets_s(lResponse))
        {
            fprintf(stderr, "ERREUR  Impossible de lire la reponse\n");
            lResult = 2;
            break;
        }

        unsigned int lRetLen = strlen(lResponse);
        if (lLen == lRetLen)
        {
            VerifyResponse(lWord, lResponse);
            break;
        }

        if (1 == lRetLen)
        {
            unsigned int lRet = FindLetter(lWord, lLen, lCurrent, lResponse[0]);
            if (0 == lRet)
            {
                printf("Le mot ne contient pas cette lettre\n");
                lErrCount++;
                if (6 <= lErrCount)
                {
                    printf("Vous avez atteint le nombre maximum d'erreur\n");
                    break;
                }
            }
            else
            {
                printf("Le mot contient cette lettre\n");
                lFound += lRet;
                if (lLen <= lFound)
                {
                    printf("Vous avez trouve toutes les lettres\n");
                    break;
                }
            }
        }
        else
        {
            fprintf(stderr, "ERREUR UTILISATEUR  La reponse n'est pas valide");
        }
    }

    delete[] lCurrent;

    return lResult;
}

// Static functions
// //////////////////////////////////////////////////////////////////////////

unsigned int FindLetter(const char* aWord, unsigned int aLen, char* aCurrent, char aLetter)
{
    assert(NULL != aWord);
    assert(0 < aLen);
    assert(NULL != aCurrent);

    unsigned int lResult = 0;

    for (unsigned int i = 0; i < aLen; i++)
    {
        if (aWord[i] == aLetter)
        {
            if (aCurrent[i] == aLetter)
            {
                return 0;
            }

            aCurrent[i] = aLetter;
            lResult++;
        }
    }

    return lResult;
}

void VerifyResponse(const char* aWord, const char* aResponse)
{
    assert(NULL != aWord);
    assert(NULL != aResponse);

    if (0 == _stricmp(aWord, aResponse))
    {
        printf("Felicitation!\n");
    }
    else
    {
        printf("Ce n'est pas le mot cherche!\n");
    }
}
