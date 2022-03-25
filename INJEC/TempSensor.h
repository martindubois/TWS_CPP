
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      INJEC/TempSensor.h

#pragma once

// ===== C++ ================================================================
#include <list>
#include <string>

// ===== Windows ============================================================
#include <Windows.h>

class TempSensor
{

public:

    TempSensor(const char* aComPortName);

    ~TempSensor();

    void GetData(double* aHumidity_pc, double* aTemp_C);

private:

    typedef struct
    {
        double mHumidity_pc;
        double mTemp_C;
    }
    Data;

    HANDLE mComPort;

    std::list<Data> mList;

    Data mSum;

};
