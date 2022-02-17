
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http ://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CLASS/Form_Square.h

#pragma once

// ===== CLASS ==============================================================
#include "Form.h"

class Form_Square : public Form
{

public:

    Form_Square();

    // ===== Form ===========================================================

    virtual ~Form_Square();

    virtual double GetArea     () const;
    virtual double GetPerimeter() const;

    virtual unsigned int GetInfoCount() const;
    virtual const char * GetInfoName(unsigned int aIndex) const;

    virtual void SetInfo(unsigned int aIndex, double aValue);

private:

    double mBase_mm;

};
