// Workshop 2 - Copy and Move Semantics
// Timekeeper.h
// 2019/01/10 - Chris Szalwinski
// 2019/09/13 - Cornel
// Name: DUC TRONG PHAM
// Seneca Student ID: 126647189
// Seneca email: dtpham2@myseneca.ca
// Date of completion: September 19, 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.
#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H

#include <iostream>
#include <chrono>
#include <string>

namespace sdds {
	const int MAX_RECORDS = 7;
	class TimedEvents {
		int nr {0};
		std::chrono::steady_clock::time_point ts;
		std::chrono::steady_clock::time_point te;
		struct {
			std::string msg;
			std::string units;
			std::chrono::steady_clock::duration duration;
		} events[MAX_RECORDS];
	public:
		void startClock();
		void stopClock();
		void recordEvent(const char*);
		friend std::ostream& operator<<(std::ostream& out, const TimedEvents& events);
	};
}
#endif
