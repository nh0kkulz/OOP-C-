// Workshop 6 - STL Containers
// 2019/10/25 - Cornel

#include <vector>
#include <list>
#include <iostream>
#include "Vehicle.h"
#include "Autoshop.h"
#include "Utilities.h"

namespace sdds
{
	Autoshop::~Autoshop()
	{
		while (!m_vehicles.empty())
		{
			delete m_vehicles.back();
			m_vehicles.pop_back();
		}
	}
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";
		for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it)
		{
			(*it)->display(out);
			out << std::endl;
		}
		out << "--------------------------------\n";
	}
}
