// Workshop 6 - STL Containers
// 2019/10/25 - Cornel

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iostream>
#include <string>
#include "Car.h"

namespace sdds
{
	class Racecar : public Car
	{
		double m_booster;
	public:
		Racecar(std::istream& in);
		void display(std::ostream& out) const;
		double topSpeed() const;
	};
}

#endif
