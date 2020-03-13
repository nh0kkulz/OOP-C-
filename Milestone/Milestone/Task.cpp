// Name: DUC TRONG PHAM
// Seneca Student ID: 126647189
// Seneca email: dtpham2@myseneca.ca
// Date of completion: December 1, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>
#include "Task.h"
using namespace std;
Task::Task(const string& str) : Item(str) {
	m_pNextTask = nullptr;
}
void Task::runProcess(std::ostream& os) {
	if (!m_orders.empty()) {
		if (m_orders.back().getOrderFillState() == false)
			m_orders.back().fillItem(*this, os);
	}
}
bool Task::moveTask() {
	if (m_orders.empty())
		return false;
	else
		if (m_orders.back().getItemFillState(getName()))
		{
			if (m_pNextTask != nullptr) {
				*m_pNextTask += move(m_orders.back());
				m_orders.pop_back();
			}
			
		}
	return true;
}
void Task::setNextTask(Task& t) {
	m_pNextTask = &t;
}
bool Task::getCompleted(CustomerOrder& c) {
	if (!m_orders.empty()) {
		c = move(m_orders.back());
		m_orders.pop_back();
		return true;
	}
	else {
		return false;
	}
}
void Task::validate(std::ostream& os) {
	if (m_pNextTask == nullptr)
		os << getName() << " --> END OF LINE" << endl;
	else
		os << getName() << " --> " << m_pNextTask->getName() << endl;
}
Task& Task::operator+=(CustomerOrder&& c) {
	m_orders.push_front(move(c));
	return *this;
}