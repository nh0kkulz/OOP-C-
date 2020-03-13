// Name: DUC TRONG PHAM
// Seneca Student ID: 126647189
// Seneca email: dtpham2@myseneca.ca
// Date of completion: December 1, 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"
using namespace std;
LineManager::LineManager(const std::string& str, vector<Task*>& t, vector<CustomerOrder>& c) {
	fstream f(str);
	if (!f)
		throw std::string("Unable to open [") + str + "] file.";
	vector<Task*>nextT;
	while (!f.eof()) {
		Utilities u;
		bool flag;
		size_t pos = 0;
		string buffer;
		getline(f, buffer);
		string current = u.extractToken(buffer, pos, flag);
		auto ctask = find_if(t.begin(), t.end(), [&](Task* task) {
			return task->getName() == current;
		});
		if (flag) {
			string next = u.extractToken(buffer, pos, flag);
			auto ntask = find_if(t.begin(), t.end(), [&](Task* task) {
				return task->getName() == next;
			});
			(*ctask)->setNextTask(**ntask);
			nextT.push_back(*ntask);
		}
		Last = *ctask;
	}
	bool found = true;
	for (auto task : t) {
		AssemblyLine.push_back(task);
		if (found&&nextT.end() == find(nextT.begin(), nextT.end(), task)) {
			First = task;
		}
	}
	for (auto& i : c)
		ToBeFilled.push_front(move(i));
}
bool LineManager::run(std::ostream& os) {
	bool flag = true;
	if (!ToBeFilled.empty()) {
		*First += std::move(ToBeFilled.back());
		ToBeFilled.pop_back();
	}
	for (auto task : AssemblyLine)
		task->runProcess(os);
	CustomerOrder filled_order;
	if (Last->getCompleted(filled_order))
		Completed.push_back(std::move(filled_order));
	for (auto task : AssemblyLine) {
		if (task->moveTask())
			flag = false;
	}
	return flag;
}
void LineManager::displayCompleted(std::ostream& os) const {
	for (auto& order : Completed)
		order.display(os);
}
void LineManager::validateTasks() const {
	for (auto& task : AssemblyLine)
		task->validate(std::cout);

}