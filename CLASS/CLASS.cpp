
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CLASS/CLASS.cpp

// QUESTION Expliquez toutes les modifications que vous devriez faire a ce
//          fichier sources pour supporter une nouvelle forme.

// ===== C ==================================================================
#include <assert.h>
#include <string.h>

// ===== C++ ================================================================
#include <iostream>

// ===== CLASS ==============================================================
#include "Form_Rectangle.h"

// Static function declarations
// //////////////////////////////////////////////////////////////////////////

static Form* CreateForm(const char* aName);

// Entry point
// //////////////////////////////////////////////////////////////////////////

// QUESTION Quelle valeur retournera la fonction main si l'utilisateur lance
//          le programme sans passer d'argument ?

// QUESTION Quelle valeur retournera la fonction main si l'utilisateur lance
//          le programme en passant "Patate" comme premier argument ?

// COMMENTAIRE PEDAGOGIQUE - Bonne pratique
// Remarquez que tous le code qui interragie avec l'utilisateur est place
// dans la fonction main. Aucun code d'interaction ne se trouve dans les
// classes Form ou Form_Rectangle. De cette maniere, si un jour nous desirons
// remplacer notre interface en ligne de commande par un interface graphique,
// seul la fonction main devra etre modifiee.

int main(int aCount, const char** aVector)
{
    // QUESTION (Decouverte) Que font les deux ligne qui suivent en Debug ?
    //          et en Release ?
    assert(1 <= aCount);
    assert(NULL != aVector);

    if (2 > aCount)
    {
        std::cerr << "ERREUR UTILISATEUR  Le nom de la forme doit etre passee en argument\n";
        return 1;
    }

    assert(NULL != aVector[1]);

    Form* lForm = CreateForm(aVector[1]);
    if (NULL == lForm)
    {
        std::cerr << "ERREUR UTILISATEUR  Le nom de la form ne correspond pas a une forme supporte\n";
        return 2;
    }

    unsigned int lCount = lForm->GetInfoCount();
    for (unsigned int i = 0; i < lCount; i++)
    {
        std::cout << "Entrez " << lForm->GetInfoName(i) << "\n";

        // COMMENTAIRE PEDAGOGIQUE - Bonne pratique
        // Le "mm" a la fin du nom de variable "lValue_mm" represente l'unite
        // de mesure associe a la valeur. De cette maniere, il est facile de
        // s'assurer que nous manipulons les bons unites de mesure a chaque
        // fois que le programme utilise ou modifie la variable.
        double lValue_mm;

        std::cin >> lValue_mm;

        lForm->SetInfo(i, lValue_mm);
    }

    std::cout << "L'aire de la forme est de "       << lForm->GetArea     () << " mm carree\n";
    std::cout << "Le perimetre de la forme est de " << lForm->GetPerimeter() << " mm\n";

    delete lForm;

    return 0;
}

// Static function declarations
// //////////////////////////////////////////////////////////////////////////

// COMMENTAIRE PEDAGOGIQUE - Bonne pratique
// La creation de l'instance de Form est place dans une fonction separee.
// C'est fait ainsi, car si nous ajoutons plusieurs types de formes, la liste
// des "si" deviendra assez longue. Il est donc preferable qu'elle soit la
// seul operation dans une fonction. Cela correspond aussi au principe
// qu'une fonction devrait avoir une seule responsabilite bien definit. Ici,
// la responsabilite est de creer une instance de class correspondant a la
// forme demandee. Il est aussi important de remarquer, que les classes
// propres a chaque types de formes ne sont pas connue a l'exterieur de
// cette fonction.

Form* CreateForm(const char* aName)
{
    assert(NULL != aName);

    Form* lResult = NULL;

    if (0 == _stricmp("Rectangle", aName)) { lResult = new Form_Rectangle(); }

    return lResult;
}
