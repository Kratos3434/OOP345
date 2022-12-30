#include "Utilities.h"
#include <string>
#include "Car.h"
#include "Van.h"

namespace sdds {
    Vehicle* createInstance(std::istream& in) {
	  Vehicle* vehicle = nullptr;
	  char type = '\0';

	  in >> type;
	  if(type == '\0') return nullptr;
	  switch (type) {
	  case 'C':
	  case 'c':
		in.putback(type);
		vehicle = new Car(in);
		break;
	  case 'V':
	  case 'v':
		in.putback(type);
		vehicle = new Van(in);
		break;
	  }
	  return vehicle;
    }
}
