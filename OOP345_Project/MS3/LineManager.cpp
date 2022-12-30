// Name: Keith Carlos
// Seneca Student ID: 127638211
// Seneca email: kwcarlos@myseneca.ca
// Date of completion: 2022-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include "LineManager.h"
#include <iterator>
#include <fstream>
#include "Utilities.h"
#include <algorithm>

namespace sdds {
    LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) {
	  std::ifstream ifs(file);
	  std::string line;
	  Utilities util;
	  bool more = true;
	  size_t pos = 0u;
	  size_t cnt = 0u;
	  std::vector<std::string> temp;
	  while (!ifs.eof()) {
		getline(ifs, line);

		while (more) {
		    temp.push_back(util.extractToken(line, pos, more));
		}
		pos = 0u;
		more = true;
		///////////

		std::copy_if(stations.begin(), stations.end(), std::back_inserter(m_activeLine), [=](const Workstation* ws) {
		    return temp[0] == ws->getItemName();
		    });

		std::for_each(stations.begin(), stations.end(), [=](Workstation* ws) {
		    if (temp.size() > 1 && temp[1] == ws->getItemName()) {
			  m_activeLine[cnt]->setNextStation(ws);
		    }
		    });
		temp.clear();
		cnt++;
	  }
	  m_cntCustomerOrder = g_pending.size();

	  std::for_each(m_activeLine.begin(), m_activeLine.end(), [=](Workstation* ws) {
		if(std::count_if(m_activeLine.begin(), m_activeLine.end(), [=](Workstation* wss) {
		    return ws->getNextStation() != nullptr 
			  && wss->getNextStation() != nullptr 
			  && ws->getItemName() == wss->getNextStation()->getItemName();
		    }) < 1)
		    m_firstStation = ws;
		});
	  

    }
    void LineManager::reorderStations() {
	  std::vector<Workstation*> activeLine{};
	  
	  activeLine.push_back(m_firstStation);//set first element to first station

	  int i = 0;
	  int j = (int)activeLine.size()-1;
	  bool ordered = false;
		for (i = 0; !ordered; i++) {//loop until ordered
		    if (m_activeLine[i]->getItemName() == activeLine[j]->getNextStation()->getItemName()) {
			  activeLine.push_back(m_activeLine[i]);
			  j++;
		    }
		    if (j == (int)m_activeLine.size() - 1) {
			  ordered = true;
		    }
		    else if (j != (int)m_activeLine.size() - 1 && i == (int)m_activeLine.size() - 1) {
			  i = -1;
		    }
		    
		}

		m_activeLine.clear();//clear vector and make it equal to ordered activeLine

		m_activeLine = activeLine;
		

    }
    bool LineManager::run(std::ostream& os) {
	  static int count = 0;
	  size_t prevOrdersFinished = g_completed.size() + g_incomplete.size();
	  os << "Line Manager Iteration: " << ++count << std::endl;
	  
	  if (!g_pending.empty())
	  {
		*m_firstStation += std::move(g_pending.front());
		g_pending.pop_front();
	  }

	  std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* ws) {
		ws->fill(os);
		});

	  std::for_each(m_activeLine.begin(), m_activeLine.end(), [](Workstation* ws) {
		ws->attemptToMoveOrder();
		});

	  m_cntCustomerOrder -= ((g_completed.size() + g_incomplete.size()) - prevOrdersFinished);
	  return m_cntCustomerOrder <= 0;
    }
    void LineManager::display(std::ostream& os) const {
	  for (auto it = m_activeLine.begin(); it != m_activeLine.end(); ++it) {
		(*it)->display(os);
	  }
    }
}