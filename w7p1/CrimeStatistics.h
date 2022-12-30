#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H

#include <string>
#include <vector>
#include <iostream>

namespace sdds {
    struct Crime {
	  std::string m_province{};
	  std::string m_district{};
	  std::string m_crime{};
	  int m_numCases{ 0 };
	  int m_year{ 0 };
	  int m_numResolved{ 0 };
    };
    std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
    class CrimeStatistics {
	  std::vector<Crime> m_crimes;
    public:
	  CrimeStatistics() {};
	  CrimeStatistics(const char* fileName);

	  //testing
	  void display(std::ostream& out) const;

    };

    std::string& trim(std::string& val, int len);
}
#endif // !SDDS_CRIMESTATISTICS_H
