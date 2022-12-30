/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H

#include <string>
#include <iostream>

namespace sdds {
    class Reservation {
	  std::string m_resID{};
	  std::string m_resName{};
	  std::string m_email{};
	  int m_numPeople{};
	  int m_day{};//1-28
	  int m_hour{};//1-24
    public:
	  Reservation();
	  ~Reservation(){}
	  void update(int day, int time);
	  Reservation(const std::string& res);
	  std::ostream& display(std::ostream& os) const;
	  bool operator==(const Reservation& res) const;
    };
    std::ostream& operator<<(std::ostream& os, const Reservation& res);
    std::string& trim(std::string& val, int len);
}
#endif // !SDDS_RESERVATION_H
