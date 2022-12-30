// Name: Keith Carlos
// Seneca Student ID: 127638211
// Seneca email: kwcarlos@myseneca.ca
// Date of completion: 2022-11-16
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Station.h"
#include "Utilities.h"
#include <iomanip>

namespace sdds {
    int Station::m_widthField = 0;
    int Station::id_generator = 0;

    Station::Station(const std::string& val) {
	  Utilities util;
	  bool more = true;
	  size_t pos = 0u;
	  
	  id_generator++;

	  m_id = id_generator;

	  m_itemName = util.extractToken(val, pos, more);

	  std::string serialNum = util.extractToken(val, pos, more);
	  m_serialNumber = std::stoi(serialNum);

	  std::string numItems = util.extractToken(val, pos, more);
	  m_numItems = std::stoi(numItems);

	  if (m_widthField < (int)util.getFieldWidth())
		m_widthField = (int)util.getFieldWidth();

	  m_desc = util.extractToken(val, pos, more);
    }

    const std::string& Station::getItemName() const {
	  return m_itemName;
    }

    size_t Station::getNextSerialNumber() {
	  m_nextSerialNum = m_serialNumber;
	  m_serialNumber++;
	  return m_nextSerialNum;
    }

    size_t Station::getQuantity() const {
	  return m_numItems;
    }

    void Station::updateQuantity() {
	  if (m_numItems > 0)
		m_numItems--;
    }

    void Station::display(std::ostream& os, bool full) const {
	  if (!full) {
		os << std::setfill('0') << std::setw(3) << std::right << m_id << " | ";
		os << std::setfill(' ') << std::setw(m_widthField) << std::left << m_itemName << "  | ";
		os << std::setfill('0') << std::setw(6) << std::right << m_serialNumber << " | " << std::endl;
	  }
	  else {
		os << std::setfill('0') << std::setw(3) << std::right << m_id << " | ";
		os << std::setfill(' ') << std::setw(m_widthField) << std::left << m_itemName << "  | ";
		os << std::setfill('0') << std::setw(6) << std::right << m_serialNumber << " | ";
		os << std::setfill(' ') << std::setw(4) << m_numItems << " | ";
		os << m_desc << std::endl;

	  }
    }
}