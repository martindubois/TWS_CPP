
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      TEMPL/StackCalculator.h

#pragma once

// ===== C++ ================================================================
#include <stack>

template <class T>
class StackCalculator
{

public:

    // Vider la pile
    void Clear();

    // Retirer 2 valeurs de la pile, les additionner, placer le resultat sur
    // la pile et retourner le resultat pour l'affichage.
    T Add();

    // Retirer 1 valeur de la pile, calculer le cosinus de la valeur (en
    // radian), placer le resultat sur la pile et retourner le resultat pour
    // l'affichage.
    T Cosinus();

    // Retirer 2 valeur de la pile, diviser la 2e valeur retirer par 1e
    // valeur, placer le resultat sur la pile et retourner le resultat pour
    // l'affichage.
    T Divide();

    // Retirer 2 valeur de la pile, calculer le rest de le division de la 2e
    // valeur retirer par la 1e valeur, placer le resultat sur la pile et
    // retourner le resultat pour l'affichage.
    T Modulus();

    // Retirer 2 valeurs de la pile, les multiplier, placer le resultat sur
    // la pile et retourner le resultat pour l'affichage.
    T Multiply();

    // Retirer 1 valeur de la pile, calculer le sinus de la valeur (en
    // radian), placer le resultat sur la pile et retourner le resultat pour
    // l'affichage.
    T Sinus();

    // Retirer 1 valeur de la pile, calculer la racine carree de la valeur,
    // placer le resultat sur la pile et retourner le resultat pour
    // l'affichage.
    T SquareRoot();

    // Retirer 2 valeur de la pile, soustraire la 1e valeur de la 2e valeur,
    // placer le resultat sur la pile et retourner le resultat pour
    // l'affichage.
    T Substract();

    // Retirer 1 valeur de la pile, calculer la tengante de la valeur (en
    // radian), placer le resultat sur la pile et retourner le resultat pour
    // l'affichage.
    T Tangent();

    // Ajouter une valeur sur la pile.
    void PushValue(T aValue);

private:

    T PopValue();

    typedef std::stack<T> ValueStack;

    ValueStack mStack;

};

// Public
// //////////////////////////////////////////////////////////////////////////

template <class T>
void StackCalculator<T>::Clear()
{
    while (!mStack.empty())
    {
        mStack.pop();
    }
}

template <class T>
T StackCalculator<T>::Add()
{
    T lB = PopValue();
    T lA = PopValue();

    T lResult = lA + lB;

    PushValue(lResult);

    return lResult;
}

template <class T>
T StackCalculator<T>::Cosinus()
{
    T lA_rad = PopValue();

    T lResult = static_cast<T>(cos(lA_rad));

    PushValue(lResult);

    return lResult;
}

template <class T>
T StackCalculator<T>::Divide()
{
    T lB = PopValue();
    T lA = PopValue();

    T lResult = lA / lB;

    PushValue(lResult);

    return lResult;
}

template <class T>
T StackCalculator<T>::Modulus()
{
    T lB = PopValue();
    T lA = PopValue();

    T lResult = static_cast<T>(fmod(lA, lB));

    PushValue(lResult);

    return lResult;
}

template <class T>
T StackCalculator<T>::Multiply()
{
    T lB = PopValue();
    T lA = PopValue();

    T lResult = lA * lB;

    PushValue(lResult);

    return lResult;
}

template <class T>
T StackCalculator<T>::Sinus()
{
    T lA_rad = PopValue();

    T lResult = static_cast<T>(sin(lA_rad));

    PushValue(lResult);

    return lResult;
}

template <class T>
T StackCalculator<T>::SquareRoot()
{
    T lA = PopValue();

    T lResult = static_cast<T>(sqrt(lA));

    PushValue(lResult);

    return lResult;
}

template <class T>
T StackCalculator<T>::Substract()
{
    T lB = PopValue();
    T lA = PopValue();

    T lResult = lA - lB;

    PushValue(lResult);

    return lResult;
}

template <class T>
T StackCalculator<T>::Tangent()
{
    T lA_rad = PopValue();

    T lResult = static_cast<T>(tan(lA_rad));

    PushValue(lResult);

    return lResult;
}

template <class T>
void StackCalculator<T>::PushValue(T aValue)
{
    mStack.push(aValue);
}

// Private
// //////////////////////////////////////////////////////////////////////////

template <class T>
T StackCalculator<T>::PopValue()
{
    T lResult = mStack.top();

    mStack.pop();

    return lResult;
}
