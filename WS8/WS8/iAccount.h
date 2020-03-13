// DUC TRONG PHAM
// 126647189
// dtpham2@myseneca.ca#ifndef IACCOUNT_H
#ifndef IACCOUNT_H
#define IACCOUNT_H
#include <iostream>
namespace sict {
	class iAccount {
	public:
		virtual ~iAccount() {};
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual void display(std::ostream&) const = 0;
	};
	iAccount* CreateAccount(const char*, double);
}
#endif
