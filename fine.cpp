//
//  fine.cpp
//  CS31_Project2
// Name: Samuel Alsup   UID: 805371633
//  Created by Sam Alsup on 10/9/19.
//  Copyright © 2019 Sam Alsup. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int baseFine = 20; // sets the base fine of $20 thousand
    double amountPaid;
    string defendantName;
    cout.setf(ios::fixed);
    cout.precision(1); //this makes each price expressed as a double with one decimal place
    cout << "Defendant: ";
    getline(cin, defendantName);
    cout << "Amount paid (in thousands) : ";
    cin >> amountPaid;
    cin.ignore(10000, '\n'); // resets the newline character so that the next getline command will take in the correct string
    string isAthlete;
    cout << "Fake athlete? (y/n) : ";
    getline(cin, isAthlete);
    cout << "---" << endl;
    double finalFine = baseFine; // starts the fine off with the base fine, so that everything else will be added on after
    
    if (amountPaid < 40) // the following lines of code fine the defendant based on how much money was paid
        finalFine = finalFine + amountPaid * 0.66; //adds a 66% fine
    else
        finalFine = finalFine + 40 * 0.66; //adds a 66% fine to first 40 thousand
    
    if ((amountPaid > 40) && (amountPaid <= 250) && (isAthlete == "n")) // checks to see if more than $40,000 was paid without athletic status
        finalFine = finalFine + ((amountPaid - 40) * 0.1);
    else if ((amountPaid > 250) && (isAthlete == "n")) // checks to see if more than $250,000 was paid without athletic status
        finalFine = finalFine + (210 * 0.1) + ((amountPaid - 250) * 0.14);
    else if ((amountPaid > 40) && (amountPaid <= 250) && (isAthlete == "y")) //checks to see if more than $40,000 was paid and faked athletic status
        finalFine = finalFine + ((amountPaid - 40) * 0.22);
    else if ((amountPaid > 250) && (isAthlete == "y")) //checks to see if more than $250,000 was paid with faked athletic status
        finalFine = finalFine + ((210) * 0.22) + ((amountPaid - 250) * 0.14);
    
    if (defendantName == "") // the following lines of code check to see if errors were made when entering information
        cout << "You must enter a defendant name." << endl;
    else if (amountPaid < 0)
        cout << "The amount paid must not be negative." << endl;
    else if ((isAthlete != "y") && (isAthlete != "n"))
        cout << "You must enter y or n." << endl;
    else // next line outputs the suggested fine if no errors were made
        cout << "The suggested fine for " << defendantName << " is $" << finalFine << " thousand." << endl;
}
