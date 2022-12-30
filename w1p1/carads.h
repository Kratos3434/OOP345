#ifndef SDDS_CARADS_H
#define SDDS_CARADS_H
#include <iostream>

extern double g_taxrate;
extern double g_discount;
namespace sdds {
    void listArgs(int argc, char* argv[]);
    class Cars {
	  char m_brand[10]{};
	  char m_model[15]{};
	  int m_year{};
	  double m_price{};
	  char m_status{};
	  bool m_onDiscount{};
	  void init();
    public:
	  Cars();
	  ~Cars() {};
	  void read(std::istream& is);
	  void display(bool reset);
	  char getStatus();
    };
}
#endif // !SDDS_CARADS_H
