
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      Common/LIBST/Tank.h

#pragma once

namespace LIBST
{

    class Tank
    {

    public:

        Tank();

        double GetFuel(double aRequested_l);

        double GetLevel() const;

    private:

        double mLevel_l;

    };

}

std::ostream& operator << (std::ostream& aOut, const LIBST::Tank& aTank);
