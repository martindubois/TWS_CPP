
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      Common/LIBDY/IRocket.h

#pragma once

// COMMENTAIRE PEDAGOGIQUE
// Quand Visual Studio cree un projet pour une librairie dynamique, il ajoute
// aux proprietes de celui-ci la definition du symbole {PROJECT}_EXPORTS, ici
// LIBDY_EXPORTS. Vous pouvez voir celui-ci dans le propriete "Processor
// Definitions" de la sous-section "Preprocessor" de la section "C/C++".
//
// Cette propriete agit exactement comme si la ligne #define LIBDY_EXPORTS
// etait ajoute au debut de tous les fichiers sources de la librairies.
//
// A cause de le definition de ce symbol, le compilation conditionnel qui
// suit donnera un code different selon que le fichier entete est inclue par
// un fichier source de la librairie ou par un fichier source d'un autre
// projet qui utilise la librairie.
//
// Dans le premier cas, LIBDY_API sera remplace par __declspec(dllexport).
// Cet ajout a la declaration d'une methode ou d'un operateur indiquera au
// compilateur que cette methode ou cet operateur doit etre accessible a
// l'exterieur de la library dynamique.
//
// Dans le second cas, LIBDY_API sera remplace par __declspec(dllimport).
// Cet ajout a la declaration indiquera au compilateur que le methode ou
// l'operateur doit etre cherche dans une librairie dynamique.
//
// Il est a noter qu'il n'est pas necessaire d'ajouter le LIBDY_EXPORTS
// pour les methodes virtuelles d'un interface. Le projet qui appelere
// c'est methode le fera au travers de la table de methodes virtuelles.
//
// La mecanique decrite ici, est specifique a Windows et n'existe pas
// sous Linux. Sous Linux, par defaut, toutes les methodes, operateurs ou
// autres sont accessible de l'exterieure de la librairie dynamique.
//
// Personnellement, je prefere n'exposer que le strict minimum. Donc, sous
// Linux, je change le defaut pour indiquer que je n'exporte rien par
// defaut et j'utiliser un fichier .def pour indiquer ce que la librarie
// doit exorter.
#ifdef LIBDY_EXPORTS
    #define LIBDY_API __declspec(dllexport)
#else
    #define LIBDY_API __declspec(dllimport)
#endif

// COMMENTAIRE PEDAGOGQUE
// L'utilisation d'un namespace m'assure que ma classe IRocket n'entrera pas
// en conflit avec une autre classe IRocket qu'une autre librairie pourrait
// definir.
namespace LIBDY
{

    class IRocket
    {

    public:

        // Cette methode cree une instance d'une classe qui implemente
        // l'interface IRocket.
        static LIBDY_API IRocket* Create();

        // Cette methode detruit l'instance.
        virtual void Destroy() = 0;

        virtual void Command(char aLetter) = 0;

        virtual double GetAltitude() const = 0;
        virtual double GetSpeed   () const = 0;

        virtual void Simulate() = 0;

    };

}

// Cet operateur permet l'utilisation de l'interface IRocket avec la classe
// std::ostream.
LIBDY_API std::ostream& operator << (std::ostream& aOut, const LIBDY::IRocket& aRocket);
