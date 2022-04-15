
// Author    KMS - Martin Dubois, P. Eng.
// Copyright (C) 2022 KMS
// License   http://www.apache.org/licenses/LICENSE-2.0
// Product   TWS - CPP
// File      INJEC_Hardware/INJEC.scad

difference()
{
    cube( [ SIZE_X, SIZE_Y, SIZE_Z ] );

    translate( [ TICK, - EPS, - EPS ] )
        cube( [ SIZE_X - 2 * TICK, 2 * EPS + SIZE_Y, EPS + 8 ] );

    translate( [ 15, - EPS, 8 + TICK ] )
        cube( [ 23.5, 2 * EPS + SIZE_Y, 2 ] );

    translate( [ 17, - EPS, 8 + TICK + 2 - EPS ] )
        cube( [ 19.5, 2 * EPS + SIZE_Y, 2 * EPS + TICK ] );

    translate( [ SIZE_X - TICK - 3, - EPS, - EPS ] )
        cube( [ 3 + TICK + EPS, EPS + 8, 2 * EPS + SIZE_Z ] );

    for ( x = [ 0, SIZE_X ] )
    {
        translate( [ x, - EPS, SIZE_Z + 20 ] )
        {
            rotate( [ - 90, 0, 0 ] )
                cylinder( 2 * EPS + SIZE_Y, 24, 24, $fn = 64 );
        }
    }
}

// Private
// //////////////////////////////////////////////////////////////////////////

EPS = 0.1;

SIZE_X = 54.5;
SIZE_Y = 20;
SIZE_Z = 14;

TICK = 2;