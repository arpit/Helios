//
//  heLerp.cpp
//  StartupsViz
//
//  Created by Gabo Mendoza on 7/18/13.
//
//

#include "heLerp.h"

float lerp( float t , float min , float max ) {
    //cout << min + (max-min)*t << endl;
    return min + (max-min)*t;
}


