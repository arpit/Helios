//
//  DateUtils.cpp
//  StartupsViz
//
//  Created by Mathur, Arpit on 7/18/13.
//
//

#include "DateUtils.h"
#include <stream.h>

int differenceInDays( int endDay, int endMonth, int endYear, int startDay, int startMonth, int startYear){
    
    return ((endYear*365) + (endMonth*30) + endDay) - ((startYear* 365)+ (startMonth*30)+startDay);
}
