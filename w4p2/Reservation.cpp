/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include "Reservation.h"
#include <string.h>

using namespace std;

namespace sdds {
    Reservation::Reservation() {
	  m_resID = "";
	  m_resName = "";
	  m_email = "";
	  m_numPeople = 0;
	  m_day = 0;
	  m_hour = 0;
    }
    void Reservation::update(int day, int time) {
	  m_day = day;
	  m_hour = time;
    }
    Reservation::Reservation(const std::string& res) {
	  std::string::size_type n;
	  string a = res;
	  //ID
	  n = a.find(':');
	  m_resID = a.substr(0, n + 1);
	  m_resID = trim(m_resID, (int)m_resID.length()-1);
	  //name
	  string b = a.substr(n + 1);
	  n = b.find(',');
	  m_resName = b.substr(0, n);
	  m_resName = trim(m_resName, (int)m_resName.length());
	  //email
	  string c = b.substr(n+1);
	  n = c.find(',');
	  m_email = c.substr(0, n);
	  m_email = trim(m_email, (int)m_email.length());
	  //num of people
	  string d = c.substr(n + 1);
	  n = d.find(',');
	  m_numPeople = stoi(d.substr(0, n));
	  //day
	  string e = d.substr(n + 1);
	  n = e.find(',');
	  m_day = stoi(e.substr(0, n));
	  //hour
	  string f = e.substr(n + 1);
	  n = f.find('\n');
	  m_hour = stoi(f.substr(0, n));
    }
    std::ostream& Reservation::display(std::ostream& os) const {
	  string email = "  <" + m_email + ">";
	  os.setf(ios::right);
	  os << "Reservation ";
	  os.width(10);
	  os << m_resID << ":";
	  os.width(21);
	  os << m_resName;
	  os.unsetf(ios::right);
	  os.setf(ios::left);
	  os.width(26);
	  os << email;
	  if (m_hour >= 6 && m_hour <= 9) os << "Breakfast on day ";
	  else if (m_hour >= 11 && m_hour <= 15) os << "Lunch on day ";
	  else if (m_hour >= 17 && m_hour <= 21) os << "Dinner on day ";
	  else os << "Drinks on day ";
	  os << m_day << " @ " << m_hour << ":00 for " << m_numPeople << (m_numPeople == 1 ? " person." : " people.") << endl;
	  return os;
    }
    std::ostream& operator<<(std::ostream& os, const Reservation& res) {
	  return res.display(os);
    }

    std::string& trim(std::string& val, int len) {
	  //static string a = val;
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

    bool Reservation::operator==(const Reservation& res) const {
	  return m_resID == res.m_resID && m_resName == res.m_resName 
		&& m_email == res.m_email && m_numPeople == res.m_numPeople 
		&& m_day == res.m_day && m_hour == res.m_hour;
    }
}