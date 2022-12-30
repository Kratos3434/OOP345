#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <iostream>
#include <string>
#include "Vehicle.h"

namespace sdds {
    class Car : public Vehicle {
	  char m_tag{};
	  std::string m_maker{};
	  char m_condition{};
	  int m_topSpeed{ 0 };

    public:
	  Car() {};
	  Car(std::istream& is);
	  ~Car() {};
	  std::string condition() const;
	  double topSpeed() const;
	  void display(std::ostream& out) const;
    };
    std::string& trim(std::string& val, int len);
}
#endif // !SDDS_CAR_H
