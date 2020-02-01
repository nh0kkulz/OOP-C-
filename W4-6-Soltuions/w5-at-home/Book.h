// Workshop 5 - Functions and Error Handling
// 2019/10 - Cornel

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <ostream>
#include <string>

namespace sdds
{
	class Book
	{
		std::string m_author;
		std::string m_title;
		std::string m_country;
		std::string m_description;
		double      m_price = 0;
		size_t      m_year = 0;
		void trim(std::string& str) const;
	public:
		Book() {}
		Book(const std::string strBook);

		const std::string& title() const { return m_title; }
		const std::string& country() const { return m_country; }
		const size_t& year() const { return m_year; }
		double& price() { return m_price; }

		template<typename T>
		void fixSpelling(T spellChecker)
		{
			spellChecker(m_description);
		}
		friend std::ostream& operator<<(std::ostream& out, const Book& theBook);
	};
}
#endif