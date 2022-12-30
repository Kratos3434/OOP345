// Name: Keith Carlos
// Seneca Student ID: 127638211
// Seneca email: kwcarlos@myseneca.ca
// Date of completion: 2022-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include <string>
#include <iostream>
#include <sstream>

namespace sdds {
    class Utilities {
	  int m_widthField{ 1 };
	  static std::string m_delimiter;
    public:
	  //Member Functions

	  void setFieldWidth(size_t newWidth);
	  size_t getFieldWidth() const;
	  std::string extractToken(const std::string& str, size_t& next_pos, bool& more);

	  //Class Functions
	  
	  static void setDelimiter(char newDelimiter);
	  static char getDelimiter();

	  std::string& trim(std::string& val, int len);
    };
}

#endif // !SDDS_UTILITIES_H
