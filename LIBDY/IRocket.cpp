
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      LIBDY/IRocket.cpp

#include "Component.h"

// ===== C++ ================================================================
#include <iomanip>

// ===== Common =============================================================
#include <LIBDY/IRocket.h>

// ===== LIBDY ==============================================================
#include "Rocket.h"

namespace LIBDY
{

    // Public
    // //////////////////////////////////////////////////////////////////////

    IRocket* IRocket::Create()
    {
        return new Rocket();
    }

}

std::ostream& operator << (std::ostream& aOut, const LIBDY::IRocket& aRocket)
{
    const Rocket * lRocket = dynamic_cast<const Rocket*>(&aRocket);
    assert(NULL != lRocket);

    return aOut << *lRocket;
}
