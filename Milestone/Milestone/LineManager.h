// Name: DUC TRONG PHAM
// Seneca Student ID: 126647189
// Seneca email: dtpham2@myseneca.ca
// Date of completion: December 1, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef LINE_MANAGER_H
#define LINE_MANAGER_H
#include <vector>
#include <iostream>
#include <deque>
#include "Task.h"
class LineManager {
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;
	Task* First;
	Task* Last;
public:
	LineManager(const std::string& str, vector<Task*>& t, vector<CustomerOrder>& c);
	bool run(std::ostream&);
	void displayCompleted(std::ostream&) const;
	void validateTasks() const;
};
#endif