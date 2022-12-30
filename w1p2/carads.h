/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H
#include <iostream>

extern double g_taxrate;
extern double g_discount;
namespace sdds {
    void listArgs(int argc, char* argv[]);
    class Cars {
	  char* m_brand{};
	  char m_model[15]{};
	  int m_year{};
	  double m_price{};
	  char m_status{};
	  bool m_onDiscount{};
	  void init();
    public:
	  Cars();
	  Cars(const Cars& cars);
	  Cars& operator=(const Cars& cars);
	  ~Cars();
	  void read(std::istream& is);
	  operator bool() const;
	  void display(bool reset) const;
	  char getStatus() const;

    };
    std::istream& operator>>(std::istream& is, Cars& car);
    void operator>>(const Cars& car1, Cars& car2);
}
#endif // !SDDS_CARADS_H