// Name: DUC TRONG PHAM
// Seneca Student ID: 126647189
// Seneca email: dtpham2@myseneca.ca
// Date of completion: December 1, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <deque>
#include "Item.h"
#include "CustomerOrder.h"
using namespace std;
class Task : public Item {
	deque<CustomerOrder> m_orders;
	Task* m_pNextTask;
public:
	Task(const string&);
	Task(const Task& t) = delete;
	Task& operator=(const Task& t) = delete;
	Task(Task&& t) = delete;
	Task& operator=(Task&& t) = delete;
	void runProcess(std::ostream&);
	bool moveTask();
	void setNextTask(Task&);
	bool getCompleted(CustomerOrder&);
	void validate(std::ostream&);
	Task& operator+=(CustomerOrder&&);
};
#endif