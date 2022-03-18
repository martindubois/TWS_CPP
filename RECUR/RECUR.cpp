
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      RECUR/RECUR.cpp

// CONFIG _ARRAY_LENGTH_
#define _ARRAY_LENGTH_ (10000)

// ===== C ==================================================================
#include <assert.h>

// ===== C++ ================================================================
#include <iostream>

// ===== Windows ============================================================
#include <Windows.h>

// Data type
// //////////////////////////////////////////////////////////////////////////

typedef struct
{
    unsigned int mLeft;
    unsigned int mRight;
}
SortInfo;

// Static function declarations
// //////////////////////////////////////////////////////////////////////////

static void FillArray(unsigned int* aArray, unsigned int aLength);

static void QuickSort (unsigned int* aArray, unsigned int aLength);
static void SimpleSort(unsigned int* aArray, unsigned int aLength);

static void QuickLoopSort (unsigned int* aArray, unsigned int aLength);
static void SimpleLoopSort(unsigned int* aArray, unsigned int aLength);

static unsigned int FindMin(const unsigned int* aArray, unsigned int aLength);

// Entry point
// //////////////////////////////////////////////////////////////////////////

int main(int aCount, const char** aVector)
{
    if (1 >= aCount)
    {
        std::cerr << "USER ERROR  The command line is not valid\n";
        return 1;
    }

    unsigned int lArray[_ARRAY_LENGTH_];

    FillArray(lArray, _ARRAY_LENGTH_);

    uint64_t lBegin_100ns;
    GetSystemTimePreciseAsFileTime(reinterpret_cast<FILETIME*>(&lBegin_100ns));

    if      (0 == _stricmp("Quick"     , aVector[1])) { QuickSort     (lArray, _ARRAY_LENGTH_); }
    else if (0 == _stricmp("QuickLoop" , aVector[1])) { QuickLoopSort (lArray, _ARRAY_LENGTH_); }
    else if (0 == _stricmp("Simple"    , aVector[1])) { SimpleSort    (lArray, _ARRAY_LENGTH_); }
    else if (0 == _stricmp("SimpleLoop", aVector[1])) { SimpleLoopSort(lArray, _ARRAY_LENGTH_); }

    uint64_t lEnd_100ns;
    GetSystemTimePreciseAsFileTime(reinterpret_cast<FILETIME*>(&lEnd_100ns));

    uint64_t lDiff_100ns = lEnd_100ns - lBegin_100ns;
    double lDiff_us = static_cast<double>(lDiff_100ns / 10);
    double lDiff_ms = lDiff_us / 1000;

    std::cout << "Execution time : " << lDiff_ms << " ms\n";

    return 0;
}

// Static functions
// //////////////////////////////////////////////////////////////////////////

void FillArray(unsigned int* aArray, unsigned int aLength)
{
    assert(NULL != aArray);
    assert(0 < aLength);

    srand(static_cast<unsigned int>(time(NULL)));

    for (unsigned int i = 0; i < aLength; i++)
    {
        aArray[i] = rand();
    }
}

void QuickSort(unsigned int* aArray, unsigned int aLength)
{
    if (1 < aLength)
    {
        unsigned int lPivot = aArray[aLength - 1];

        unsigned int lLeft = 0;
        unsigned int lRight = aLength - 1;

        while (lLeft < lRight)
        {
            while ((lLeft < lRight) && (lPivot > aArray[lLeft]))
            {
                lLeft++;
            }

            if (lLeft < lRight)
            {
                aArray[lRight] = aArray[lLeft];
                lRight--;
            }

            while ((lLeft < lRight) && (lPivot <= aArray[lRight]))
            {
                lRight--;
            }

            if (lLeft < lRight)
            {
                aArray[lLeft] = aArray[lRight];
                lLeft++;
            }
        }

        aArray[lLeft] = lPivot;

        QuickSort(aArray, lLeft);
        QuickSort(aArray + lLeft + 1, aLength - lLeft - 1);
    }
}

void SimpleSort(unsigned int* aArray, unsigned int aLength)
{
    if (1 < aLength)
    {
        unsigned int lIndex = FindMin(aArray, aLength);
        unsigned int lMin = aArray[lIndex];

        aArray[lIndex] = aArray[0];
        aArray[0] = lMin;

        SimpleSort(aArray + 1, aLength - 1);
    }
}

