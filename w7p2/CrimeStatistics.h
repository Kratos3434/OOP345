/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H

#include <string>
#include <vector>
#include <iostream>
#include <list>

namespace sdds {
    struct Crime {
	  std::string m_province{};
	  std::string m_district{};
	  std::string m_crime{};
	  int m_numCases{ 0 };
	  int m_year{ 0 };
	  int m_resolved{ 0 };

    };

    std::ostream& operator<<(std::ostream& out, const Crime& theCrime);

    class CrimeStatistics {
	  std::vector<Crime> m_crimes;
    public:
	  CrimeStatistics() {};
	  CrimeStatistics(const std::string& fileName);
	  void display(std::ostream& out) const;
	  void sort(const std::string& fieldName);
	  void cleanList();
	  bool inCollection(const std::string& crimeName) const;
	  std::list<Crime> getListForProvince(const std::string& provinceName) const;
    };

    std::string& trim(std::string& val, int len);
}
#endif // !SDDS_CRIMESTATISTICS_H
