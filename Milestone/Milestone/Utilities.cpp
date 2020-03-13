// Name: DUC TRONG PHAM
// Seneca Student ID: 126647189
// Seneca email: dtpham2@myseneca.ca
// Date of completion: December 1, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include "Utilities.h"
using namespace std;
char Utilities::m_delimeter = '\0';
Utilities::Utilities() : m_widthField(1){}
void Utilities::setFieldWidth(size_t p) {
	m_widthField = p;
}
size_t Utilities::getFieldWidth() const {
	return m_widthField;
}
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	string token = str.substr(next_pos, str.find(m_delimeter, next_pos) - next_pos);
	next_pos = str.find(m_delimeter, next_pos) + 1;
	if (token!=""&&next_pos!=0) {
		more = true;
		m_widthField = m_widthField < token.length() ? token.length() : m_widthField;
	}
	else {
		more = false;
	}
	return token;
}
void Utilities::setDelimiter(const char c) {
	m_delimeter = c;
}
const char Utilities::getDelimiter() const {
	return m_delimeter;
}
