/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/


#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H

#include "Reservation.h"
#include <iostream>

namespace sdds {
    class Restaurant {
	  Reservation** m_res{};
	  int m_numReservations{0};
    public:
	  Restaurant(const Reservation* reservations[], size_t cnt);
	  //copy
	  Restaurant(const Restaurant& res);
	  Restaurant& operator=(const Restaurant& res);
	  ~Restaurant();
	  //move
	  Restaurant(Restaurant&& res);
	  Restaurant& operator=(Restaurant&& res);
	  size_t size();
	  std::ostream& display(std::ostream& os) const;
    };
    std::ostream& operator<<(std::ostream& os, const Restaurant& res);
}
#endif // !SDDS_RESTAURANT_H
