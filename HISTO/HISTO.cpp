
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      HISTO/HISTO.cpp

// ===== C ==================================================================
#include <assert.h>

// ===== C++ ================================================================
#include <iostream>

// Entry point
// //////////////////////////////////////////////////////////////////////////

int main(int aCount, const char** aVector)
{
    assert(1 <= aCount);
    assert(NULL != aVector);

    if (2 > aCount)
    {
        std::cerr << "USER ERROR  You must pass the file name as first argument\n";
        return 1;
    }

    FILE* lFile;

    int lRet = fopen_s(&lFile, aVector[1], "rb");
    if (0 != lRet)
    {
        std::cerr << "ERROR  Cannot open the file\n";
        return 2;
    }

    unsigned int lCount = 0;
    unsigned int lHisto[256];

    memset(&lHisto, 0, sizeof(lHisto));

    uint8_t lByte;

    while (1 == fread(&lByte, sizeof(uint8_t), 1, lFile))
    {
        lCount++;
        lHisto[lByte]++;
    }

    std::cout << lCount << " bytes\n\n";

    std::cout << "Value Count Ratio\n";
    std::cout << "===== ===== =====\n";

    uint8_t      lMax_Byte;
    unsigned int lMax_Value = 0xffffffff;
    uint8_t      lMin_Byte;
    unsigned int lMin_Value = 0;
    double       lPC;

    for (unsigned int i = 0; i < 0xff; i++)
    {
        if (lMax_Value > lHisto[i])
        {
            lMax_Byte = i;
            lMax_Value = lHisto[i];
        }

        if (lMin_Value < lHisto[i])
        {
            lMin_Byte = i;
            lMin_Value = lHisto[i];
        }

        lPC = lHisto[i];

        lPC /= lCount;
        lPC *= 100;

        printf("   %02x %5u %f %%\n", i, lHisto[i], lPC);
    }

    lPC = lHisto[lMin_Byte];
    lPC /= lCount;
    lPC *= 100;
    printf("Minimum %02x %5u %f %%\n", lMin_Byte, lMin_Value, lPC);

    lPC = lHisto[lMax_Byte];
    lPC /= lCount;
    lPC *= 100;
    printf("Maximum %02x %5u %f %%\n", lMax_Byte, lMax_Value, lPC);

    lRet = fclose(lFile);
    assert(0 == lRet);
}
