/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include "Autoshop.h"
#include <iterator>

namespace sdds {
    Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
	  m_vehicles.push_back(theVehicle);

	  return *this;
    }
    Autoshop::~Autoshop() {
	  for (size_t i = 0; i < m_vehicles.size();i++) {
		delete m_vehicles[i];
	  }
    }
    void Autoshop::display(std::ostream& out) const {
	  for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++) {
		(*it)->display(out);
		out << std::endl; 
	  }
		
    }
}