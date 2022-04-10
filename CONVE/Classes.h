
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CONVE/Classes.cpp

#pragma once

// ===== C++ ================================================================
#include <iostream>

class ClassA
{

public:
    virtual void Display() { std::cout << "ClassA\n"; }

};

class ClassB : public ClassA
{

public:
    virtual void Display() { std::cout << "ClassB\n"; }

};

class ClassC : public ClassA
{

public:
    virtual void Display() { std::cout << "ClassC\n"; }

};

class ClassD
{

public:
    virtual void Display() { std::cout << "ClassA\n"; }

};
