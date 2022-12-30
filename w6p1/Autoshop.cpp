#include "Autoshop.h"
#include <iterator>

namespace sdds {
    Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
	  m_vehicles.push_back(theVehicle);

	  return *this;
    }


    Autoshop::~Autoshop(){
	for(size_t i = 0;i < m_vehicles.size(); i++){
	delete m_vehicles[i];
}
}
    void Autoshop::display(std::ostream& out) const {
	  for (auto it = m_vehicles.begin(); it != m_vehicles.end(); it++) {
		(*it)->display(out);
	  }
		
    }
}
