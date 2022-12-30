/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/


#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H

#include "Reservation.h"
#include <iostream>
namespace sdds {
    class ConfirmationSender {
	  const Reservation** m_res{};
	  int m_numRes{ 0 };
    public:
	  ConfirmationSender();
	  //copy
	  ConfirmationSender(const ConfirmationSender& cs);
	  ConfirmationSender& operator=(const ConfirmationSender& cs);
	  //move
	  ConfirmationSender(ConfirmationSender&& cs);
	  ConfirmationSender& operator=(ConfirmationSender&& cs);
	  ~ConfirmationSender();
	  ConfirmationSender& operator+=(const Reservation& res);
	  ConfirmationSender& operator-=(const Reservation& res);
	  bool isExist(const Reservation& res);

	  std::ostream& display(std::ostream& os) const;
    };
    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs);
}
#endif // !SDDS_CONFIRMATIONSENDER_H
