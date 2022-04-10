
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CONVE/CONVE.cpp

// ===== C ==================================================================
#include <assert.h>

// ===== C++ ================================================================
#include <iostream>

// ===== CONVE ==============================================================
#include "Classes.h"

// Data types
// //////////////////////////////////////////////////////////////////////////

typedef void (* Case)(void);

// Static function declarations
// //////////////////////////////////////////////////////////////////////////

static void Case00();
static void Case01();
static void Case02();
static void Case03();
static void Case04();
static void Case05();
static void Case06();
static void Case07();
static void Case08();
static void Case09();
static void Case10();
static void Case11();
static void Case12();
static void Case13();
static void Case14();
static void Case15();
static void Case16();
static void Case17();
static void Case18();
static void Case19();
static void Case20();
static void Case21();
static void Case22();
static void Case23();
static void Case24();
static void Case25();
static void Case26();
static void Case27();
static void Case28();
static void Case29();

// Constantes
// //////////////////////////////////////////////////////////////////////////

static Case CASES[] =
{
   Case00, Case01, Case02, Case03, Case04, Case05, Case06, Case07, Case08, Case09,
   Case10, Case11, Case12, Case13, Case14, Case15, Case16, Case17, Case18, Case19,
   Case20, Case21, Case22, Case23, Case24, Case25, Case26, Case27, Case28, Case29,
};

#define CASE_QTY (sizeof(CASES) / sizeof(CASES[0]))

// Entry point
// //////////////////////////////////////////////////////////////////////////

int main(int aCount, const char** aVector)
{
    assert(1 <= aCount);
    assert(NULL != aVector);

    if (2 > aCount)
    {
        std::cerr << "USER ERROR  You must pass the COM port name as first argument\n";
        return 1;
    }

    assert(NULL != aVector[1]);

    if (0 == _stricmp("All", aVector[1]))
    {
        for (unsigned int i = 0; i < CASE_QTY; i++)
        {
            std::cout << "Case #" << i << "\n";
            CASES[i]();
        }
    }
    else
    {
        int lCase = atoi(aVector[1]);
        if ((0 <= lCase) && (CASE_QTY > lCase))
        {
            std::cout << "Case #" << lCase << "\n";
            CASES[lCase]();
        }
        else
        {
            std::cerr << "Invalid case\n";
        }
    }

    return 0;
}

// Static functions
// //////////////////////////////////////////////////////////////////////////

// Implicite double -> int
// WARNING
// Perte de la faction
// RISQUE Depassement de l'etendu du int
void Case00()
{
    double lA = 77.7;
    std::cout << "A : " << lA << "\n";

    int lB = lA;
    std::cout << "B : " << lB << "\n";
}

// Implicite double -> int64_t
// WARNING
// Perte de la faction
// RISQUE Depassement de l'etendu du int64_t
void Case01()
{
    double lA = 77.7;
    std::cout << "A : " << lA << "\n";

    int64_t lB = lA;
    std::cout << "B : " << lB << "\n";
}

// Implicite double -> uint64_t
// WARNING
// Perte de la faction
// RISQUE Depassement de l'etendu du uint64_t
void Case02()
{
    double lA = 77.7;
    std::cout << "A : " << lA << "\n";

    uint64_t lB = lA;
    std::cout << "B : " << lB << "\n";
}

// Implicite double -> unsigned int
// WARNING
// Perte de la faction
// RISQUE Depeassement de l'etendu
void Case03()
{
    double lA = 77.7;
    std::cout << "A : " << lA << "\n";

    unsigned int lB = lA;
    std::cout << "B : " << lB << "\n";
}

// Implicite float -> int64_t
// Perte de la fraction
// RISQUE Depassement de l'etendu du int64_t
void Case04()
{
    float lA = 77.7;
    std::cout << "A : " << lA << "\n";

    int64_t lB = lA;
    std::cout << "B : " << lB << "\n";
}

// Implicite float -> uint64_t
// Perte de la faction
// RISQUE Conversion invalid de valeur negative
// RISQUE Depassement de l'etendu du uint64_t
void Case05()
{
    float lA = 77.7;
    std::cout << "A : " << lA << "\n";

    uint64_t lB = lA;
    std::cout << "B : " << lB << "\n";
}

// Implicite int -> unsigned int
// RISQUE Conversion invalide de valeur negative
void Case06()
{
    int lA = 7200;
    std::cout << "A : " << lA << "\n";

    unsigned int lB = lA;
    std::cout << "B : " << lB << "\n";
}

// Implicite int -> unsigned int (valeur connue par le compilateur et negative)
// ERREUR Conversion invalide de valeur negative
void Case07()
{
    int lA = -7200;
    std::cout << "A : " << lA << "\n";

    unsigned int lB = lA;
    std::cout << "B : " << lB << "\n";
}

// Implicite int32_t -> int32_t
void Case08()
{
    int32_t lA = 7200;
    std::cout << "A : " << lA << "\n";

    int32_t lB = lA;
    std::cout << "B : " << lB << "\n";
}

// Implicite int32_t -> int16_t
// RISQUE Depassement de l'etendu du int16_t
void Case09()
{
    int32_t lA = 7200;
    std::cout << "A : " << lA << "\n";

    int16_t lB = lA;
    std::cout << "B : " << lB << "\n";
}

// Implicite int32_t -> int16_t (le compilateur ne connait pas la valeur)
// RISQUE Depassement de l'etendu du int16_t
void Case10()
{
    int32_t lA = strtoul("7200", NULL, 10);
    std::cout << "A : " << lA << "\n";

    int16_t lB = lA;
    std::cout << "B : " << lB << "\n";
}

