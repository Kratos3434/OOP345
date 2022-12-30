/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include "Utilities.h"
#include <string>
#include "Car.h"
#include "Van.h"
#include "Racecar.h"
#include "Luxuryvan.h"

namespace sdds {
    Vehicle* createInstance(std::istream& in) {
	  Vehicle* vehicle = nullptr;
	  char type = '\0';

	  in >> type;
	  if (type == '\0') return nullptr;
	  //std::cout << type << std::endl;
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
		case 'R':
		case 'r':
		    in.putback(type);
		    vehicle = new Racecar(in);
		    break;
		case 'L':
		case 'l':
		    in.putback(type);
		    vehicle = new Luxuryvan(in);
		    break;
		default:
		    std::string s(1, type);
		    std::string errMsg = "Unrecognized record type: [" + s + "]";
		    in.clear();
		    in.ignore(1000, '\n');
		    throw errMsg;
		    break;
		}
	  return vehicle;
    }
}