// Name: DUC TRONG PHAM
// Seneca Student ID: 126647189
// Seneca email: dtpham2@myseneca.ca
// Date of completion: December 1, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>
#include <iomanip>
#include "Item.h"
#include "Utilities.h"
using namespace std;
size_t Item::m_widthField=1;
Item::Item(const std::string& str) {
		Utilities u;
		bool flag;
		size_t pos = 0;
		m_name = u.extractToken(str, pos, flag);
		if (flag)
			m_widthField = u.getFieldWidth();
		if (flag)
			m_serialNumber = stoi(u.extractToken(str, pos, flag));
		if (flag)
			m_quantity= stoi(u.extractToken(str, pos, flag));
		if (flag)
			m_description= u.extractToken(str, pos, flag);
}
const std::string& Item::getName() const {
	return m_name;
}
const unsigned int Item::getSerialNumber() {
	return m_serialNumber++;
}
const unsigned int Item::getQuantity() {
	return m_quantity;
}
void Item::updateQuantity() {
	if (m_quantity > 0)
		m_quantity--;
}
void Item::display(std::ostream& os, bool full) const {
	if (!full) {
		os << setw(m_widthField) << left << m_name << " [" << right << setw(6) << setfill('0') << m_serialNumber << setfill(' ') << "]" << endl;
	}
	else {
		os << setw(m_widthField) << left << m_name << " [" << right << setw(6) << setfill('0') << m_serialNumber << setfill(' ') << "] Quantity: " << setw(m_widthField) << left << m_quantity
			<< " Description: " << m_description << endl;
	}
}