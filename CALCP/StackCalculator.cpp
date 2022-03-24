
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CALCP/StackCalculator.cpp

// ===== CALCP ==============================================================
#include "StackCalculator.h"

// Public
// //////////////////////////////////////////////////////////////////////////

void StackCalculator::Clear()
{
    while (!mStack.empty())
    {
        mStack.pop();
    }
}

double StackCalculator::Add()
{
    double lB = PopValue();
    double lA = PopValue();

    double lResult = lA + lB;

    PushValue(lResult);

    return lResult;
}

double StackCalculator::Cosinus()
{
    double lA_rad = PopValue();

    double lResult = cos(lA_rad);

    PushValue(lResult);

    return lResult;
}

double StackCalculator::Divide()
{
    double lB = PopValue();
    double lA = PopValue();

    double lResult = lA / lB;

    PushValue(lResult);

    return lResult;
}

double StackCalculator::Modulus()
{
    double lB = PopValue();
    double lA = PopValue();

    double lResult = fmod(lA, lB);

    PushValue(lResult);

    return lResult;
}

double StackCalculator::Multiply()
{
    double lB = PopValue();
    double lA = PopValue();

    double lResult = lA * lB;

    PushValue(lResult);

    return lResult;
}

double StackCalculator::Sinus()
{
    double lA_rad = PopValue();

    double lResult = sin(lA_rad);

    PushValue(lResult);

    return lResult;
}

double StackCalculator::SquareRoot()
{
    double lA = PopValue();

    double lResult = sqrt(lA);

    PushValue(lResult);

    return lResult;
}

double StackCalculator::Substract()
{
    double lB = PopValue();
    double lA = PopValue();

    double lResult = lA - lB;

    PushValue(lResult);

    return lResult;
}

double StackCalculator::Tangent()
{
    double lA_rad = PopValue();

    double lResult = tan(lA_rad);

    PushValue(lResult);

    return lResult;
}

void StackCalculator::PushValue(double aValue)
{
    mStack.push(aValue);
}

// Private
// //////////////////////////////////////////////////////////////////////////

double StackCalculator::PopValue()
{
    double lResult = mStack.top();

    mStack.pop();

    return lResult;
}
