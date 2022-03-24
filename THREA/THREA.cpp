
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      THREA/THREA.cpp

// ===== C ==================================================================
#include <stdint.h>
#include <stdio.h>

// ===== Windows ============================================================
#include <Windows.h>

// Constants
// //////////////////////////////////////////////////////////////////////////

// IMPORTANT La valeur de la constante GOAL doit etre divisible par le nombre
//           de fils d'execution (THREAD_QTY).
#define GOAL (160000000)

#define THREAD_QTY (8)

#define GOAL_BY_THREAD (GOAL/THREAD_QTY)

// Static function declarations
// //////////////////////////////////////////////////////////////////////////

// QUESTION (Revision) La declaration de la fonction qui suit debut par le
//          mot cle "static". Qu'indique ce mot cle au compilateur ?
static void CloseThreads(HANDLE* aThread, unsigned int aCount);

static unsigned int CreateThreads(HANDLE* aThreads);

// QUESTION Les deux declarations de fonction qui suivent inclue le mot
//          "WINAPI" entre le type de retour et le nom de la fonction. En
//          placant notre pointeur de souris sur ce dernier nous apprenons
//          que celui-ci sera remplace par "__stdcall" par le preprocesseur
//          au moment de la compilation. Pourquoi cet ajout est-elle ici
//          essentiel ?
static DWORD WINAPI Run0(LPVOID aParam);
static DWORD WINAPI Run1(LPVOID aParam);

// Static variables
// //////////////////////////////////////////////////////////////////////////

static CRITICAL_SECTION sGate;

static uint64_t sValue = 0;

// Entry point
// //////////////////////////////////////////////////////////////////////////

int main()
{
    InitializeCriticalSection(&sGate);

    // J'utilise le type uint64_t plutot que FILETIME pour les temps car cela
    // falicite les calcules de difference entre deux temps.
    uint64_t lBegin;

    GetSystemTimePreciseAsFileTime(reinterpret_cast<FILETIME*>(&lBegin));

    HANDLE lThreads[THREAD_QTY];

    unsigned int lThreadCount = CreateThreads(lThreads);

    // QUESTION La fonction WaitForMultipleObjects attends que les "objets"
    //          specifies soit dans l'etats signale avant de retourner.
    //          1. Que signifie le TRUE passe comme 3ieme argument ?
    //          2. Que signifie le 60000 passe comme 4ieme argument ?
    DWORD lRet = WaitForMultipleObjects(lThreadCount, lThreads, TRUE, 60000);
    if (WAIT_OBJECT_0 + lThreadCount - 1 != lRet)
    {
        fprintf(stderr, "ERROR  WaitForMultipleObjects( , , ,  ) failed\n");
    }

    CloseThreads(lThreads, lThreadCount);

    // QUESTION Que se passera-t-il si nous oublions d'appeler
    //          DeleteCriticalSection comme nous le faisons ici ?
    DeleteCriticalSection(&sGate);

    uint64_t lEnd;

    GetSystemTimePreciseAsFileTime(reinterpret_cast<FILETIME*>(&lEnd));

    uint64_t lDuration_100ns = lEnd - lBegin;
    double lDuration_us = static_cast<double>(lDuration_100ns / 10);
    double lDuration_ms = lDuration_us / 1000;
    double lDuration_s = lDuration_ms / 1000;

    uint64_t lMissing = GOAL - sValue;

    printf("La valeur finale est %llu (%llu manquant, %llu %%)\n", sValue, lMissing, lMissing * 100 / GOAL);
    printf("Execution en %f s\n", lDuration_s);

    return 0;
}

// Static functions
// //////////////////////////////////////////////////////////////////////////

// QUESTION Qu'arriverait-il si nous oublions d'appeler CloseHandle pour
//          chacun des HANDLEs de thread, comme c'est fait dans cette
//          fonction ?
void CloseThreads(HANDLE* aThreads, unsigned int aCount)
{
    for (unsigned int i = 0; i < aCount; i++)
    {
        BOOL lRetB = CloseHandle(aThreads[i]);
        if (!lRetB)
        {
            fprintf(stderr, "ERROR  CloseHandle(  ) failed\n");
        }
    }
}

unsigned int CreateThreads(HANDLE* aThreads)
{
    unsigned int lResult;

    for (lResult = 0; lResult < THREAD_QTY; lResult++)
    {
        DWORD lThreadId;

        aThreads[lResult] = CreateThread(NULL, 0, Run0, NULL, 0, &lThreadId);
        if (NULL == aThreads[lResult])
        {
            fprintf(stderr, "ERROR  CreatThread( , , , , ,  ) failed\n");
            break;
        }
    }

    return lResult;
}

DWORD WINAPI Run0(LPVOID aParam)
{
    for (uint64_t i = 0; i < GOAL_BY_THREAD; i++)
    {
        sValue++;
    }

    return 0;
}

DWORD WINAPI Run1(LPVOID aParam)
{
    for (uint64_t i = 0; i < GOAL_BY_THREAD; i++)
    {
        // QUESTION Que fait la fonction EnterCriticalSection ?
        EnterCriticalSection(&sGate);
        {
            sValue++;
        }
        LeaveCriticalSection(&sGate);
    }

    return 0;
}
