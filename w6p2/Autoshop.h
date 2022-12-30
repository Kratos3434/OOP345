/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include "Vehicle.h"
#include "Luxuryvan.h"
#include <iostream>
#include <list>

namespace sdds {
    class Autoshop {
	  std::vector<Vehicle*> m_vehicles;
	  //std::vector<Luxuryvan*> m_lvehicles;

    public:
	  ~Autoshop();
	  Autoshop& operator+=(Vehicle* theVehicle);
	  void display(std::ostream& out) const;

	  template <typename T>
	  void select(T test, std::list<const Vehicle*>& vehicles);
    };

    template <typename T>
    void Autoshop::select(T test, std::list<const Vehicle*>& vehicles) {
	  for (size_t i = 0; i < m_vehicles.size(); i++) {
		if (test(m_vehicles[i])) {
		    vehicles.push_back(m_vehicles[i]);
		}
	  }
    }

}
#endif // !SDDS_AUTOSHOP_H
