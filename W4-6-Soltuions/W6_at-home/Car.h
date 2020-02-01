// Workshop 6 - STL Containers
// 2019/10/25 - Cornel

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <string>
#include <iostream>
#include <iomanip>
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		std::string m_model;
		std::string m_condition;
		int m_topSpeed;
	protected:
		std::string& trim(std::string& token);
	public:
		Car(std::istream& in);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}

#endif
