#include <iostream>
#include <iomanip>
#include <cmath>
 
int main() {
    double loan_amount;
    double annual_rate;        // entered as a percentage, e.g. 6.5
    int number_of_payments;
 
    std::cout << "Enter the loan amount: ";
    std::cin >> loan_amount;
 
    std::cout << "Enter the annual interest rate (as a percentage): ";
    std::cin >> annual_rate;
 
    std::cout << "Enter the number of monthly payments: ";
    std::cin >> number_of_payments;
 
    // Convert the annual percentage rate to a monthly decimal rate
    double monthly_rate = annual_rate / 100 / 12;
 
    // Monthly payment formula (full, unrounded values)
    double growth = std::pow(1 + monthly_rate, number_of_payments);
    double monthly_payment = (monthly_rate * growth) / (growth - 1) * loan_amount;
 
    double amount_paid_back = monthly_payment * number_of_payments;
    double interest_paid = amount_paid_back - loan_amount;
 
    // Display results
    std::cout << "\n";
    std::cout << std::fixed;
 
    std::cout << std::setprecision(2);
    std::cout << "Loan amount:          $" << loan_amount << "\n";
 
    // The monthly rate is not a monetary value, so show more digits
    std::cout << std::setprecision(6);
    std::cout << "Monthly interest rate: " << monthly_rate << "\n";
 
    std::cout << "Number of payments:    " << number_of_payments << "\n";
 
    // setprecision(2) only for monetary results
    std::cout << std::setprecision(2);
    std::cout << "Monthly payment:      $" << monthly_payment << "\n";
    std::cout << "Amount paid back:     $" << amount_paid_back << "\n";
    std::cout << "Interest paid:        $" << interest_paid << "\n";
 
    return 0;
}
