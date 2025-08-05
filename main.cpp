#include <iostream>
#include "single_income_tax_brackets_2025.h"

int main (int argc, char** argv){

    if(argc != 2){
        std::cout << "Usage: tax <income from wages>" << std::endl;
        return 1;
    }

	double taxable_income = 0.0;
	double tax = 0.0;
	double fica_tax_rate = 0.0765;
	double fica_tax = 0.0;

	// Get income
	double income = atof(argv[1]);

	// FICA
	fica_tax = income * fica_tax_rate;	

	// Subtract deductions
    double std_deduction = 15750.0;	
	taxable_income = income > std_deduction ? (income - std_deduction) : 0;

	// Filter through tax brackets
    tax = TaxTable::getIncomeTax(taxable_income);

	std::cout << "Taxable income = " << taxable_income << std::endl;	
	std::cout << "FICA tax = " << fica_tax << std::endl;
	std::cout << "Income tax = " << tax << std::endl;
	std::cout << "Total tax = " << fica_tax + tax << std::endl;
	double income_tax_percentage = tax/income;
	double total_tax_percentage = (tax+fica_tax)/income;
	std::cout << "Income tax percent = " << income_tax_percentage << std::endl;
	std::cout << "Total tax percent = " << total_tax_percentage << std::endl;
	std::cout << "Remaining income = " << income - fica_tax - tax << std::endl;
	return 0;
}


