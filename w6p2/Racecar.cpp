/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include "Racecar.h"

namespace sdds {
    Racecar::Racecar(std::istream& in):Car(in) {
	  in.ignore();
	  in >> m_booster;
    }
    void Racecar::display(std::ostream& out) const {
	  Car::display(out);

	  out << "*";
    }
    double Racecar::topSpeed() const {
	  double topSpeed = Car::topSpeed() + (Car::topSpeed() * m_booster);
	  return topSpeed;
    }
}