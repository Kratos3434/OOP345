#include <iomanip>
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
}