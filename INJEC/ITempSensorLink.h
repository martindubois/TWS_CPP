
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      INJEC/ITempSensorLink.h

#pragma once

class ITempSensorLink
{

public:

    virtual void GetData(double* aHumidity_pc, double* aTemp_C) = 0;

};

