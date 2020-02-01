// Name: DUC TRONG PHAM
// Seneca Student ID: 126647189
// Seneca email: dtpham2@myseneca.ca
// Date of completion: September 19, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef TEXT_H
#define TEXT_H
#include <iostream>
using namespace std;
namespace sdds
{
	class Text {
		string* line;
		int n;
	public:
		Text();
		Text(const string&);
		Text(const Text&);
		Text(Text&&);
		Text& operator=(const Text&);
		Text& operator=(Text&&);
		~Text();
		size_t size() const;
	};
}
#endif
