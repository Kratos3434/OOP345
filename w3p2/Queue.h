/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H

#include "Dictionary.h"
namespace sdds {
    template <typename T, unsigned int capacity>
    class Queue {
    protected:
	  T m_queue[capacity]{};
	  unsigned m_qCount = 0;
	  T dummy{};
    public:
	  Queue() :m_qCount(0), dummy() { }
	  virtual ~Queue() {}

	  virtual bool push(const T& item) {
		bool added = false;
		if (m_qCount < capacity) {
		    m_queue[size()] = item;
		    m_qCount++;
		    added = true;
		}
		return added;
	  }

	  T pop() {
		T temp = m_queue[0];
		for (unsigned i = 0; i < m_qCount - 1; i++) {
		    m_queue[i] = m_queue[i + 1];
		}
		m_qCount--;
		return temp;
	  }

	  unsigned size() const {
		return m_qCount;
	  }
	  T& operator[](unsigned index)
	  {
		if (index >= size())
		    return dummy;
		else return m_queue[index];
	  }

	  std::ostream& display(std::ostream& os = std::cout) const {
		os << "----------------------\n";
		os << "| Dictionary Content |\n";
		os << "----------------------\n";
		for (unsigned i = 0; i < size(); i++) {
		    os << m_queue[i] << std::endl;
		}
		os << "----------------------" << std::endl;
		return os;
	  }

    };
    //Specialization
    template<>
    Dictionary& Queue<Dictionary, 100u>::operator[](unsigned index) {
	  if (index > m_qCount) {
		m_queue[index].set("Empty Term", "Empty Substitute");
	  }
	  return m_queue[index];
    }
}
#endif // !SDDS_QUEUE_H