/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include "Luxuryvan.h"
#include "Car.h"
namespace sdds {
    Luxuryvan::Luxuryvan(std::istream& in):Van(in) {
	  in.ignore();
	  std::string consumption;
	  getline(in, consumption);
	  consumption = trim(consumption, (int)consumption.length());
	  if (consumption == "g") {
		throw "Invalid record!";
	  }
	  m_consumption = consumption;
	  //std::cout << m_consumption << std::endl;
    }
    void Luxuryvan::display(std::ostream& out) const {
	  Van::display(out);
	  out << " electric van  *";
    }
    std::string Luxuryvan::consumption() const {
	  return m_consumption;
    }
}