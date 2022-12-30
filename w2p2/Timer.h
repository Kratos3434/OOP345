/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H

#include <chrono>
namespace sdds {
    class Timer {
	  std::chrono::time_point<std::chrono::system_clock> m_startTime{};
	  std::chrono::time_point<std::chrono::system_clock> m_endTime{};
    public:
	  void start();
	  long long stop();
    };
}
#endif // !SDDS_TIMER_H
