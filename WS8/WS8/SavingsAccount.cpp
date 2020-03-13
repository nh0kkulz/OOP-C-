// DUC TRONG PHAM
// 126647189
// dtpham2@myseneca.ca
#include <iostream>
#include "SavingsAccount.h"
using namespace std;
namespace sict {
	SavingsAccount::SavingsAccount(double initial, double rate) : Account(initial){
		if (rate > 0) {
			interest = rate;
		}
		else {
			interest = 0.0;
		}
	}
	void SavingsAccount::monthEnd() {
		double money = balance() * interest;
	}
	void SavingsAccount::display(ostream& os) const {
		os.setf(ios::fixed);
		os.precision(2);
		os << "Account type: Savings" << endl;
		os << "Balance: $" << balance() << endl;
		os << "Interest Rate (%): " << interest * 100 << endl;
	}
}