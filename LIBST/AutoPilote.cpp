
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      LIBST/AutoPilote.cpp

#include "Component.h"

// ===== MOON0 ==============================================================
#include <LIBST/Motor.h>

#include <LIBST/AutoPilote.h>

// Static function declaration
// //////////////////////////////////////////////////////////////////////////

static double ComputeTargetSpeed(double aAltitude_m);

namespace LIBST
{

    // Public
    // //////////////////////////////////////////////////////////////////////

    AutoPilote::AutoPilote() : mEnable(false), mMotor(NULL), mTank(NULL)
    {
    }

    void AutoPilote::Disable() { mEnable = false; }
    void AutoPilote::Enable() { mEnable = true; }

    bool AutoPilote::IsEnabled() const { return mEnable; }

    void AutoPilote::SetMotor(Motor* aMotor) { assert(NULL != aMotor); mMotor = aMotor; }
    void AutoPilote::SetTank(Tank* aTank) { assert(NULL != aTank); mTank = aTank; }

    void AutoPilote::Simulate(double aAltitude_m, double aSpeed_m_s)
    {
        assert(0.0 < aAltitude_m);

        if (mEnable)
        {
            mTargetSpeed_m_s = ComputeTargetSpeed(aAltitude_m);

            double lMaxPower = 0.89;

            if (10.0 > aAltitude_m) { lMaxPower = 1.0; }

            if (aSpeed_m_s < mTargetSpeed_m_s)
            {
                if (lMaxPower > mMotor->GetPower())
                {
                    (*mMotor)++;
                }
            }
            else
            {
                (*mMotor)--;
            }
        }
    }

    // Internal
    // //////////////////////////////////////////////////////////////////////

    double AutoPilote::GetTargetSpeed() const { return mTargetSpeed_m_s; }

}

std::ostream& operator << (std::ostream& aOut, const LIBST::AutoPilote& aAutoPilote)
{
    if (aAutoPilote.IsEnabled())
    {
        aOut << "Auto (" << aAutoPilote.GetTargetSpeed() << ")";
    }
    else
    {
        aOut << "Manual";
    }

    return aOut;
}

// Static function declaration
// //////////////////////////////////////////////////////////////////////////

typedef struct
{
    double mAltitude_m;
    double mSpeed_m_s;
}
TableEntry;

static const TableEntry TABLE[] =
{
    //  Alt. Speed
    { 1000.0, - 35.0 },
    {  450.0, - 30.0 },
    {  270.0, - 23.0 },
    {  200.0, - 18.0 },
    {  100.0, - 10.0 },
    {   25.0, -  4.0 },
    {    0.4, -  0.3 },
    {    0.0, -  0.0 },
};

#define TABLE_LEN (sizeof(TABLE) / sizeof(TABLE[0]))

double ComputeTargetSpeed(double aAltitude_m)
{
    double lResult_m_s = 0;

    for (unsigned int i = 1; i < TABLE_LEN; i++)
    {
        if (TABLE[i].mAltitude_m < aAltitude_m)
        {
            double lFactor = (aAltitude_m - TABLE[i].mAltitude_m) / (TABLE[i - 1].mAltitude_m - TABLE[i].mAltitude_m);

            lResult_m_s = TABLE[i].mSpeed_m_s + lFactor * (TABLE[i - 1].mSpeed_m_s - TABLE[i].mSpeed_m_s);

            break;
        }
    }

    return lResult_m_s;
}