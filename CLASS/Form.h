
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http ://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      CLASS/Form.h

#pragma once

class Form
{

public:

    virtual ~Form();

    virtual double GetArea     () const = 0;
    virtual double GetPerimeter() const = 0;

    virtual unsigned int GetInfoCount() const = 0;
    virtual const char * GetInfoName (unsigned int aIndex) const = 0;

    virtual void SetInfo(unsigned int aIndex, double aValue_mm) = 0;

protected:

    // QUESTION Pourquoi le constructeur de la classe Form est-il
    //          "protected" ?
    Form();

};
