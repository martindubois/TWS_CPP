
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CLASS/Form_Parallelogram.h

#pragma once

// ===== CLASS ==============================================================
#include "Form.h"

class Form_Parallelogram : public Form
{

public:

    Form_Parallelogram();

    // ===== Form ===========================================================

    virtual ~Form_Parallelogram();

    virtual double GetArea     () const;
    virtual double GetPerimeter() const;

    virtual unsigned int GetInfoCount() const;
    virtual const char * GetInfoName(unsigned int aIndex) const;

    virtual void SetInfo(unsigned int aIndex, double aValue);

private:

    double mAngle_deg;
    double mBase_mm;
    double mSide_mm;

};
