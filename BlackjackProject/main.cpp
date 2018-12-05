/* Names: Tiffany Lam, Chelsea Marfil, Rachel Pai
 * ID: , 014400501,
 * Class: CECS 282 C++
 * Instructor: Minhthong Nguyen
 * Due Date: December 12, 2018
 * Purpose: Using what we've learned in this course to implement this final project.
 */

#include <iostream>
using namespace std;

/** Ask the user to enter the account number.
 @return acctNum - the user's account number.
 */
int promptAccountNumber() {
    cout << "Enter your account number: ";
    int acctNum;
    cin >> acctNum;
    return acctNum;
}

/** Ask the user to enter the amount of money he/she wants to bet.
 @return betAmt - the amount of money user wants to bet.
 */
double promptAmountToBet() {
    cout << "Enter the amount of money to bet: ";
    int betAmt;
    cin >> betAmt;
    return betAmt;
}

/** Randomly select and show the user two cards.
 @return
 */
string selectAndShowTwo() {
    
}

int main(int argc, const char * argv[]) {
    // a. Ask the user to enter the account number.
    int acctNum = promptAccountNumber();
    cout << endl;
    
    // b. Ask the user to enter the amount of money he/she wants to bet.
    double betAmt = promptAmountToBet();
    cout << endl;
    
    // c. The program will randomly select and show the user two cards.
    
    // d. The program will randomly select another two cards and show one card (dealer’s cards).
    
    
    // e. The program will show the value of user’s cards and ask if the user wants to hit or stand or split.
    
    
    //menu
    return 0;
}



