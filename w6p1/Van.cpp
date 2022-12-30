#include "Van.h"
#include "Car.h"
#include <iomanip>

namespace sdds {
    Van::Van(std::istream& is) {
	  char tag, type, purpose, condition;
	  std::string maker;
	  int topSpeed;

	  is >> tag;
	  is.ignore();
	  getline(is, maker, ',');
	  maker = trim(maker, (int)maker.length());
	  is >> type;
	  is.ignore();
	  is >> purpose;
	  is.ignore();
	  is >> condition;
	  is.ignore();
	  is >> topSpeed;

	  auto checkTag = [](char tag) {
		return tag == 'V' || tag == 'v';
	  };

	  auto checkType = [](char type) {
		return type == 'p' || type == 'm' || type == 'c';
	  };

	  auto checkCondition = [](char condi) {
		return condi == 'n' || condi == 'u' || condi == 'b';
	  };

	  if (checkTag(tag) && checkType(type) && checkCondition(condition)) {
		m_tag = tag;
		m_maker = maker;
		m_type = type;
		m_purpose = purpose;
		m_condition = condition;
		m_topSpeed = topSpeed;
	  }
    }
    std::string Van::condition() const {
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
    double Van::topSpeed() const {
	  return (double)m_topSpeed;
    }
    std::string Van::type() const {
	  std::string type;
	  switch (m_type) {
	  case 'p':
		type = "pickup";
		break;
	  case 'm':
		type = "mini-bus";
		break;
	  case 'c':
		type = "camper";
		break;
	  }

	  return type;
    }
    std::string Van::usage() const {
	  std::string purpose;
	  switch (m_purpose) {
	  case 'd':
		purpose = "delivery";
		break;
	  case 'p':
		purpose = "passenger";
		break;
	  case 'c':
		purpose = "camping";
		break;
	  }

	  return purpose;
    }
    void Van::display(std::ostream& out) const {
	  out << "| " << std::right << std::setw(8) << m_maker << " | ";
	  out << std::left << std::setw(12) << type();
	  out << " | " << std::setw(12) << usage();
	  out << " | " << std::setw(6) << condition();
	  out << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |" << std::endl;
    }
}
