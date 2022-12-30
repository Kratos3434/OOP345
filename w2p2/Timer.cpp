/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include "Timer.h"

namespace sdds {
    void Timer::start() {
	  m_startTime = std::chrono::system_clock::now();
    }

    long long Timer::stop() {
	  m_endTime = std::chrono::system_clock::now();

	  return std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime).count();
    }
}