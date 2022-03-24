
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CALCP/CALCP.cpp

// ===== C ==================================================================
#include <stdio.h>
#include <string.h>

// ===== C++ ================================================================
#include <iostream>

// ===== CALCP ==============================================================
#include "StackCalculator.h"


// Static function declarations
// //////////////////////////////////////////////////////////////////////////

static void DisplayHelp();
static void DisplayValue(double aValue);

// Entry point
// //////////////////////////////////////////////////////////////////////////

int main()
{
    StackCalculator lSC;

    for (;;)
    {
        std::cout << "> ";

        char lLine[1024];

        if (NULL == fgets(lLine, sizeof(lLine), stdin)) { break; }

        if (0 == _stricmp("exit\n", lLine)) { break; }

        try
        {
            if      (0 == _stricmp("help\n", lLine)) { DisplayHelp(); }
            else if (0 == _stricmp("?\n"   , lLine)) { DisplayHelp(); }
            else if (0 == _stricmp("clear\n", lLine)) { lSC.Clear(); }
            else if (0 == _stricmp("cos\n" , lLine)) { DisplayValue(lSC.Cosinus()); }
            else if (0 == _stricmp("sin\n" , lLine)) { DisplayValue(lSC.Sinus()); }
            else if (0 == _stricmp("sqrt\n", lLine)) { DisplayValue(lSC.SquareRoot()); }
            else if (0 == _stricmp("tan\n" , lLine)) { DisplayValue(lSC.Tangent()); }
            else if (0 == _stricmp("+\n"   , lLine)) { DisplayValue(lSC.Add()); }
            else if (0 == _stricmp("-\n"   , lLine)) { DisplayValue(lSC.Substract()); }
            else if (0 == _stricmp("*\n"   , lLine)) { DisplayValue(lSC.Multiply()); }
            else if (0 == _stricmp("/\n"   , lLine)) { DisplayValue(lSC.Divide()); }
            else if (0 == _stricmp("%\n"   , lLine)) { DisplayValue(lSC.Modulus()); }
            else { lSC.PushValue(strtod(lLine, NULL)); }
        }
        catch (std::exception eE)
        {
            std::cerr << "EXCEPTION  " << eE.what() << "\n";
        }
    }

    return 0;
}

// Static functions
// //////////////////////////////////////////////////////////////////////////

void DisplayHelp()
{
    std::cout << "clear  Clear\n";
    std::cout << "cos    Cosinus\n";
    std::cout << "exit   Terminate execution\n";
    std::cout << "help   Display this help\n";
    std::cout << "sin    Sinus\n";
    std::cout << "sqrt   Square root\n";
    std::cout << "tan    Tangent\n";
    std::cout << "?      Display this help\n";
    std::cout << "+      Add\n";
    std::cout << "-      Substract\n";
    std::cout << "*      Multiply\n";
    std::cout << "/      Divide\n";
    std::cout << "%      Modulo\n";
}

void DisplayValue(double aValue)
{
    std::cout << aValue << "\n";
}
