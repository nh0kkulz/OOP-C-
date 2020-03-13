// Name: DUC TRONG PHAM
// Seneca Student ID: 126647189
// Seneca email: dtpham2@myseneca.ca
// Date of completion: December 1, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Item.h"
using namespace std;
size_t CustomerOrder::m_widthField = 1;
CustomerOrder::CustomerOrder() {
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;
}
CustomerOrder::CustomerOrder(string& record) {
	Utilities u;
	bool flag;
	size_t pos = 0;
	m_name = u.extractToken(record, pos, flag);
	if (flag)
		m_product = u.extractToken(record, pos, flag);
	if (flag) {
		m_cntItem = count(record.begin(), record.end(), u.getDelimiter()) - 1;
		m_lstItem = new ItemInfo*[m_cntItem];
		for (size_t i = 0u; i < m_cntItem; i++) {
			m_lstItem[i] = new ItemInfo(u.extractToken(record, pos, flag));
		}
		if (m_widthField < u.getFieldWidth())
			m_widthField = u.getFieldWidth();
	}
}
CustomerOrder::CustomerOrder(const CustomerOrder& o) {
	throw "Error";
}
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& o) {
	if (this != &o) {
		if (m_lstItem != nullptr) {
			for (size_t i = 0u; i < m_cntItem; i++)
				delete m_lstItem[i];
			delete[] m_lstItem;
		}
		m_name = o.m_name;
		m_product = o.m_product;
		m_cntItem = o.m_cntItem;
		m_lstItem = o.m_lstItem;
		o.m_name = "";
		o.m_product = "";
		o.m_cntItem = 0;
		o.m_lstItem = nullptr;
	}
	return *this;
}
CustomerOrder::CustomerOrder(CustomerOrder&& o) noexcept {
	m_lstItem = nullptr;
	*this = std::move(o);
}
CustomerOrder::~CustomerOrder() {
	for (size_t i = 0u; i < m_cntItem; i++)
		delete m_lstItem[i];
	delete[] m_lstItem;
	m_lstItem = nullptr;
}
bool CustomerOrder::getItemFillState(std::string str) const {
	for (size_t i = 0; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == str) {
			return m_lstItem[i]->m_fillState;
		}
	}
	return true;
}
bool CustomerOrder::getOrderFillState() const {
	for (size_t i = 0u; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_fillState == false)
			return false;
	}
	return true;
}
void CustomerOrder::fillItem(Item& item, std::ostream& os) {
	for (size_t i = 0u; i < m_cntItem; i++) {
		if (item.getName() == m_lstItem[i]->m_itemName) {
			if (item.getQuantity() >= 1) {
				item.updateQuantity();
				m_lstItem[i]->m_serialNumber = item.getSerialNumber();
				m_lstItem[i]->m_fillState = true;
				os << "Filled " << m_name << "," << m_product << "[" << m_lstItem[i]->m_itemName << "]" << endl;
			}
			else {
				os << "Unable to fill " << m_name << "," << m_product << "[" << m_lstItem[i]->m_itemName << "]" << endl;
			}
		}
	}
}
void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << endl;
	for (size_t i = 0u; i < m_cntItem; i++) {
		os << "[" << right << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << left << setfill(' ') << "] " << setw(m_widthField) << m_lstItem[i]->m_itemName << " - "
			<< (m_lstItem[i]->m_fillState == true ? "FILLED" : "MISSING") << endl;
	}
}