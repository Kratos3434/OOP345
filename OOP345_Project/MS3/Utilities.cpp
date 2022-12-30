// Name: Keith Carlos
// Seneca Student ID: 127638211
// Seneca email: kwcarlos@myseneca.ca
// Date of completion: 2022-11-10
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "Utilities.h"

namespace sdds {
    std::string Utilities::m_delimiter = "";

    std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	  std::string token = str.substr(next_pos);

	  if (token[0] == m_delimiter[0])
	  {
		more = false;
		throw "   ERROR: No token.";
	  }

	  std::stringstream ss(token);
	  std::string res;
	  std::getline(ss, res, m_delimiter[0]);
	  //res = trim(res, (int)res.length());
	  next_pos += res.length();
	  next_pos++;
	  if (token[res.length()] == m_delimiter[0]) {
		more = true;
	  }
	  else more = false;

	  std::string extractedToken = trim(res, (int)res.length());

	  if (m_widthField < (int)extractedToken.length())
		m_widthField = (int)extractedToken.length();

	  return extractedToken;

    }

    void Utilities::setFieldWidth(size_t newWidth) {
	  m_widthField = (int)newWidth;
    }

    size_t Utilities::getFieldWidth() const {
	  return m_widthField;
    }


    void Utilities::setDelimiter(char newDelimiter) {
	  m_delimiter = newDelimiter;
    }
    char Utilities::getDelimiter() {
	  return m_delimiter[0];
    }

    std::string& Utilities::trim(std::string& val, int len) {
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