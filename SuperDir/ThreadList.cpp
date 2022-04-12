
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/ThreadList.cpp

#include "Component.h"

// ===== SuperDir ===========================================================
#include "ThreadList.h"

// Public
// //////////////////////////////////////////////////////////////////////////

void ThreadList::WaitAndClose()
{
    for (HANDLE lThread : *this)
    {
        assert(NULL != lThread);

        DWORD lRet = WaitForSingleObject(lThread, 60000);
        assert(WAIT_OBJECT_0 == lRet);

        BOOL lRetB = CloseHandle(lThread);
        assert(lRetB);
    }
}
