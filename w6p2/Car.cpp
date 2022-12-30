/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include "Car.h"
#include <iomanip>

namespace sdds {
    Car::Car(std::istream& is) {
	  std::string condition{""};
	  int topSpeed = 0;
	  std::string maker,tag;

	  getline(is, tag, ',');
	  tag = trim(tag, (int)tag.length());

	  getline(is, maker,',');
	  maker = trim(maker, (int)maker.length());
	  //std::cout << maker << std::endl;

	  getline(is, condition, ',');
	  condition = trim(condition, (int)condition.length());
	  if (condition.empty() || condition == " ") {
		//std::cout << "condition: " << condition << std::endl;
		condition = "n";
	  }
	  else {
		//std::cout << "condition: " << condition << std::endl;
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

		m_tag = tag;
		m_maker = maker;
		m_condition = condition;
		m_topSpeed = topSpeed;
	 
    }
    std::string Car::condition() const {
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
    double Car::topSpeed() const {
	  return (double)m_topSpeed;
    }
    void Car::display(std::ostream& out) const {
	  out << "| " << std::right << std::setw(10) << m_maker << " | ";
	  out << std::left << std::setw(6) << condition() << " | ";
	  out << std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
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