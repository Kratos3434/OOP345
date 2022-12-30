/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include "Van.h"
#include "Car.h"
#include <iomanip>

namespace sdds {
    Van::Van(std::istream& is) {
	  std::string condition, type, purpose;
	  int topSpeed = 0;
	  std::string maker, tag;

	  getline(is, tag, ',');
	  tag = trim(tag, (int)tag.length());

	  getline(is, maker, ',');
	  maker = trim(maker, (int)maker.length());

	  getline(is, type, ',');
	  type = trim(type, (int)type.length());
	  auto checkType = [](std::string type) {
		return type == "p" || type == "m" || type == "c";
	  };
	  if (!checkType(type)) {
		is.clear();
		is.ignore(1000, '\0');
		throw "Invalid record!";
	  }

	  getline(is, purpose, ',');
	  purpose = trim(purpose, (int)purpose.length());
	  auto checkPurpose = [](std::string purpose) {
		return purpose == "d" || purpose == "p" || purpose == "c";
	  };
	  if (!checkPurpose(purpose)) {
		is.clear();
		is.ignore(1000, '\n');
		throw "Invalid record!";
	  }

	  getline(is, condition, ',');
	  condition = trim(condition, (int)condition.length());
	  if (condition.empty() || condition == " ") {
		//std::cout << "condition: " << condition << std::endl;
		condition = 'n';
	  }
	  else {
		auto checkCondition = [](std::string condi) {
		    return condi == "n" || condi == "u" || condi == "b";
		};

		if (!checkCondition(condition)) {
		    is.clear();
		    is.ignore(1000, '\n');
		    throw "Invalid record!";
		}
	  }

	  is >> topSpeed;
	  //std::cout << "topSpeed: " << topSpeed << std::endl;
	  if (is.fail()) {
		is.clear();
		is.ignore(1000, '\n');
		throw "Invalid record!";
	  }
	  
	  if (tag == "v" || tag == "V") {
		std::string consumption;
		getline(is, consumption);
	  }
	  m_tag = tag;
	  //std::cout << tag << std::endl;
	  m_maker = maker;
	  m_type = type;
	  m_purpose = purpose;
	  m_condition = condition;
	  m_topSpeed = topSpeed;

    }
    std::string Van::condition() const {
	  std::string condition;
	  switch (m_condition[0]) {
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
	  switch (m_type[0]) {
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
	  switch (m_purpose[0]) {
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
	  out << " | " << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
    }
}