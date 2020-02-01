// Workshop 4 - Containers
// 2019/09/27 - Cornel

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <ostream>
#include "Reservation.h"
namespace sdds
{
	// manages a collection of reservations
	// On day change all reservations that are next day
	//   will be sent to the notification system for confirmation.
	class Restaurant
	{
		size_t m_currentDay = 0u;
		Reservation* m_reservations = nullptr;
		size_t m_cnt = 0u;
	public:
		//Restaurant();
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& other);
		Restaurant& operator=(const Restaurant& other);
		Restaurant(Restaurant&& other) noexcept;
		Restaurant& operator=(Restaurant&& other) noexcept;
		~Restaurant();
		size_t size() const { return m_cnt; }

		friend std::ostream& operator<<(std::ostream& os, const Restaurant& res);
	};
}
#endif
