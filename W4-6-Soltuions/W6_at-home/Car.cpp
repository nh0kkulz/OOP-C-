// Workshop 6 - STL Containers
// 2019/10/25 - Cornel

#include <string>
#include <iostream>
#include <iomanip>
#include "Car.h"

namespace sdds
{
	std::string& Car::trim(std::string& token)
	{
		while (token.length() > 0 && token[0] == ' ')
			token.erase(0, 1);
		while (token.length() > 0 && token[token.length() - 1] == ' ')
			token.erase(token.length() - 1, 1);
		return token;
	}
	Car::Car(std::istream& in)
	{
		std::string token;

		std::getline(in, token, ',');
		m_model = trim(token);

		std::getline(in, token, ',');
		trim(token);
		if (token == "" || token == "n")
			m_condition = "new";
		else if (token == "b")
			m_condition = "broken";
		else if (token == "u")
			m_condition = "used";
		else
			throw "Invalid record!";

		std::getline(in, token, ',');
		try
		{
			m_topSpeed = std::stoi(trim(token));
		}
		catch (...)
		{
			throw "Invalid record!";
		}
	}
	std::string Car::condition() const
	{
		return m_condition;
	}
	double Car::topSpeed() const
	{
		return m_topSpeed;
	}
	void Car::display(std::ostream& out) const
	{
		out << "| " << std::setw(10) << m_model
			<< " | " << std::setw(6) << std::left << this->condition()
			<< " | " << std::setw(6) << std::setprecision(2) << std::fixed << std::right << this->topSpeed() << " |";
	}
}
