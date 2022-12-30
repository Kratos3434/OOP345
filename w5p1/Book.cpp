#include "Book.h"
#include <iomanip>


namespace sdds {
    void Book::setEmpty() {
	  m_author = "";
	  m_title = "";
	  m_country = "";
	  m_year = 0;
	  m_price = 0.0;
	  m_description = "";
    }
    Book::Book() {
	  setEmpty();
    }
    const std::string& Book::title() const {
	  return m_title;
    }
    const std::string& Book::country() const {
	  return m_country;
    }
    const size_t& Book::year() const {
	  return m_year;
    }
    double& Book::price() {
	  return m_price;
    }
    Book::Book(const std::string& strBook) {
	  std::string a = strBook;
	  size_t n = a.find(',');
	  m_author = a.substr(0, n);
	  m_author = trim(m_author, (int)m_author.length());

	  std::string b = a.substr(n + 1);
	  n = b.find(',');
	  m_title = b.substr(0, n);
	  m_title = trim(m_title, (int)m_title.length());

	  std::string c = b.substr(n + 1);
	  n = c.find(',');
	  m_country = c.substr(0, n);
	  m_country = trim(m_country, (int)m_country.length());

	  std::string d = c.substr(n + 1);
	  n = d.find(',');
	  m_price = stod(d.substr(0, n));

	  std::string e = d.substr(n + 1);
	  n = e.find(',');
	  m_year = stoi(e.substr(0, n));

	  std::string f = e.substr(n + 1);
	  n = f.find('\n');
	  m_description = f.substr(n + 1);
	  m_description = trim(m_description, (int)m_description.length());
    }
    std::ostream& Book::display(std::ostream& os) const {
	  //AUTHOR | TITLE | COUNTRY | YEAR | PRICE | DESCRIPTION
	  os << std::setw(20) << m_author << " | ";
	  os << std::setw(22) << m_title << " | ";
	  os << std::setw(5) << m_country << " | ";
	  os << std::setw(4) << m_year << " | ";
	  os << std::setw(6) << std::fixed << std::setprecision(2) << m_price << " | ";
	  os << m_description << std::endl;

	  return os;
    }

    std::string& trim(std::string& val, int len) {
	  int z = 0, y = 0;
	  for (int i = 0; i < len; i++) {
		if (val[i] != ' ') {
		    y = i;
		    break;
		}
	  }
	  for (int i = len - 1; i >= 0; i--) {
		if (val[i] != ' ') {
		    z = i;
		    break;
		}
	  }

	  z = z - y + 1;
	  val = val.substr(y, z);

	  return val;
    }
    std::ostream& operator<<(std::ostream& os, const Book& b) {
	  return b.display(os);
    }
}