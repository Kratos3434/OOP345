/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/


#include "Restaurant.h"

namespace sdds {
    Restaurant::Restaurant(const Reservation* reservations[], size_t cnt) {
	  m_numReservations = cnt;
	  m_res = new Reservation * [cnt+1];
	  for (int i = 0; i < (int)cnt; i++) m_res[i] = new Reservation(*reservations[i]);
    }

    Restaurant::Restaurant(const Restaurant& res) {
	  (*this) = res;
    }
    Restaurant& Restaurant::operator=(const Restaurant& res) {
	  if (this != &res) {
		for (int i = 0; i < m_numReservations; i++) delete m_res[i];
		delete[] m_res;

		m_numReservations = res.m_numReservations;
		m_res = new Reservation * [res.m_numReservations + 1];
		for (int i = 0; i < res.m_numReservations; i++) {
		    m_res[i] = new Reservation(*res.m_res[i]);
		}
	  }

	  return *this;
    }
    Restaurant::~Restaurant() {
	  for (int i = 0; i < m_numReservations; i++) delete m_res[i];
	  delete[] m_res;
    }
    Restaurant::Restaurant(Restaurant&& res) {
	  *this = std::move(res);
    }
    Restaurant& Restaurant::operator=(Restaurant&& res) {
	  if (this != &res) {
		delete[] m_res;

		m_numReservations = res.m_numReservations;
		
		m_res = res.m_res;
		res.m_res = nullptr;
		res.m_numReservations = 0;
	  }

	  return *this;
    }
    size_t Restaurant::size() {
	  return m_numReservations;
    }

    std::ostream& Restaurant::display(std::ostream& os) const {
	  static int callCount = 0;
	  callCount++;
	  os << "--------------------------\n";
	  os << "Fancy Restaurant (" << callCount << ")\n";
	  os << "--------------------------\n";
	  if (m_numReservations == 0) os << "This restaurant is empty!\n";
	  else for (int i = 0; i < m_numReservations; i++) os << *m_res[i];
	  os << "--------------------------" << std::endl;

	  return os;
    }

    std::ostream& operator<<(std::ostream& os, const Restaurant& res) {
	  return res.display(os);
    }
}