void QuickLoopSort(unsigned int* aArray, unsigned int aLength)
{
    // COMMENTAIRE PEDAGOGIC - Explication
    // Utiliser une std::list pour la variable lList causerait un grand
    // nombre d'allocation et de liberation de memoire qui dominerait
    // totalement le temps de calcul.
    //
    // L'utilisation d'un std::vecteur serait deja plus interessant et
    // n'obligerait pas a estimer la longueur necessaire comme c'est fait
    // plus bas.
    //
    // L'utilisation d'un tableau est optimal du point de vue temps de
    // calcule.
    //
    // Quand les nombres a trier sont initialise au hazard, comme c'est le
    // cas ici, il faut que la liste soit environ log en base 2 du nombre de
    // valeurs a trier (le log en base 2 de 1000 est entre 14 et 15). Une
    // list de 100 entree est donc suffisent.
    //
    // Cependant, si la liste serait deja trier ou trier en ordre inverse,
    // nous aurions alors le pire cas et il faudrait une liste qui contient
    // le meme nombre d'entrees que le nombre de valeurs a trier. Et dans ce
    // cas particulier, la performance du tri rapide serait tres mauvaise
    // autant en temps de calcul que pour la consommation de memoire.
    SortInfo lList[100];
    unsigned int lCount = 1;

    // Au debut, la liste contient l'information sur un seule ensemble de
    // valeurs a trier.
    lList[0].mLeft  = 0;
    lList[0].mRight = aLength - 1;

    // Nous continuous tant qu'il reste un ensemble de valeurs a trier.
    // Chaque iteration de la boucle principale traite un ensemble de valeurs
    // a trier et la retire de la liste. Cependant, chaque iteration ajoute
    // aussi deux sous ensembles de valeurs a trier a cette meme liste (sauf
    // quand la longueur des sous ensembles de valeurs est 0 ou 1).
    while (0 < lCount)
    {
        lCount--;

        SortInfo lInfo = lList[lCount];

        unsigned int lPivot = aArray[lInfo.mRight];

        unsigned int lLeft  = lInfo.mLeft;
        unsigned int lRight = lInfo.mRight;


        while (lLeft < lRight)
        {
            while ((lLeft < lRight) && (lPivot > aArray[lLeft]))
            {
                lLeft++;
            }

            if (lLeft < lRight)
            {
                aArray[lRight] = aArray[lLeft];
                lRight--;
            }

            while ((lLeft < lRight) && (lPivot <= aArray[lRight]))
            {
                lRight--;
            }

            if (lLeft < lRight)
            {
                aArray[lLeft] = aArray[lRight];
                lLeft++;
            }
        }

        aArray[lLeft] = lPivot;

        // Ici, puisque je desire utiliser une boucle plutot que la
        // recursivite, je ne peut pas rapeller la fonction de trie. Plutot,
        // j'ajoute les deux sous ensemble a trier dans la liste des trie a
        // effectuer. Naturellement, si la longueur du sous ensemble de
        // valeurs est de 0 ou 1, je ne l'ajoute pas.
        if (lInfo.mLeft + 1 < lLeft       ) { lList[lCount].mLeft = lInfo.mLeft; lList[lCount].mRight = lLeft - 1   ; lCount++; }
        if (lRight + 1      < lInfo.mRight) { lList[lCount].mLeft = lRight + 1 ; lList[lCount].mRight = lInfo.mRight; lCount++; }
    }
}

void SimpleLoopSort(unsigned int* aArray, unsigned int aLength)
{
    for (unsigned int i = 0; i < aLength - 1; i++)
    {
        unsigned int lIndex = FindMin(aArray + i, aLength - i) + i;
        unsigned int lMin = aArray[lIndex];

        aArray[lIndex] = aArray[i];
        aArray[i] = lMin;
    }
}

unsigned int FindMin(const unsigned int* aArray, unsigned int aLength)
{
    unsigned int lMin = aArray[0];
    unsigned int lResult = 0;

    for (unsigned int i = 1; i < aLength; i++)
    {
        if (lMin > aArray[i])
        {
            lMin = aArray[i];
            lResult = i;
        }
    }

    return lResult;
}
