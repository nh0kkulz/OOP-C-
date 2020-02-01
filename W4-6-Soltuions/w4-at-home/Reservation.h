// Workshop 4 - Containers
// 2019/09/27 - Cornel

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <string>
#include <ostream>

namespace sdds
{
	class Reservation
	{
		std::string m_id = "";
		std::string m_name = "";
		std::string m_email = "";
		size_t m_partysize = 0;
		size_t m_day = 0;
		size_t m_time = 0;

		void trim(std::string& str) const;
	public:
		Reservation() {}
		Reservation(const std::string& m_res);
		friend std::ostream& operator<<(std::ostream& out, const Reservation& res);
	};
}
#endif