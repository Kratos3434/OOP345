/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include "CrimeStatistics.h"
#include <fstream>
#include <iterator>
#include <iomanip>
#include <numeric>
#include <algorithm>
#include <functional>

namespace sdds {
    CrimeStatistics::CrimeStatistics(const std::string& fileName) {
	  if (fileName != "crimes.txt") throw "Invalid file!";
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
		ifs >> c[cnt].m_resolved;
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
	  out << theCrime.m_resolved;
	  out << " |";

	  return out;
    }
    
    void CrimeStatistics::display(std::ostream& out) const{
	  /*
	  for (auto it = m_crimes.begin(); it != m_crimes.end(); ++it) {
		out << *it << std::endl;
	  }
	  */
	  std::copy(m_crimes.begin(), m_crimes.end(), std::ostream_iterator<Crime>(out, "\n"));


	  int totalCrimes = std::accumulate(m_crimes.begin(), m_crimes.end(), 0, [](int sum, const Crime& crime) {
		return sum + crime.m_numCases;
		});

	  out << "----------------------------------------------------------------------------------------\n";
	  out << "|" << std::setw(80);
	  out << "Total Crimes:  " << totalCrimes;
	  out << " |\n";

	  int resolvedCases = std::accumulate(m_crimes.begin(), m_crimes.end(), 0, [](int sum, const Crime& crime) {
		return sum + crime.m_resolved;
		});

	  out << "|" << std::setw(80);
	  out << "Total Resolved Cases:  " << resolvedCases;
	  out << " |" << std::endl;
    }

    void CrimeStatistics::sort(const std::string& fieldName) {
	  if (fieldName == "Province") {
		std::sort(m_crimes.begin(), m_crimes.end(), [](const Crime& crime1, const Crime& crime2) {
		    return crime1.m_province < crime2.m_province;
		    });
	  }
	  else if (fieldName == "Crime") {
		std::sort(m_crimes.begin(), m_crimes.end(), [](const Crime& crime1, const Crime& crime2) {
		    return crime1.m_crime < crime2.m_crime;
		    });
	  }
	  else if (fieldName == "Cases") {
		std::sort(m_crimes.begin(), m_crimes.end(), [](const Crime& crime1, const Crime& crime2) {
		    return crime1.m_numCases < crime2.m_numCases;
		    });
	  }
	  else if (fieldName == "Resolved") {
		std::sort(m_crimes.begin(), m_crimes.end(), [](const Crime& crime1, const Crime& crime2) {
		    return crime1.m_resolved < crime2.m_resolved;
		    });
	  }
    }

    void CrimeStatistics::cleanList() {
	  static_cast<void>(std::count_if(m_crimes.begin(), m_crimes.end(), [](Crime& crime) {
		bool none = false;
		if (crime.m_crime == "[None]") {
		    crime.m_crime = "";
		    none = true;
		}

		return none;
		}));
    }

    bool CrimeStatistics::inCollection(const std::string& crimeName) const {
	  return std::any_of(m_crimes.begin(), m_crimes.end(), [=](const Crime& crime) {
		return crime.m_crime == crimeName;
		});
    }

    std::list<Crime> CrimeStatistics::getListForProvince(const std::string& provinceName) const {
	  std::list<Crime> result(m_crimes.size());

	  auto numResults = std::copy_if(m_crimes.begin(), m_crimes.end(), result.begin(), [=] (const Crime& crime) {
		return crime.m_province == provinceName;
		});

	  result.resize(std::distance(result.begin(), numResults));//resize array to number of results

	  return result;
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