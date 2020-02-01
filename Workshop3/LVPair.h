// Name: DUC TRONG PHAM
// Seneca Student ID: 126647189
// Seneca email: dtpham2@myseneca.ca
// Date of completion: October 1, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef LVPAIR_H
#define LVPAIR_H
#include <iostream>
#include <iomanip>
#include <cstddef>
namespace sdds {
	template<typename L, typename V>
	class LVPair {
		L m_label;
		V m_value;
	public:
		LVPair() {}
		LVPair(const L& aa, const V& bb) {
			m_label = aa;
			m_value = bb;
		}
		const L& key() const {
			return m_label;
		}
		const V& value() const {
			return m_value;
		}
		virtual void display(std::ostream& os) const {
			os << m_label << " : " << m_value << std::endl;
		}
	};
	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& obj) {
		obj.display(os);
		return os;
	}
	template<typename L, typename V>
	class SummableLVPair : public LVPair<L, V> {
		static V initialvalue;
		static size_t minwidth;
	public:
		static const V& getInitialValue() {
			return initialvalue;
		}
		SummableLVPair() {}
		SummableLVPair(const L& lbl, const V& val) : LVPair<L, V>(lbl, val) {
			if (minwidth < lbl.size()) minwidth = lbl.size();
		}
		V sum(const L& lbl, const V& val) const {
			return LVPair<L, V>::value() + val;
		}
		void display(std::ostream& os) const {
			os << std::left << std::setw(minwidth);
			LVPair<L, V>::display(os);
			os << std::right;
		}
	};
	template<typename L, typename V>
	size_t SummableLVPair<L, V>::minwidth = 0;
	template<>
	std:: string SummableLVPair<std::string, std::string>::initialvalue = "";
	template<>
	int SummableLVPair<std::string, int>::initialvalue = 0;
	template<>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& lbl, const std::string& val) const
	{	
		if (val != "")
			return (val + ", " + LVPair<std::string, std::string>::value());
		else
			return LVPair<std::string, std::string>::value();
	}
}
#endif