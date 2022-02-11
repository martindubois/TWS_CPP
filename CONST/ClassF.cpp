
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CONST/ClassF.cpp

// ===== C++ ================================================================
#include <iostream>

// ===== CONST ==============================================================
#include "ClassF.h"

// Public
// //////////////////////////////////////////////////////////////////////////

ClassF::ClassF() : ClassD("Inconnue")
{
}

ClassF::~ClassF()
{
    std::cout << "Instance detruite\n";
}
