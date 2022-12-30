#define _CRT_SECURE_NO_WARNINGS
#include "carads.h"
#include <iomanip>
#include <cstring>


double g_taxrate = 0.0;
double g_discount = 0.0;
namespace sdds {
    void listArgs(int argc, char* argv[]) {
	  std::cout << "Command Line:\n";
	  std::cout << "--------------------------\n";
	  for (int i = 0; i < argc; i++) {
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << std::endl;
	  }
	  std::cout << "--------------------------\n" << std::endl;
    }

    void Cars::init() {
	  m_brand[0] = '\0';
	  m_model[0] = '\0';
	  m_year = 0;
	  m_price = 0.0;
	  m_status = '\0';
	  m_onDiscount = NULL;
    }
    Cars::Cars() {
	  init();
    }
    void Cars::read(std::istream& is) {
	  char discountStatus{};
	  if (is) {
		is >> m_status;
		is.ignore();
		is.getline(m_brand, 10, ',');
		is.getline(m_model, 15, ',');
		is >> m_year;
		is.ignore();
		is >> m_price;
		is.ignore();
		is >> discountStatus;
		switch (discountStatus) {
		case 'Y': m_onDiscount = true;
		    break;
		case 'N': m_onDiscount = false;
		    break;
		}
	  }
	  return;
    }
    void Cars::display(bool reset) {
	  double priceWithTax = (m_price * g_taxrate) + m_price;
	  double specialPrice = priceWithTax - (priceWithTax * g_discount);
	  static unsigned int callCount = 0;
	  callCount++;
	  if (reset) callCount = 1;
	  if (m_brand[0] != '\0') {
		std::cout << std::left << std::setw(2) << callCount<<". ";
		std::cout << std::left << std::setw(10) << m_brand << "| ";
		std::cout << std::left << std::setw(15) << m_model << "| ";
		std::cout << std::setw(4) << m_year << " | ";
		std::cout << std::right << std::setw(11) << std::fixed << std::setprecision(2) << priceWithTax << "|";
		if (m_onDiscount) std::cout << std::right << std::setw(12) << std::fixed << std::setprecision(2) << specialPrice;
		std::cout << std::endl;
	  }
	  else callCount--;
    }
    char Cars::getStatus() {
	  return m_status;
    }
}