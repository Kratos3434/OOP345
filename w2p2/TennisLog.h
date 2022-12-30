/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H

#include <string>
#include <iostream>

using namespace std;
namespace sdds {
     struct TennisMatch {
	   string m_tournamentID;
	   string m_tournamentName;
	   unsigned int m_matchID;
	   string m_matchWinner;
	   string m_matchLoser;
    };
    std::ostream& operator<<(std::ostream& os, const TennisMatch& tm);
    class TennisLog {
	  TennisMatch* m_tennisMatch{};
	  int NOM{};//Number of Matches

    public:
	  TennisLog();
	  TennisLog(const char* fileName);
	  //copy const and copy assign
	  TennisLog(const TennisLog& tl);
	  TennisLog& operator=(const TennisLog& tl);
	  //move const and move assign
	  TennisLog(TennisLog&& tl);
	  TennisLog& operator=(TennisLog&& tl);
	  ~TennisLog();
	  void addMatch(const TennisMatch& tl);
	  TennisLog findMatches(const char* name);
	  TennisMatch operator[](size_t index) const;
	  operator size_t() const;


    };

}
#endif // !SDDS_TENNISLOG_H
