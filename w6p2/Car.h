/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
    class Car : public Vehicle {
	  std::string m_tag{};
	  std::string m_maker{};
	  std::string m_condition{};
	  int m_topSpeed{ 0 };

    public:
	  Car() {};
	  Car(std::istream& is);
	  ~Car() {};
	  std::string condition() const;
	  double topSpeed() const;
	  void display(std::ostream& out) const;
    };
    std::string& trim(std::string& val, int len);
}
#endif // !SDDS_CAR_H
