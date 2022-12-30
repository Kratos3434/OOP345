#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <vector>
#include "Vehicle.h"
#include <iostream>

namespace sdds {
    class Autoshop {
	  std::vector<Vehicle*> m_vehicles;

    public:
	  Autoshop& operator+=(Vehicle* theVehicle);
	  ~Autoshop();
	  void display(std::ostream& out) const;
	  
    };
}
#endif // !SDDS_AUTOSHOP_H
