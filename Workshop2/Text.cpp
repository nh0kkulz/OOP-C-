// Name: DUC TRONG PHAM
// Seneca Student ID: 126647189
// Seneca email: dtpham2@myseneca.ca
// Date of completion: September 19, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include "Text.h"
using namespace std;
namespace sdds
{
	Text::Text() {
		n = 0;
		line = nullptr;
	}
	Text::Text(const string& filename) {
		ifstream f(filename.c_str());
		n = 0;
		line = nullptr;
		if (!f)
			return;
		do
		{
			char c = f.get();
			if (c == ' ') n++;
		} while (!f.eof());
		f.seekg(std::ios::beg);
		line = new string[n];
		for (int i = 0; i < n; i++)
			getline(f, line[i], ' ');
	}
	Text::Text(const Text& src) {
		line = nullptr;
		*this = src;
	}
	Text& Text::operator=(const Text& src) {
		if (this != &src) {
			n = src.n;
			delete[] line;
			if (src.line != nullptr) {
				line = new string[n];
				for (int i = 0; i < n; i++)
					line[i] = src.line[i];
			}
		}
		else {
			line = nullptr;
		}
		return *this;
	}
	Text::Text(Text&& src) {
		line = nullptr;
		*this = move(src);
	}
	Text& Text::operator=(Text&& src) {
		if (this != &src) {
			delete[] line;
			n = src.n;
			line = src.line;
			src.line = nullptr;
			src.n = 0;
		}
		return *this;
	}
	Text::~Text() {
		delete[] line;
	}
	size_t Text::size() const {
		return n;
	}
}