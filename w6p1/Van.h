#ifndef SDDS_VAN_H
#define SDDS_VAN_H

#include "Vehicle.h"
#include <iostream>
#include <string>

namespace sdds {
    class Van :public Vehicle {
	  char m_tag{};
	  std::string m_maker{};
	  char m_type{};
	  char m_purpose{};
	  char m_condition{};
	  int m_topSpeed{ 0 };

    public:
	  Van() {};
	  Van(std::istream& is);
	  ~Van() {};
	  std::string condition() const;
	  double topSpeed() const;
	  std::string type() const;
	  std::string usage() const;
	  void display(std::ostream& out) const;

    };
}
#endif // !SDDS_VAN_H
