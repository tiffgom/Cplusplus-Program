/*Author: Tiffany Gomez
* Course: CS210 Professor Rissover
* Date: August 1, 2021
* Assignment: Final Project 2- Airgead Banking Application
* 
* This program consists of three files (main.cpp, MyInvest.cpp, MyInvest.h). 
* The application allows the user to study a static display for Data Input and then input their own data.
* The program uses the user's choices of initial investment amount, length of the investment, interest rate percentage, and monthly
* deposits to calculate two reports that compare the span of the accounts earnings with additional monthly deposits made into the account
* versus the earnings including only the intial investment. The user has the option to continue to alter the data input to study various
* results and end the program when they are ready.

*/

#include<iostream>
#include "MyInvest.h"


using namespace std;


int main() {												//main() initiates the program and has minimal code in main() for portability
	MyInvest MyInvest;
	MyInvest.dataInputDisplay();


	return 0;
}

