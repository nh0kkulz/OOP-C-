// DUC TRONG PHAM
// 126647189
// dtpham2@myseneca.ca
#include "Account.h"
#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H
namespace sict {
	class SavingsAccount : public Account {
		double interest;
	public:
		SavingsAccount(double, double);
		void monthEnd();
		void display(std::ostream&) const;
	};
}
#endif
