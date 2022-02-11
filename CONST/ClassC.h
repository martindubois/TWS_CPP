
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CONST/ClassC.h

#pragma once

// QUESTION Est-il possible de creer un tableau d'instance de la classe
//          ClassC ? Pourquoi ?
class ClassC
{

public:

    ClassC(const char* aName);

    ~ClassC();

    const char * GetName() const;

private:

    char* mName;

};
