/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H

#include "Car.h"

namespace sdds {
    class Racecar:public Car {
	  double m_booster{0.0};
    public:
	  Racecar() {};
	  Racecar(std::istream& in);
	  ~Racecar() {};
	  void display(std::ostream& out) const;
	  double topSpeed() const;
    };
}


#endif //!SDDS_RACECAR_H