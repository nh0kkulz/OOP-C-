// Workshop 5 - Functions and Error Handling
// 2019/10 - Cornel

#include <fstream>
#include "SpellChecker.h"

namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream file(filename);
		if (file.is_open() == false)
			throw "Bad file name!";

		for (size_t i = 0u; i < sizeof(m_badWords) / sizeof(m_badWords[0]); ++i)
		{
			file >> m_badWords[i];
			file >> m_goodWords[i];
		}
	}
	void SpellChecker::operator()(std::string& text) const
	{
		for (auto i = 0u; i < sizeof(m_badWords) / sizeof(m_badWords[0]); ++i)
		{
			size_t pos = text.find(m_badWords[i]);
			while (pos != std::string::npos)
			{
				text.replace(pos, m_badWords[i].size(), m_goodWords[i]);
				pos = text.find(m_badWords[i]);
			}
		}
	}
}