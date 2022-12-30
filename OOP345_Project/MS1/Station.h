// Name: Keith Carlos
// Seneca Student ID: 127638211
// Seneca email: kwcarlos@myseneca.ca
// Date of completion: 2022-11-16
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <string>

namespace sdds {
    class Station {
	  int m_id{ 0 };
	  std::string m_itemName{};
	  std::string m_desc{};
	  unsigned int m_nextSerialNum{ 0u };
	  unsigned int m_numItems{ 0u };
	  unsigned int m_serialNumber{ 0u };
	  static int m_widthField;
	  static int id_generator;
    public:
	  Station(const std::string& val);
	  const std::string& getItemName() const;
	  size_t getNextSerialNumber();
	  size_t getQuantity() const;
	  void updateQuantity();
	  void display(std::ostream& os, bool full) const;

    };

}
#endif // !SDDS_STATION_H
