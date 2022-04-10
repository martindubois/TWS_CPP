
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      OPCON/Classes.cpp

// ===== C++ ================================================================
#include <iostream>

// ===== OPCON ==============================================================
#include "Classes.h"

// Public
// //////////////////////////////////////////////////////////////////////////

ClassA::ClassA(const char* aName) : mName(aName)
{
}

void ClassA::Display() const
{
    std::cout << "  (ClassA::Display) My name is " << mName << "\n";
}

ClassB::ClassB(const char* aName, unsigned int aAge) : ClassA(aName), mAge(aAge)
{
}

void ClassB::DisplayAge() const
{
    std::cout << "  (ClassB::DisplayAge) I am " << mAge << " years old\n";
}

void ClassB::Display() const
{
    std::cout << "  (ClassB::Display)\n";

    ClassA::Display();

    DisplayAge();
}

ClassC::ClassC(const char* aName, const char* aColor) : ClassA(aName), mColor(aColor)
{
}

void ClassC::DoNotCall() const
{
    std::cout << "  (ClassC::DoNotCall)\n";
}

void ClassC::DisplayColor() const
{
    std::cout << "  (ClassC::DisplayColor) My color is " << mColor << "\n";
}

void ClassC::Display() const
{
    std::cout << "  (ClassC::Display)\n";

    ClassA::Display();

    DisplayColor();
}

ClassD::ClassD(const char* aSecret) : mSecret(aSecret)
{
}

void ClassD::DoNotCall() const
{
    std::cout << "  (ClassD::DoNotCall)\n";
}

void ClassD::DisplaySecret() const
{
    std::cout << "  (ClassD::DisplaySecret) My secret is " << mSecret << "\n";
}
