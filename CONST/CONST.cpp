
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CONST/CONST.cpp

// ===== C++ ================================================================
#include <iostream>

// ===== CONST ==============================================================
#include "ClassC.h"
#include "ClassD.h"

// Static function declarations
// //////////////////////////////////////////////////////////////////////////

static void Case0();
static void Case1();
static void Case2();

static void DisplayName_ByPtr(const ClassD* aIn);
static void DisplayName_ByRef(const ClassD& aIn);
static void DisplayName_ByVal(      ClassD  aIn);

// Entry point
// //////////////////////////////////////////////////////////////////////////

int main(int aCount, const char** aVector)
{
    if (2 > aCount)
    {
        std::cerr << "ERREUR UTILISATEUR  Passer le numero de cas en argument\n";
        return 1;
    }

    unsigned int lCase = strtoul(aVector[1], NULL, 10);

    switch (lCase)
    {
    case 0: Case0(); break;
    case 1: Case1(); break;
    case 2: Case2(); break;

    default:
        std::cerr << "ERREUR UTILISATEUR  Le numero de cas invalid\n";
        return 1;
    }

    return 0;
}

// Static functions
// //////////////////////////////////////////////////////////////////////////

void Case0()
{
    ClassC lC0("Martin");
    ClassC lC1(lC0);

    std::cout << "Nom 0 : " << lC0.GetName() << "\n";
    std::cout << "Nom 1 : " << lC1.GetName() << "\n";
}

void Case1()
{
    ClassD lD0("Martin");
    ClassD lD1(lD0);

    std::cout << "Nom 0 : " << lD0.GetName() << "\n";
    std::cout << "Nom 1 : " << lD1.GetName() << "\n";
}

void Case2()
{
    ClassD lD0("Martin");

    DisplayName_ByPtr(&lD0);
    DisplayName_ByRef( lD0);
    DisplayName_ByVal( lD0);
}

void DisplayName_ByPtr(const ClassD* aIn)
{
    std::cout << "Nom : " << aIn->GetName() << "\n";
}

void DisplayName_ByRef(const ClassD& aIn)
{
    std::cout << "Nom : " << aIn.GetName() << "\n";
}

void DisplayName_ByVal(ClassD  aIn)
{
    std::cout << "Nom : " << aIn.GetName() << "\n";
}
