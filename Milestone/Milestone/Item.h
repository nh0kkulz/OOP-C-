// Name: DUC TRONG PHAM
// Seneca Student ID: 126647189
// Seneca email: dtpham2@myseneca.ca
// Date of completion: December 1, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
class Item {
	std::string m_name;
	std::string m_description;
	int m_serialNumber;
	int m_quantity;
	static size_t m_widthField;
public:
	const std::string& getName() const;
	const unsigned int getSerialNumber();
	void updateQuantity();
	const unsigned int getQuantity();
	void display(std::ostream& os, bool full) const;
	Item(const std::string&);
};
#endif