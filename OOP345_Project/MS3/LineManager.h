// Name: Keith Carlos
// Seneca Student ID: 127638211
// Seneca email: kwcarlos@myseneca.ca
// Date of completion: 2022-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include "Workstation.h"
#include <string>
#include <iostream>
#include <vector>

namespace sdds {
    class LineManager {
	  std::vector<Workstation*> m_activeLine{};
	  size_t m_cntCustomerOrder{0u};
	  Workstation* m_firstStation{nullptr};

    public:
	  LineManager(const std::string& file, const std::vector<Workstation*>& stations);
	  void reorderStations();
	  bool run(std::ostream& os);
	  void display(std::ostream& os) const;
    };
}

#endif // !SDDS_LINEMANAGER_H
