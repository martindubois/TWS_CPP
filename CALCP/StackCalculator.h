
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CALCP/StackCalculator.h

#pragma once

// ===== C++ ================================================================
#include <stack>

class StackCalculator
{

public:

    // Vider la pile
    void Clear();

    // Retirer 2 valeurs de la pile, les additionner, placer le resultat sur
    // la pile et retourner le resultat pour l'affichage.
    double Add();

    // Retirer 1 valeur de la pile, calculer le cosinus de la valeur (en
    // radian), placer le resultat sur la pile et retourner le resultat pour
    // l'affichage.
    double Cosinus();

    // Retirer 2 valeur de la pile, diviser la 2e valeur retirer par 1e
    // valeur, placer le resultat sur la pile et retourner le resultat pour
    // l'affichage.
    double Divide();

    // Retirer 2 valeur de la pile, calculer le rest de le division de la 2e
    // valeur retirer par la 1e valeur, placer le resultat sur la pile et
    // retourner le resultat pour l'affichage.
    double Modulus();

    // Retirer 2 valeurs de la pile, les multiplier, placer le resultat sur
    // la pile et retourner le resultat pour l'affichage.
    double Multiply();

    // Retirer 1 valeur de la pile, calculer le sinus de la valeur (en
    // radian), placer le resultat sur la pile et retourner le resultat pour
    // l'affichage.
    double Sinus();

    // Retirer 1 valeur de la pile, calculer la racine carree de la valeur,
    // placer le resultat sur la pile et retourner le resultat pour
    // l'affichage.
    double SquareRoot();

    // Retirer 2 valeur de la pile, soustraire la 1e valeur de la 2e valeur,
    // placer le resultat sur la pile et retourner le resultat pour
    // l'affichage.
    double Substract();

    // Retirer 1 valeur de la pile, calculer la tengante de la valeur (en
    // radian), placer le resultat sur la pile et retourner le resultat pour
    // l'affichage.
    double Tangent();

    // Ajouter une valeur sur la pile.
    void PushValue(double aValue);

private:

    typedef std::stack<double> ValueStack;

};
