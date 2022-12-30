/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/


#include "ConfirmationSender.h"

namespace sdds {
    ConfirmationSender::ConfirmationSender() {
	  m_res = nullptr;
	  m_numRes = 0;
    }
    //copy
    ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs) {
	  *this = cs;
    }
    ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cs) {
	  if (this != &cs) {
		delete[] m_res;

		m_numRes = cs.m_numRes;
		m_res = new const Reservation * [cs.m_numRes + 1];
		for (int i = 0; i < cs.m_numRes; i++) m_res[i] = cs.m_res[i];
	  }

	  return *this;
    }
    //move
    ConfirmationSender::ConfirmationSender(ConfirmationSender&& cs) {
	  *this = std::move(cs);
    }
    ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& cs) {
	  if (this != &cs) {
		delete[] m_res;

		m_numRes = cs.m_numRes;

		m_res = cs.m_res;
		cs.m_res = nullptr;
		cs.m_numRes = 0;
	  }

	  return *this;
    }
    ConfirmationSender::~ConfirmationSender() {
	  delete[] m_res;
    }
    ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
	  if (!isExist(res)) {
		const Reservation** temp = new const Reservation * [m_numRes];
		for (int i = 0; i < m_numRes; i++) {
		    temp[i] = m_res[i];
		}
		delete[] m_res;
		m_numRes++;
		m_res = new const Reservation * [m_numRes];
		for (int i = 0; i < m_numRes - 1; i++) {
		    m_res[i] = temp[i];
		}
		m_res[m_numRes - 1] = &res;
		delete[] temp;
	  }

	  return *this;
    }
    ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
	  if (isExist(res)) {
		int index = -1;
		for (int i = 0; i < m_numRes; i++) {
		    if (*m_res[i] == res)
			  index = i;
		}
		if (index > -1) {
		    m_res[index] = nullptr;
		    m_numRes--;
		    for (int i = index; i < m_numRes; i++) m_res[i] = m_res[i + 1];
		}
	  }

	  return *this;
    }

    bool ConfirmationSender::isExist(const Reservation& res) {
	  bool exist = false;
	  for (int i = 0; i < m_numRes; i++) {
		if (*m_res[i] == res) exist = true;
	  }

	  return exist;
    }

    std::ostream& ConfirmationSender::display(std::ostream& os) const {
	  os << "--------------------------\n";
	  os << "Confirmations to Send\n";
	  os << "--------------------------\n";
	  if (m_numRes == 0) os << "There are no confirmations to send!\n";
	  else for (int i = 0; i < m_numRes; i++) os << *m_res[i];
	  os << "--------------------------" << std::endl;

	  return os;
    }

    std::ostream& operator<<(std::ostream& os, const ConfirmationSender& cs) {
	  return cs.display(os);
    }
}