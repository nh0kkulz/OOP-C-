// Workshop 5 - Functions and Error Handling
// 2019/10 - Cornel

#include <iomanip>
#include "Book.h"

namespace sdds
{
	void Book::trim(std::string& str) const
	{
		size_t i = 0u;
		for (i = 0u; i < str.length() && str[i] == ' '; ++i);
		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
		str = str.substr(0, i);
	}

	Book::Book(const std::string strBook)
	{
		size_t posS = 0;
		size_t posE = strBook.find(',');
		this->trim(m_author = strBook.substr(posS, posE - posS));

		posS = posE + 1;
		posE = strBook.find(',', posS);
		this->trim(m_title = strBook.substr(posS, posE - posS));

		posS = posE + 1;
		posE = strBook.find(',', posS);
		this->trim(m_country = strBook.substr(posS, posE - posS));

		posS = posE + 1;
		posE = strBook.find(',', posS);
		m_price = std::stod(strBook.substr(posS, posE - posS));

		posS = posE + 1;
		posE = strBook.find(',', posS);
		m_year = std::stoi(strBook.substr(posS, posE - posS));

		posS = posE + 1;
		this->trim(m_description = strBook.substr(posS));
	}

	std::ostream& operator<<(std::ostream& out, const Book& theBook)
	{
		out << std::setw(20) << theBook.m_author << " | "
			<< std::setw(22) << theBook.m_title << " | "
			<< std::setw(5) << theBook.m_country << " | "
			<< std::setw(4) << theBook.m_year << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << theBook.m_price << " | "
			<< theBook.m_description << "\n";
		return out;
	}
}