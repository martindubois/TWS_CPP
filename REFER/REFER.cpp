
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      REFER/REFER.cpp

// ===== C ==================================================================
#include <stdio.h>
#include <stdlib.h>

// Static function declarations
// //////////////////////////////////////////////////////////////////////////

// QUESTION (Decouverte) A quoi sert le mot cle "static" place au debut des
//          declaration de fonctions ?
static bool DivideP(int aA, int aB, int* aOut);
static bool DivideR(int aA, int aB, int& aOut);

// Entry point
// //////////////////////////////////////////////////////////////////////////

int main(int aCount, const char** aVector)
{
    if (2 >= aCount)
    {
        // QUESTION (Revision) Que signifie "stderr" ?
        fprintf(stderr, "ERREUR UTILISATEUR  REFER.exe doit recevoir deux nombres en argument.\n");

        // QUESTION (Revision) Pourquoi retourner 1 ?
        return 1;
    }

    // QUESTION (Decouverte) Dans quel fichier entete la fonction "atoi"
    //          est-elle declare ?

    // QUESTION Que fais la fonction "atoi" ? Pourquoi s'appelle-t-elle
    //          ainsi ?

    int lA = atoi(aVector[1]);
    int lB = atoi(aVector[2]);

    int lResultDiv;
    bool lRet;

    // lRet = DivideP(lA, lB, &lResultDiv);
    lRet = DivideR(lA, lB, lResultDiv);

    if (!lRet)
    {
        fprintf(stderr, "ERREUR UTILISATEUR  La division est impossible.\n");
        return 2;
    }

    printf("Le resultat de la division est %d\n", lResultDiv);

    return 0;
}

// Static functions
// //////////////////////////////////////////////////////////////////////////

// QUESTION Que se passerait-il si la cette fonction etait appelee avec la
//          valeur NULL comme 3ieme argument ?
bool DivideP(int aA, int aB, int* aOut)
{
    if (0 == aB)
    {
        return false;
    }

    *aOut = aA / aB;
    return true;
}

bool DivideR(int aA, int aB, int& aOut)
{
    if (0 == aB)
    {
        return false;
    }

    aOut = aA / aB;
    return true;
}
