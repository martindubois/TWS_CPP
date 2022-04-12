
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      SuperDir/ThreadList.h

#pragma once

// ===== C++ ================================================================
#include <list>

// ===== Windows ============================================================
#include <Windows.h>

class ThreadList : public std::list<HANDLE>
{

public:

    void WaitAndClose();

};
