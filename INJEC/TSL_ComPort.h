
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      INJEC/TSL_ComPort.h

#pragma once

// ===== Windows ============================================================
#include <Windows.h>

// ===== INJEC ==============================================================
#include "ITempSensorLink.h"

class TSL_ComPort : public ITempSensorLink
{

public:

    TSL_ComPort(const char* aComPortName);

    ~TSL_ComPort();

    // ===== ITempSensorLink ================================================
    virtual void GetData(double* aHumidity_pc, double* aTemp_C);

private:

    HANDLE mComPort;

};