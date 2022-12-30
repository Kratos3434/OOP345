// Name: Keith Carlos
// Seneca Student ID: 127638211
// Seneca email: kwcarlos@myseneca.ca
// Date of completion: 2022-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include "CustomerOrder.h"
#include <exception>
#include <string>
#include <iostream>
#include "Station.h"
#include <deque>

//Globals
extern std::deque<sdds::CustomerOrder> g_pending;
extern std::deque<sdds::CustomerOrder> g_completed;
extern std::deque<sdds::CustomerOrder> g_incomplete;

namespace sdds {
    class Workstation:public Station {
	  std::deque<CustomerOrder> m_orders{};
	  Workstation* m_pNextStation{ nullptr };
    public:
	  Workstation(const std::string& val);
	  //delete move and copy operators
	  Workstation(const Workstation&) = delete;
	  Workstation& operator=(const Workstation&) { throw std::exception(); }
	  Workstation(Workstation&&) = delete;
	  Workstation& operator=(Workstation&&) { throw std::exception(); }

	  void fill(std::ostream& os);
	  bool attemptToMoveOrder();
	  void setNextStation(Workstation* station = nullptr);
	  Workstation* getNextStation() const;
	  void display(std::ostream& os) const;
	  Workstation& operator+=(CustomerOrder&& newOrder);

    };
}

#endif // !SDDS_WORKSTATION_H
