/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

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
	  m_brand = nullptr;
	  m_model[0] = '\0';
	  m_year = 0;
	  m_price = 0.0;
	  m_status = '\0';
	  m_onDiscount = NULL;
    }
    Cars::Cars() {
	  init();
    }
    Cars::Cars(const Cars& cars) {
	  if (cars.m_brand) {
		m_brand = new char[strlen(cars.m_brand) + 1];
		strcpy(m_brand, cars.m_brand);
		strcpy(m_model, cars.m_model);
		m_year = cars.m_year;
		m_price = cars.m_price;
		m_status = cars.m_status;
		m_onDiscount = cars.m_onDiscount;
	  }
	  else init();
    }
    Cars& Cars::operator=(const Cars& cars) {
	  delete[] m_brand;
	  m_brand = nullptr;
	  if (cars.m_brand) {
		m_brand = new char[strlen(cars.m_brand)+1];
		strcpy(m_brand, cars.m_brand);
		strcpy(m_model, cars.m_model);
		m_year = cars.m_year;
		m_price = cars.m_price;
		m_status = cars.m_status;
		m_onDiscount = cars.m_onDiscount;
	  }
	  else init();

	  return *this;
    }
    Cars::~Cars() {
	  delete[] m_brand;
    }
    void Cars::read(std::istream& is) {
	  char discountStatus{};
	  if (is) {
		char* brand = new char[256]{};
		delete[] m_brand;
		m_brand = nullptr;

		is >> m_status;
		is.ignore();
		is.getline(brand, 256, ',');
		if (brand) {
		    m_brand = new char[strlen(brand) + 1];
		    strcpy(m_brand, brand);
		}
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
		delete[] brand;
	  }

    }
    void Cars::display(bool reset) const{
	  double priceWithTax = (m_price * g_taxrate) + m_price;
	  double specialPrice = priceWithTax - (priceWithTax * g_discount);
	  static unsigned int callCount = 0;
	  callCount++;
	  if (reset) callCount = 1;
	  if (m_brand[0] != '\0') {
		std::cout << std::left << std::setw(2) << callCount << ". ";
		std::cout << std::left << std::setw(10) << m_brand << "| ";
		std::cout << std::left << std::setw(15) << m_model << "| ";
		std::cout << std::setw(4) << m_year << " | ";
		std::cout << std::right << std::setw(11) << std::fixed << std::setprecision(2) << priceWithTax << "|";
		if (m_onDiscount) std::cout << std::right << std::setw(12) << std::fixed << std::setprecision(2) << specialPrice;
		std::cout << std::endl;
	  }
	  else callCount--;
    }
    char Cars::getStatus() const{
	  return m_status;
    }
    Cars::operator bool() const {
	  return m_status == 'N';
    }
    std::istream& operator>>(std::istream& is, Cars& car) {
	  car.read(is);
	  return is;
    }
    void operator>>(const Cars& car1, Cars& car2) {
	  car2 = car1;
    }
}