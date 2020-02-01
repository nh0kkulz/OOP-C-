// Workshop 4 - Containers
// 2019/09/27 - Cornel

#include "Restaurant.h"

namespace sdds
{
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
	{
		this->m_reservations = new Reservation[cnt];
		this->m_cnt = cnt;
		for (auto i = 0u; i < cnt; ++i)
			this->m_reservations[i] = *reservations[i];
	}
	Restaurant::Restaurant(const Restaurant& other)
	{
		*this = other;
	}
	Restaurant& Restaurant::operator=(const Restaurant& other)
	{
		if (this != &other)
		{
			m_currentDay = other.m_currentDay;
			m_cnt = other.m_cnt;

			delete[] this->m_reservations;
			this->m_reservations = new Reservation[m_cnt];
			for (auto i = 0u; i < m_cnt; ++i)
				this->m_reservations[i] = other.m_reservations[i];
		}
		return *this;
	}
	Restaurant::Restaurant(Restaurant&& other) noexcept
	{
		*this = std::move(other);
	}
	Restaurant& Restaurant::operator=(Restaurant&& other) noexcept
	{
		if (this != &other)
		{
			m_currentDay = other.m_currentDay;
			m_cnt = other.m_cnt;

			delete[] this->m_reservations;
			this->m_reservations = other.m_reservations;
			other.m_currentDay = 0;
			other.m_cnt = 0;
			other.m_reservations = nullptr;
		}
		return *this;
	}
	Restaurant::~Restaurant()
	{
		delete[] m_reservations;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& res)
	{
		os << "--------------------------\n";
		os << "Fancy Restaurant\n";
		os << "--------------------------\n";
		if (res.m_cnt == 0)
			os << "The object is empty!\n";
		for (auto i = 0u; i < res.m_cnt; ++i)
			os << res.m_reservations[i];
		os << "--------------------------\n";
		return os;
	}
}