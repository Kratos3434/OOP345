// Name: Keith Carlos
// Seneca Student ID: 127638211
// Seneca email: kwcarlos@myseneca.ca
// Date of completion: 2022-11-30
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <string>
#include "Station.h"
#include <iostream>
#include <exception>

namespace sdds {
    struct Item
    {
	  std::string m_itemName;
	  size_t m_serialNumber{ 0 };
	  bool m_isFilled{ false };

	  Item(const std::string& src) : m_itemName(src) {};
    };

    class CustomerOrder {
	  std::string m_name{};
	  std::string m_product{};
	  size_t m_cntItem{0};
	  Item** m_lstItem{nullptr};

	  static size_t m_widthField;

    public:
	  CustomerOrder();
	  CustomerOrder(const std::string& str);
	  CustomerOrder(const CustomerOrder&) { throw std::exception(); }
	  CustomerOrder& operator=(const CustomerOrder&) = delete;
	  CustomerOrder(CustomerOrder&& co) noexcept;
	  CustomerOrder& operator=(CustomerOrder&& co) noexcept;
	  ~CustomerOrder();
	  bool isOrderFilled() const;
	  bool isItemFilled(const std::string& itemName) const;
	  void fillItem(Station& station, std::ostream& os);
	  void display(std::ostream& os) const;
    };
}
#endif // !SDDS_CUSTOMERORDER_H
