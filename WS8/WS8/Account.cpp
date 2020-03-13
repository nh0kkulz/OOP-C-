// DUC TRONG PHAM
// 126647189
// dtpham2@myseneca.ca
#include <iostream>
#include "Account.h"
using namespace std;
namespace sict {
	Account::Account(double d) {
		if (d > 0) {
			currentbalance = d;
		}
		else {
			currentbalance = 0.0;
		}
	}
	bool Account::credit(double amount) {
		if (amount > 0) {
			currentbalance += amount;
			return true;
		}
		else {
			return false;
		}
	}
	bool Account::debit(double amount) {
		if (amount > 0) {
			currentbalance -= amount;
			return true;
		}
		else {
			return false;
		}
	}
	double Account::balance() const {
		return currentbalance;
	}
}