#include "CrimeStatistics.h"
#include <fstream>
#include <iterator>
#include <iomanip>

namespace sdds {
    CrimeStatistics::CrimeStatistics(const char* fileName) {
	  std::ifstream ifs(fileName);
	  int cnt = 0;
	  char province[25] = { '\0' };
	  char district[25] = { '\0' };
	  char crime[25] = { '\0' };
	  Crime* c = nullptr;
	  std::string line;
	  while (ifs) {
		getline(ifs, line);
		cnt++;
	  }
	  c = new Crime[cnt];
	  cnt = 0;
	  ifs.close();
	  ifs.open(fileName);

	  while (ifs) {
		ifs.get(province, 25);
		c[cnt].m_province = province;
		c[cnt].m_province = trim(c[cnt].m_province, (int)c[cnt].m_province.length());
		ifs.ignore();

		ifs.get(district, 25);
		c[cnt].m_district = district;
		c[cnt].m_district = trim(c[cnt].m_district, (int)c[cnt].m_district.length());
		ifs.ignore();

		ifs.get(crime, 25);
		c[cnt].m_crime = crime;
		c[cnt].m_crime = trim(c[cnt].m_crime, (int)c[cnt].m_crime.length());
		ifs.ignore();

		ifs >> c[cnt].m_year;
		ifs.ignore();
		ifs >> c[cnt].m_numCases;
		ifs.ignore();
		ifs >> c[cnt].m_numResolved;
		ifs.ignore(1000, '\n');

		m_crimes.push_back(c[cnt]);

		cnt++;
	  }

	  delete[] c;
    }
    std::ostream& operator<<(std::ostream& out, const Crime& theCrime) {
	  out << "| " << std::setw(21) <<std::left;
	  out << theCrime.m_province;
	  out << " | " << std::setw(15);
	  out << theCrime.m_district;
	  out << " | " << std::setw(20);
	  out << theCrime.m_crime;
	  out << " | " << std::setw(6) << std::right;
	  out << theCrime.m_year;
	  out << " | " << std::setw(4);
	  out << theCrime.m_numCases;
	  out << " | " << std::setw(3);
	  out << theCrime.m_numResolved;
	  out << " |";

	  return out;
    }
    void CrimeStatistics::display(std::ostream& out) const{
	  for (auto it = m_crimes.begin(); it != m_crimes.end(); ++it) {
		out << *it << std::endl;
	  }
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