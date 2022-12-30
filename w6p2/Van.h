/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_VAN_H
#define SDDS_VAN_H

#include "Vehicle.h"
#include <iostream>
#include <string>

namespace sdds {
    class Van :public Vehicle {
	  std::string m_tag{};
	  std::string m_maker{};
	  std::string m_type{};
	  std::string m_purpose{};
	  std::string m_condition{};
	  int m_topSpeed{ 0 };

    public:
	  Van() {};
	  Van(std::istream& is);
	  ~Van() {};
	  std::string condition() const;
	  double topSpeed() const;
	  std::string type() const;
	  std::string usage() const;
	  void display(std::ostream& out) const;

    };
}
#endif // !SDDS_VAN_H
