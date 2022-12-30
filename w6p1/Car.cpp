#include "Car.h"
#include <iomanip>

namespace sdds {
    Car::Car(std::istream& is) {
	  char tag, condition;
	  std::string maker;
	  int topSpeed;

	  is >> tag;
	  is.ignore();
	  getline(is, maker,',');
	  maker = trim(maker, (int)maker.length());
	  is >> condition;
	  is.ignore();
	  is >> topSpeed;
	 
	  auto checkTag = [](char tag) {
		return tag == 'C' || tag == 'c';
	  };

	  auto checkCondition = [](char condi) {
		return condi == 'n' || condi == 'u' || condi == 'b';
	  };

	  if (checkTag(tag) && checkCondition(condition)) {
		m_tag = tag;
		m_maker = maker;
		m_condition = condition;
		m_topSpeed = topSpeed;
	  }

    }
    std::string Car::condition() const {
	  std::string condition;
	  switch (m_condition) {
	  case 'n': 
		condition = "new";
		break;
	  case 'u':
		condition = "used";
		break;
	  case 'b':
		condition = "broken";
		break;
	  }

	  return condition;
    }
    double Car::topSpeed() const {
	  return (double)m_topSpeed;
    }
    void Car::display(std::ostream& out) const {
	  out << "| " << std::right << std::setw(10) << m_maker << " | ";
	  out << std::left << std::setw(6) << condition() << " | ";
	  out << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |" << std::endl;
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
}
