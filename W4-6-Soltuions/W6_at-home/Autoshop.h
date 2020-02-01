// Workshop 6 - STL Containers
// 2019/10/25 - Cornel

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <vector>
#include <list>
#include <iostream>
#include "Vehicle.h"

namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop() = default;
		~Autoshop();
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;

		template<typename T>
		void select(T condition, std::list<const Vehicle*>& vehicles)
		{
			for (auto it = m_vehicles.begin(); it != m_vehicles.end(); ++it)
			{
				if (condition(*it))
					vehicles.push_back(*it);
			}
		}
	};
}

#endif
