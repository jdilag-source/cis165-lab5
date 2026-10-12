# cis165-lab5
Why must a percentage be divided by 100 before using it in a formula?
-Maybe because a percentage is just a fraction written out of a hundred. 
How does pow represent exponentiation?
-The first parameter is the base and then the second one is the exponent.
What does the number of compounding periods change in the savings formula?
-Apparently it changes how interest gets added to your balance, and because each addition earns interest itself, more frequent compounding produces a slightly larger final amount. Also, two things happen. 1.) it shrinks the rate applied each time. 2.) it raises the number of times interest is applied.
How is an annual interest rate converted to a monthly rate?
-The annual interest rate is converted to a monthly rate by dividing the annual rate by 100 and then dividing that number by 12. 
Why should double be used for these calculations?
-double should be used because the answer is most likely going to have a decimal point.
Why should calculations use full precision when money is displayed to two decimal places?
-Because rounding at each step would produce small errors which then messes up the whole thing.
How are the amount paid back and total interest calculated?
-So amount paid back is calculated by the monthly payment times the number of payment. THe interest is calculated by the amount paid back minus the loan amount.
Why are calculations stored in variables before being displayed?
-so that we could have a base calculation of things. also, to use it as a simulator of other numbers. 

// compound_interest.cpp
// Calculates compound interest earned on a savings balance.
 
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
 
int main()
{
    double principal;
    double rate_percent;
    double rate;
    double amount;
    double interest_earned;
    int times_compounded;
 
    // Get input from the user
    cout << "Enter the principal balance: ";
    cin >> principal;
 
    cout << "Enter the annual interest rate (as a percentage): ";
    cin >> rate_percent;
 
    cout << "Enter the number of times interest is compounded per year: ";
    cin >> times_compounded;
 
    // Convert percentage to decimal form
    rate = rate_percent / 100.0;
 
    // Compound interest formula
    amount = principal * pow(1.0 + rate / times_compounded,
                             times_compounded);
 
    interest_earned = amount - principal;
 
    // Display the report
    cout << fixed << setprecision(2);
    cout << "\nInterest Report\n";
    cout << "-----------------------------------------\n";
    cout << left  << setw(28) << "Interest Rate:"
         << right << setw(10) << rate_percent << "%\n";
    cout << left  << setw(28) << "Times Compounded:"
         << right << setw(10) << times_compounded << "\n";
    cout << left  << setw(28) << "Principal:"
         << right << "$" << setw(9) << principal << "\n";
    cout << left  << setw(28) << "Interest Earned:"
         << right << "$" << setw(9) << interest_earned << "\n";
    cout << left  << setw(28) << "Amount in Savings:"
         << right << "$" << setw(9) << amount << "\n";
 
    return 0;
}
Enter the principal balance: 1000
Enter the annual interest rate (as a percentage): 4.25
Enter the number of times interest is compounded per year: 12

Interest Report
-----------------------------------------
Interest Rate:                    4.25%
Times Compounded:                   12
Principal:                  $  1000.00
Interest Earned:            $    43.34
Amount in Savings:          $  1043.34

Random Calculation:
Enter the principal balance: 2500
Enter the annual interest rate (as a percentage): 8.00
Enter the number of times interest is compounded per year: 12

Interest Report
-----------------------------------------
Interest Rate:                    8.00%
Times Compounded:                   12
Principal:                  $  2500.00
Interest Earned:            $   207.50
Amount in Savings:          $  2707.50

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
what I get from using this 
Loan amount:          $10000.00
Monthly interest rate: 0.010000
Number of payments:    36
Monthly payment:      $332.14
Amount paid back:     $11957.15
Interest paid:        $1957.15

Random Calculation:
Enter the loan amount: 35000
Enter the annual interest rate (as a percentage): 15
Enter the number of monthly payments: 48

Loan amount:          $35000.00
Monthly interest rate: 0.012500
Number of payments:    48
Monthly payment:      $974.08
Amount paid back:     $46755.66
Interest paid:        $11755.66

