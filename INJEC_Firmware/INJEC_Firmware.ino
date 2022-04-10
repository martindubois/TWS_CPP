
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      INJEC_Firmware/INJEC_Firmware.ino

#include <DHT.h>

// Static variables
// //////////////////////////////////////////////////////////////////////////

DHT sDHT(2, DHT22);

// Entry points
// //////////////////////////////////////////////////////////////////////////

void setup()
{
    Serial.begin(115200);

    sDHT.begin();
}

void loop()
{
    delay(2000);

    int8_t lRaw[3];

    lRaw[0] = 0xff;
    lRaw[1] = sDHT.readHumidity();
    lRaw[2] = sDHT.readTemperature();

    Serial.write(reinterpret_cast<char *>(lRaw), sizeof(lRaw));

    delay(2000);
}
