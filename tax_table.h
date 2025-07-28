#pragma once

class TaxTable{

  public:
    static double getIncomeTax(double taxable_income){
      
      const double bracket_limits[] = 
      {0.0,
      11600.0,
      47150.0,
      100525.0,
      191950.0, 
      243725.0,
      609350.0,
      999999999.0};


      const double bracket_rates[] = 
      {0.0,
      0.10, 
      0.12, 
      0.22, 
      0.24, 
      0.32, 
      0.35, 
      0.37};
      
      double tax = 0.0;
      
      for(int i = 1; i < 8; i++){
        if(taxable_income > bracket_limits[i]){
          tax += (bracket_limits[i] - bracket_limits[i-1]) * bracket_rates[i];
        }
        else{
          tax += (taxable_income - bracket_limits[i-1]) * bracket_rates[i];
          break;
        }
      }  
      return tax;
    }
};


