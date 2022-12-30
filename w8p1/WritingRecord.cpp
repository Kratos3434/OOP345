/*
Name: Keith Carlos
Section: NBB
Email: kwcarlos@myseneca.ca
Student ID: 127638211

I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.
*/

#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
    GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
	  GeneratingList<EmployeeWage> activeEmp;

	  // TODO: Add your code here to build a list of employees
	  //         using raw pointers
	  for (int i = 0; i < (int)emp.size(); i++) {
		for (int j = 0; j < (int)sal.size(); j++) {
		    if (emp[i].id == sal[j].id) {
			  EmployeeWage* empWage = new EmployeeWage(emp[i].name, sal[j].salary);

			  try {
				empWage->rangeValidator();
			  }
			  catch (std::string& errMsg) {
				delete empWage;
				throw errMsg;
			  }

			  if (activeEmp.checkSIN(emp[i].id)) {
				activeEmp += empWage;
			  }
			  else {
				delete empWage;
				std::string errMsg = "Invalid SIN";
				throw errMsg;
			  }
			  delete empWage;
		    }
		}
	  }

	  return activeEmp;
    }
}