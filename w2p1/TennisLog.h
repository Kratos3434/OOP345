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
	  TennisLog(const TennisLog& tl);
	  TennisLog& operator=(const TennisLog& tl);
	  ~TennisLog();
	  void addMatch(const TennisMatch& tl);
	  TennisLog findMatches(const char* name);
	  TennisMatch operator[](size_t index);
	  operator size_t() const;


    };

}
#endif // !SDDS_TENNISLOG_H
