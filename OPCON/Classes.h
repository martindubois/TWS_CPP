
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      OPCON/Classes.h

#pragma once

// ===== C++ ================================================================
#include <string>

class ClassA
{

public:

    ClassA(const char* aName);

    virtual void Display() const;

private:

    std::string mName;

};

class ClassB : public ClassA
{

public:

    ClassB(const char* aName, unsigned int aAge);

    virtual void DisplayAge() const;

    // ===== Class A ========================================================
    virtual void Display() const;

private:

    unsigned int mAge;

};

class ClassC : public ClassA
{

public:

    ClassC(const char* aName, const char* aColor);

    virtual void DoNotCall() const;

    virtual void DisplayColor() const;

    // ===== Class A ========================================================
    virtual void Display() const;

private:

    std::string mColor;

};

class ClassD
{

public:

    ClassD(const char* aSecret);

    virtual void DoNotCall() const;

    virtual void DisplaySecret() const;

private:

    std::string mSecret;

};
