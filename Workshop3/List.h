// Name: DUC TRONG PHAM
// Seneca Student ID: 126647189
// Seneca email: dtpham2@myseneca.ca
// Date of completion: October 1, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef LIST_H
#define LIST_H
#include <cstddef>
#include "LVPair.h"
namespace sdds {
	template <typename T, size_t N>
	class List {
		T listarray[N];
		size_t noe=0;
	public:
		size_t size() const {
			return noe;
		}
		const T& operator[](size_t i) const {
			return listarray[i];
		}
		void operator+=(const T& tt) {
			if (noe < N) {
				listarray[noe] = tt;
				noe += 1;
			}
		}
	};
	template <typename L, typename V, typename T, unsigned N>
	class LVList : public List<T, N> {
	public:
		V accumulate(const L& label) const {
			SummableLVPair<L, V> obj;
			V accumulator = obj.getInitialValue();
			for (unsigned i = 0; i < (*this).size(); i++) {
				if (label == (*this)[i].key())
					accumulator = (*this)[i].sum(label, accumulator);
			}
			return accumulator;
		}
	};
}
#endif