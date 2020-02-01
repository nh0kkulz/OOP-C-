// Workshop 4 - Containers
// 2019/09/27 - Cornel

#include <utility>
#include "ConfirmationSender.h"
namespace sdds
{
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& other)
	{
		*this = other;
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& other)
	{
		if (this != &other)
		{
			this->m_cnt = other.m_cnt;
			delete[] this->m_reservations;

			this->m_reservations = new const Reservation*[m_cnt];
			for (auto i = 0u; i < m_cnt; ++i)
				this->m_reservations[i] = other.m_reservations[i];
		}
		return *this;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& other) noexcept
	{
		*this = std::move(other);
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& other) noexcept
	{
		if (this != &other)
		{
			this->m_cnt = other.m_cnt;
			delete[] this->m_reservations;

			this->m_reservations = other.m_reservations;
			other.m_reservations = nullptr;
			other.m_cnt = 0;
		}
		return *this;
	}

	ConfirmationSender::~ConfirmationSender()
	{
		delete[] m_reservations;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool found = false;
		for (auto i = 0u; i < m_cnt && found == false; ++i)
			if (&res == m_reservations[i])
				found = true;

		if (found == false)
		{
			// resize & add
			const sdds::Reservation** tmp = nullptr;
			tmp = new const Reservation * [m_cnt + 1];
			for (auto i = 0u; i < m_cnt; ++i)
				tmp[i] = m_reservations[i];
			tmp[m_cnt] = &res;

			++m_cnt;
			delete[] m_reservations;
			m_reservations = tmp;
		}

		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		for (auto i = 0u; i < m_cnt; ++i)
			if (&res == m_reservations[i])
				m_reservations[i] = nullptr;

		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& sender)
	{
		os << "--------------------------\n";
		os << "Confirmations to Send\n";
		os << "--------------------------\n";
		if (sender.m_cnt == 0)
			os << "The object is empty!\n";
		for (auto i = 0u; i < sender.m_cnt; ++i)
			if (sender.m_reservations[i] != nullptr)
				os << *(sender.m_reservations[i]);
		os << "--------------------------\n";
		return os;
	}
}
