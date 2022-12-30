/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_LUXURYVAN_H
#define SDDS_LUXURYVAN_H

#include <string>
#include <iostream>
#include "Van.h"

namespace sdds {
    class Luxuryvan:public Van {
	  std::string m_consumption;
    public:
	  Luxuryvan() {};
	  Luxuryvan(std::istream& in);
	  ~Luxuryvan() {};
	  void display(std::ostream& out) const;
	  std::string consumption() const;

    };
}
#endif // !SDDS_LUXURYVAN_H
