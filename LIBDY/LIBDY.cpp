
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      LIBDY/LIBDY.cpp

#include "Component.h"

// ===== Windows ============================================================
#include <Windows.h>

// Entry point
// //////////////////////////////////////////////////////////////////////////

// COMMENTAIRE PEDAGOGIQUE
// Sous Windows, une librarie dynamique doit avoir une fonction DllMain.
// Chaque fois qu'un programme charge la librairie, cette methode est appele.
// Elle est aussi appele quand un programme decharge la librarie, cree un
// thread ou qu'un thread se termine.
//
// Parfois, une librairie utilise cette fonction pour allouer la memoire
// necessaire pour chacun des programmes qui l'utilise. La librairie,
// pourrait aussi effectuer d'autre taches d'initialisation ou de netoyage.
//
// Souvent, cette fonction, comme c'est le cas ici, ne fait rien.
//
// Personellement, je prefere qu'elle ne fasse rien car l'equivalent n'existe
// pas sour Linux.
//
// De toute maniere, si une initialisation est necessaire, il est facile de
// creer et exporter une fonction qui s'en chargera.
BOOL APIENTRY DllMain(HMODULE aModule, DWORD aReason, LPVOID aReserved)
{
    switch (aReason)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }

    return TRUE;
}

