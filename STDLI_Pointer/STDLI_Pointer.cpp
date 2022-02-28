
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      STDLI_Pointer/STDLI_Pointer.cpp

// ===== C ==================================================================
#include <assert.h>

// ===== C++ ================================================================
#include <list>

// ===== LISTE ==============================================================
#include "Friend.h"

// Static fonction declarations
// //////////////////////////////////////////////////////////////////////////

static void Add     (std::list<Friend*>* aList, const char* aLine);
static void Display (std::list<Friend*>* aList);
static void FreeList(std::list<Friend*>* aList);
static void Remove  (std::list<Friend*>* aList, const char* aLine);

// Entry point
// //////////////////////////////////////////////////////////////////////////

int main()
{
    std::list<Friend*> lList;

    for (;;)
    {
        char lLine[1024];

        printf("Enter a command\n");

        if (NULL != fgets(lLine, sizeof(lLine), stdin))
        {
            if      (0 == _strnicmp("Add"    , lLine, 3)) { Add(&lList, lLine); }
            else if (0 == _strnicmp("Display", lLine, 7)) { Display(&lList); }
            else if (0 == _strnicmp("Exit"   , lLine, 4)) { break; }
            else if (0 == _strnicmp("Remove" , lLine, 6)) { Remove(&lList, lLine); }
        }
    }

    FreeList(&lList);

    return 0;
}

// Static functions
// //////////////////////////////////////////////////////////////////////////

void Add(std::list<Friend*>* aList, const char* aLine)
{
    assert(NULL != aList);
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

    for (std::list<Friend*>::iterator lIt = aList->begin(); lIt != aList->end(); lIt++)
    {
        if (0 >= strcmp(lFirstName, (*lIt)->GetFirstName()))
        {
            aList->insert(lIt, lNew);
            return;
        }
    }

    aList->push_back(lNew);
}

void Display(std::list<Friend*>* aList)
{
    assert(NULL != aList);

    for (std::list<Friend*>::iterator lIt = aList->begin(); lIt != aList->end(); lIt++)
    {
        (*lIt)->Display();
    }
}

void FreeList(std::list<Friend*>* aList)
{
    assert(NULL != aList);

    for (std::list<Friend*>::iterator lIt = aList->begin(); lIt != aList->end(); lIt++)
    {
        delete (*lIt);
    }

    aList->clear();
}

void Remove(std::list<Friend*>* aList, const char* aLine)
{
    assert(NULL != aList);
    assert(NULL != aLine);

    char lFirstName[1024];
    char lLastName [1024];

    if (2 != sscanf_s(aLine + 6, " %s %s\n", lFirstName, sizeof(lFirstName), lLastName, sizeof(lLastName)))
    {
        printf("USER ERROR  The command line is not valid\n");
        return;
    }

    for (std::list<Friend*>::iterator lIt = aList->begin(); lIt != aList->end(); lIt++)
    {
        if (   (0 == strcmp(lFirstName, (*lIt)->GetFirstName()))
            && (0 == strcmp(lLastName , (*lIt)->GetLastName ())))
        {
            delete (*lIt);
            aList->erase(lIt);
            break;
        }
    }
}
