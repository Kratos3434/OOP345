#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include "Vehicle.h"
#include <iostream>

namespace sdds {
    Vehicle* createInstance(std::istream& in);
}
#endif // !SDDS_UTILITIES_H
