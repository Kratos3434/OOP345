/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include <iomanip>
#include <cstring>
#include "Dictionary.h"

namespace sdds {
    Dictionary::Dictionary() {
	  set("", "");
    }

    void Dictionary::set(const std::string& term, const std::string& definition) {
	  m_term = term;
	  m_definition = definition;
    }
    std::ostream& Dictionary::display(std::ostream& os) const {
	  os << std::right << std::setw(20) << m_term << ": " << m_definition;

	  return os;
    }

    std::ostream& operator<<(std::ostream& os, const Dictionary& d) {
	  return d.display(os);
    }
    
    bool Dictionary::operator==(const Dictionary& d) const {
	  return m_term == d.m_term && m_definition == d.m_definition;
    }
}