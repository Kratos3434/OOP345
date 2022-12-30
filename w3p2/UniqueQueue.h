/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H

#include "Queue.h"

namespace sdds {
    template <typename T>
    class UniqueQueue:public Queue<T,100> {
    public:
	  bool push(const T& item) {
		bool added = false;
		for (unsigned i = 0; i < Queue<T, 100>::size(); i++) {
		    if (Queue<T, 100>::m_queue[i] == item) {
			  return added;
		    }
		}
		return Queue<T, 100>::push(item);
	  }
    };
    template <>
    bool UniqueQueue<double>::push(const double& item) {
	  bool added = false;
	  for (unsigned i = 0; i < Queue<double, 100>::size(); i++) {
		if (std::abs(Queue<double, 100>::m_queue[i] - item) <= 0.005) {
		    return added;
		}
	  }
	  return Queue<double, 100>::push(item);
    }
}

#endif // !SDDS_UNIQUEQUEUE_H
