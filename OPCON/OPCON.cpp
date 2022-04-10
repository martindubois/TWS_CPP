
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      OPCON/OPCON.cpp

// ===== C++ ================================================================
#include <iostream>

// ===== OPCON ==============================================================
#include "Classes.h"

int main()
{
    ClassA* lA = new ClassB("Alice", 21);
    ClassA* lB = new ClassC("Bob", "Brown");
    ClassC* lC = new ClassC("Charlie", "Black");
    ClassD* lD = new ClassD("My secret");

    ClassB* lE = dynamic_cast<ClassB*>(lA);
    ClassB* lF = dynamic_cast<ClassB*>(lB);

    ClassA* lG = dynamic_cast<ClassA*>(lC);
    ClassA* lH = dynamic_cast<ClassA*>(lD);

    ClassA* lI = static_cast<ClassA*>(lC);

    ClassA* lJ = reinterpret_cast<ClassA*>(lD);

    ClassA* lK = lC;

    ClassB* lL = reinterpret_cast<ClassB*>(lC);

    ClassB* lM = (ClassB*)(lC);

    std::cout << " 1.\n"; lA->Display();
    std::cout << " 2.\n"; lB->Display();
    std::cout << " 3.\n"; lC->Display(); lC->DisplayColor();
    std::cout << " 4.\n"; lD->DisplaySecret();

    if (NULL != lE) { std::cout << " 5.\n"; lE->Display(); lE->DisplayAge(); }
    if (NULL != lF) { std::cout << " 6.\n"; lF->Display(); lF->DisplayAge(); }
    if (NULL != lG) { std::cout << " 7.\n"; lG->Display(); }
    if (NULL != lH) { std::cout << " 8.\n"; lH->Display(); }

    std::cout << " 9.\n"; lI->Display();
    std::cout << "10.\n"; lJ->Display();
    std::cout << "11.\n"; lK->Display();
    std::cout << "12.\n"; lL->Display(); lL->DisplayAge();
    std::cout << "13.\n"; lM->Display(); lM->DisplayAge();

    delete lA;
    delete lB;
    delete lC;
    delete lD;
}
