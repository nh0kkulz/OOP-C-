// Name: DUC TRONG PHAM
// Seneca Student ID: 126647189
// Seneca email: dtpham2@myseneca.ca
// Date of completion: December 1, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef UTILITIES_H
#define UTILITIES_H
class Utilities {
	size_t m_widthField;
	static char m_delimeter;
public:
	Utilities();
	void setFieldWidth(size_t);
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(const char c);
	const char getDelimiter() const;
};
#endif