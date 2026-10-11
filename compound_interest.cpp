
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
