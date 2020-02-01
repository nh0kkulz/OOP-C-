// Workshop 5 - Functions and Error Handling
// 2019/10 - Cornel

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <ostream>
#include <string>

namespace sdds
{
	class Movie
	{
		std::string m_title;
		size_t m_year;
		std::string m_description;
		void trim(std::string& str) const;
	public:
		Movie() :m_year{ 0 } {};
		Movie(const std::string strMovie);

		const std::string& title() const { return m_title; };

		template<typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_description);
		}

		friend std::ostream& operator<<(std::ostream& out, const Movie& theMovie);
	};
}
#endif