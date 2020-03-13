// DUC TRONG PHAM
// 126647189
// dtpham2@myseneca.ca
#include "iAccount.h"
#include "SavingsAccount.h"
namespace sict {
	const double inrate = 0.05;
	iAccount* CreateAccount(const char* string, double initial) {
		iAccount *p = nullptr;
		if (string[0] == 'S') {
			p = new SavingsAccount(initial, inrate);
		}
		else if (string[0] == 'C') {
			p = new SavingsAccount(initial, inrate);
		}
		return p;
	}
}