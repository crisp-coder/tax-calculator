#include <iostream>
#include "tax_table.h"

int main (int argc, char** argv){
	double taxable_income = 0.0;
	double tax = 0.0;
	double fica_tax_rate = 0.0765;
	double fica_tax = 0.0;

	// Get income
	double income = atof(argv[1]);

	// FICA
	fica_tax = income * fica_tax_rate;	
	// Subtract deductions
    double std_deduction = 14600.0;	
	taxable_income = income > std_deduction ? (income - std_deduction) : 0;

	// Filter through tax brackets
    tax = TaxTable::getIncomeTax(taxable_income);

	std::cout << "Taxable_income = " << taxable_income << std::endl;	
	std::cout << "FICA Tax = " << fica_tax << std::endl;
	std::cout << "Income Tax = " << tax << std::endl;
	std::cout << "Total Tax = " << fica_tax + tax << std::endl;
	double effective_tax_rate = tax/income;
	double total_tax_rate = (tax+fica_tax)/income;
	std::cout << "Percent of Income = " << effective_tax_rate << std::endl;
	std::cout << "Total Tax Rate = " << total_tax_rate << std::endl;
	std::cout << "Remaining Income = " << income - fica_tax - tax << std::endl;
	return 0;
}