// Implicite int32_t -> int16_t (valeur connue par le compilateur et trop grande)
// ERREUR Depassement de l'entendu
void Case11()
{
    int32_t lA = 77000;
    std::cout << "A : " << lA << "\n";

    int16_t lB = lA;
    std::cout << "B : " << lB << "\n";
}

// dynamic_cast ClassA * -> ClassB *
void Case12()
{
    ClassA* lA = new ClassB;
    std::cout << "A : ";
    lA->Display();

    ClassB* lB = dynamic_cast<ClassB*>(lA);
    std::cout << "B : " << ((NULL == lB) ? "NULL\n" : "Pas NULL\n");
}

// dynamic_cast ClassA * -> ClassB *
void Case13()
{
    ClassA* lA = new ClassC;
    std::cout << "A : ";
    lA->Display();

    ClassB* lB = dynamic_cast<ClassB*>(lA);
    std::cout << "B : " << ((NULL == lB) ? "NULL\n" : "Pas NULL\n");
}

// dynamic_cast ClassA * -> ClassD *
void Case14()
{
    ClassA* lA = new ClassB;
    std::cout << "A : ";
    lA->Display();

    ClassD* lB = dynamic_cast<ClassD*>(lA);
    std::cout << "B : " << ((NULL == lB) ? "NULL\n" : "Pas NULL\n");
}

// dynamic_cast ClassB * -> ClassA *
void Case15()
{
    ClassB* lA = new ClassB;
    std::cout << "A : ";
    lA->Display();

    ClassA* lB = dynamic_cast<ClassA*>(lA);
    std::cout << "B : " << ((NULL == lB) ? "NULL\n" : "Pas NULL\n");
}

// static_case Class_A * -> Class_B *
void Case16()
{
    ClassA* lA = new ClassB;
    std::cout << "A : ";
    lA->Display();

    ClassB* lB = static_cast<ClassB*>(lA);
    std::cout << "B : " << ((NULL == lB) ? "NULL\n" : "Pas NULL\n");
}

// static_case Class_A * -> Class_B *
// ERREUR
void Case17()
{
    ClassA* lA = new ClassC;
    std::cout << "A : ";
    lA->Display();

    ClassB* lB = static_cast<ClassB*>(lA);
    std::cout << "B : " << ((NULL == lB) ? "NULL\n" : "Pas NULL\n");
}

// static_cast Class_B * -> ClassA *
void Case18()
{
    ClassB* lA = new ClassB;
    std::cout << "A : ";
    lA->Display();

    ClassA* lB = static_cast<ClassA*>(lA);
    std::cout << "B : " << ((NULL == lB) ? "NULL\n" : "Pas NULL\n");
}

// static_cast double -> int
// Perte de la fraction
// ERREUR Depassement de l'etendu
void Case19()
{
    double lA = 1.2e10;
    std::cout << "A : " << lA << "\n";

    int lB = static_cast<int>(lA);
    std::cout << "B : " << lB << "\n";
}

// static_cast double -> unsigned int
// Perte de la fraction
// ERREUR Depassement de l'etendu
void Case20()
{
    double lA = - 1.2;
    std::cout << "A : " << lA << "\n";

    unsigned int lB = static_cast<int>(lA);
    std::cout << "B : " << lB << "\n";
}

// static_cast int32_t -> int16_t
// ERREUR Depassement de l'etendu
void Case21()
{
    int32_t lA = 88000;
    std::cout << "A : " << lA << "\n";

    int16_t lB = static_cast<int16_t>(lA);
    std::cout << "B : " << lB << "\n";
}

// static_cast int32_t -> uint32_t
// ERREUR Depassement de l'etendu
void Case22()
{
    int32_t lA = -8800;
    std::cout << "A : " << lA << "\n";

    uint32_t lB = static_cast<uint32_t>(lA);
    std::cout << "B : " << lB << "\n";
}

// static_cast uint8_t -> int8_t
// ERREUR Depassement de l'etendu
void Case23()
{
    uint8_t lA = 200;
    std::cout << "A : " << static_cast<uint16_t>(lA) << "\n";

    int8_t lB = static_cast<int8_t>(lA);
    std::cout << "B : " << static_cast<int16_t>(lB) << "\n";
}

// reinterpret_cast const char * -> const void * -> const char *
void Case24()
{
    const char* lA = "Case24";
    std::cout << "A : " << lA << "\n";

    const void* lTmp = reinterpret_cast<const void*>(lA);

    const char* lB = reinterpret_cast<const char*>(lTmp);
    std::cout << "B : " << lB << "\n";
}

void Case25()
{

}

void Case26()
{

}

void Case27()
{

}

// reinterpret_cast const char * -> unsigned int -> const char *
// ERREUR FATALE (en x64)
void Case28()
{
    const char* lA = "Constante";
    std::cout << "A : " << lA << "\n";

    unsigned int lTmp = reinterpret_cast<unsigned int>(lA);

    const char* lB = reinterpret_cast<const char *>(lTmp);
    std::cout << "B : " << lB << "\n";
}

// const_cast char * -> const char *
// ERREUR FATALE Modification d'une valeure constantes
void Case29()
{
    const char* lA = "Constante";
    std::cout << "A : " << lA << "\n";

    char* lB = const_cast<char*>(lA);
    strcpy_s(lB, 10, "Pas const.");

    std::cout << "A : " << lA << "\n";
}
