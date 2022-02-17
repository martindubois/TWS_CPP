
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http ://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      LISTE/LISTE.cpp

// ===== C ==================================================================
#include <assert.h>

// ===== LISTE ==============================================================
#include "Friend.h"

// Static fonction declarations
// //////////////////////////////////////////////////////////////////////////

static void Add     (Friend** aHead, const char* aLine);
static void Display (Friend** aHead);
static void FreeList(Friend** aHead);
static void Remove  (Friend** aHead, const char* aLine);

// Entry point
// //////////////////////////////////////////////////////////////////////////

int main()
{
    Friend* lHead = NULL;

    for (;;)
    {
        char lLine[1024];

        printf("Enter a command\n");

        if (NULL != fgets(lLine, sizeof(lLine), stdin))
        {
            if      (0 == _strnicmp("Add"    , lLine, 3)) { Add(&lHead, lLine); }
            else if (0 == _strnicmp("Display", lLine, 7)) { Display(&lHead); }
            else if (0 == _strnicmp("Exit"   , lLine, 4)) { break; }
            else if (0 == _strnicmp("Remove" , lLine, 6)) { Remove(&lHead, lLine); }
        }
    }

    return 0;
}

// Static functions
// //////////////////////////////////////////////////////////////////////////

void Add(Friend** aHead, const char* aLine)
{
    assert(NULL != aHead);
    assert(NULL != aLine);

    char lFirstName[1024];
    char lLastName [1024];

    if (2 != sscanf_s(aLine + 3, " %s %s\n", lFirstName, sizeof(lFirstName), lLastName, sizeof(lLastName)))
    {
        printf("USER ERROR  The command line is not valid\n");
        return;
    }

    Friend* lNew = new Friend();
    assert(NULL != lNew);

    lNew->Initialise(lFirstName, lLastName);

    Friend* lCurrent = *aHead;
    Friend* lPrevious = NULL;

    while (NULL != lCurrent)
    {
        if (0 >= strcmp(lFirstName, lCurrent->GetFirstName()))
        {
            break;
        }

        lPrevious = lCurrent;
        lCurrent = lCurrent->Next_Get();
    }

    if (NULL != lPrevious)
    {
        lPrevious->Next_Set(lNew);
    }
    else
    {
        *aHead = lNew;
    }

    lNew->Next_Set(lCurrent);
}

void Display(Friend** aHead)
{
    assert(NULL != aHead);

    Friend* lCurrent = *aHead;

    while (NULL != lCurrent)
    {
        lCurrent->Display();

        lCurrent = lCurrent->Next_Get();
    }
}

void FreeList(Friend** aHead)
{
    assert(NULL != aHead);

    Friend* lCurrent = *aHead;

    while (NULL != lCurrent)
    {
        Friend* lNext = lCurrent->Next_Get();

        delete lCurrent;

        lCurrent = lNext;
    }

    *aHead = NULL;
}

void Remove(Friend** aHead, const char* aLine)
{
    assert(NULL != aHead);
    assert(NULL != aLine);

    char lFirstName[1024];
    char lLastName [1024];

    if (2 != sscanf_s(aLine + 6, " %s %s\n", lFirstName, sizeof(lFirstName), lLastName, sizeof(lLastName)))
    {
        printf("USER ERROR  The command line is not valid\n");
        return;
    }

    Friend* lCurrent = *aHead;
    Friend* lPrevious = NULL;

    while (NULL != lCurrent)
    {
        if (   (0 == strcmp(lFirstName, lCurrent->GetFirstName()))
            && (0 == strcmp(lLastName , lCurrent->GetLastName ())))
        {
            Friend* lNext = lCurrent->Next_Get();

            if (NULL != lPrevious)
            {
                lPrevious->Next_Set(lNext);
            }
            else
            {
                *aHead = lNext;
            }

            delete lCurrent;
            break;
        }

        lPrevious = lCurrent;
        lCurrent = lCurrent->Next_Get();
    }
}
