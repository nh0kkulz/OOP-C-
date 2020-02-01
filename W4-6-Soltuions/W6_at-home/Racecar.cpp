// Workshop 6 - STL Containers
// 2019/10/25 - Cornel

#include <iostream>
#include <string>
#include "Racecar.h"

namespace sdds
{
	Racecar::Racecar(std::istream& in) : Car(in)
	{
		std::string token;
		std::getline(in, token, ',');
		m_booster = std::stod(trim(token));
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}
	double Racecar::topSpeed() const
	{
		return Car::topSpeed() * (1 + m_booster);
	}
}
