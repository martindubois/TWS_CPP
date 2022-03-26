
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      INJEC/TempSensor.cpp

// ===== C ==================================================================
#include <assert.h>

// ===== INJEC ==============================================================
#include "ITempSensorLink.h"

#include "TempSensor.h"

// Public
// //////////////////////////////////////////////////////////////////////////

TempSensor::TempSensor()
{
    mSum.mHumidity_pc = 0.0;
    mSum.mTemp_C      = 0.0;
}

void TempSensor::GetData(double* aHumidity_pc, double* aTemp_C)
{
    assert(NULL != aHumidity_pc);
    assert(NULL != aTemp_C);

    assert(NULL != mLink);

    Data lData;

    mLink->GetData(&lData.mHumidity_pc, &lData.mTemp_C);

    mSum.mHumidity_pc += lData.mHumidity_pc;
    mSum.mTemp_C      += lData.mTemp_C;

    mList.push_front(lData);

    unsigned int lLen = mList.size();
    if (10 < lLen)
    {
        mSum.mHumidity_pc -= mList.back().mHumidity_pc;
        mSum.mTemp_C      -= mList.back().mTemp_C;

        mList.pop_back();
        lLen--;
    }

    *aHumidity_pc = mSum.mHumidity_pc / lLen;
    *aTemp_C      = mSum.mTemp_C      / lLen;
}

void TempSensor::SetLink(ITempSensorLink* aLink)
{
    assert(NULL != aLink);

    mLink = aLink;
}
