
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http ://www.apache.org/licenses/LICENSE-2.0
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

// Static function declarations
// //////////////////////////////////////////////////////////////////////////

static void FillArray(unsigned int* aArray, unsigned int aLength);

static void QuickSort (unsigned int* aArray, unsigned int aLength);
static void SimpleSort(unsigned int* aArray, unsigned int aLength);

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
    // TODO
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
