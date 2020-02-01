// Workshop 5 - Functions and Error Handling
// 2019/10 - Cornel

#include <ostream>
#include <iomanip>
#include "Movie.h"

namespace sdds
{
	void Movie::trim(std::string& str) const
	{
		size_t i = 0u;
		for (i = 0u; i < str.length() && str[i] == ' '; ++i);
		str = str.substr(i);

		for (i = str.length(); i > 0 && str[i - 1] == ' '; --i);
		str = str.substr(0, i);
	}

	Movie::Movie(const std::string strMovie)
	{
		size_t posS = 0;
		size_t posE = strMovie.find(',');
		this->trim(m_title = strMovie.substr(posS, posE - posS));

		posS = posE + 1;
		posE = strMovie.find(',', posS);
		m_year = std::stoi(strMovie.substr(posS, posE - posS));

		posS = posE + 1;
		this->trim(m_description = strMovie.substr(posS));
	}


	std::ostream& operator<<(std::ostream& out, const Movie& theMovie)
	{
		out << std::setw(40) << theMovie.m_title << " | "
			<< std::setw(4) << theMovie.m_year << " | "
			<< theMovie.m_description << "\n";
		return out;
	}
}