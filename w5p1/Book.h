#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include <string>

namespace sdds {
    class Book {
	  std::string m_author{};
	  std::string m_title{};
	  std::string m_country{};
	  size_t m_year{};//Should be int,but year() return type is size_t.
	  double m_price{};
	  std::string m_description{};
	  void setEmpty();
    public:
	  Book();
	  const std::string& title() const;
	  const std::string& country() const;
	  const size_t& year() const;
	  double& price();
	  Book(const std::string& strBook);
	  std::ostream& display(std::ostream& os) const;
    };
    std::string& trim(std::string& val, int len);
    std::ostream& operator<<(std::ostream& os, const Book& b);
}
#endif // !SDDS_BOOK_H
