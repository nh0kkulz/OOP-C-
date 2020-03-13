// DUC TRONG PHAM
// 126647189
// dtpham2@myseneca.ca
#include "iAccount.h"
#ifndef ACCOUNT_H
#define ACCOUNT_H
namespace sict {
	class Account : public iAccount {
		double currentbalance;
	public:
		Account(double);
		bool credit(double);
		bool debit(double);
	protected:
		double balance() const;
	};
}
#endif
