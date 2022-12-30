// Name: Keith Carlos
// Seneca Student ID: 127638211
// Seneca email: kwcarlos@myseneca.ca
// Date of completion: 2022-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Workstation.h"

//Globals
std::deque<sdds::CustomerOrder> g_pending;
std::deque<sdds::CustomerOrder> g_completed;
std::deque<sdds::CustomerOrder> g_incomplete;

namespace sdds {
    Workstation::Workstation(const std::string& val):Station(val) {

    }

    void Workstation::fill(std::ostream& os) {
	  if (!m_orders.empty()) {
		  m_orders.front().fillItem(*this, os);
		//m_orders.front().display(os);
	 }
    }

    bool Workstation::attemptToMoveOrder() {
	  bool orderMoved = false;
	  if (!m_orders.empty()) {
		if (m_orders.front().isItemFilled(getItemName()) || getQuantity() == 0) {
		    if (m_pNextStation != nullptr) {
			  *m_pNextStation += std::move(m_orders.front());
			  m_orders.pop_front();
			  orderMoved = true;
		    }
		    else {
			  if (m_orders.front().isOrderFilled()) {
				g_completed.push_back(std::move(m_orders.front()));
			  }
			  else {
				g_incomplete.push_back(std::move(m_orders.front()));
			  }
			  m_orders.pop_front();
			  orderMoved = true;
		    }
		}
	  }
	  
	  return orderMoved;
    }

    void Workstation::setNextStation(Workstation* station) {
	  m_pNextStation = station;
    }

    Workstation* Workstation::getNextStation() const {
	  return m_pNextStation;
    }
    void Workstation::display(std::ostream& os) const {
	  if (m_pNextStation == nullptr) {
		os << getItemName() << " --> End of Line";
	  }
	  else
		os << getItemName() << " --> " << m_pNextStation->getItemName();
	  os << '\n';
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
	  m_orders.push_back(std::move(newOrder));

	  return *this;
    }
}