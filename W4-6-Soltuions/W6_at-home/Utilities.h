// Workshop 6 - STL Containers
// 2019/10/25 - Cornel

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include "Vehicle.h"

namespace sdds
{
	Vehicle* createInstance(std::istream& in);
}

#endif