
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      INJEC/TSL_File.h

#pragma once

// ===== C++ ================================================================
#include <fstream>

// ===== INJEC ==============================================================
#include "ITempSensorLink.h"

class TSL_File : public ITempSensorLink
{

public:

    TSL_File(const char* aFileName);

    // ===== ITempSensorLink ================================================
    virtual void GetData(double* aHumidity_pc, double* aTemp_C);

private:

    std::ifstream mFile;

};
