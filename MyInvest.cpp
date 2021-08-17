#include "MyInvest.h"
#include <sstream>				  //For conversion of variable to string
#include<iostream>
#include <limits>				  //For numeric_limits function
#include <string>		
#include <Windows.h>		     //For sleep() function.
#include<iomanip>				//For displays
#include <stdexcept>			// Library needed for the runtime_error object to be  thrown/caught in exception handling cases
#undef max	//Undefine Microsoft's macro as Microsoft define's is as non-standard "max" macro in Windows.h header and it conflicts with max() function of numeric_limits.					



using namespace std;

///initialized default constructor
MyInvest::MyInvest() {					
	this->m_investmentAmount = 0.0;		     //Initial investment amount.
	this->m_interestRate = 0.0;				//Annual interest rate.
	this->m_numberYears = 0;				//Years account produces earnings.
	this->m_monthlyDeposit = 0.0;			//Additional amount of investment per month.		
}

///Parameterized contructor with initialized data members. 
MyInvest::MyInvest(double t_investmentAmount, double t_interestRate, double t_monthlyDeposit, int t_numberYears) {
	this->m_investmentAmount = t_investmentAmount;
	this->m_interestRate = t_interestRate;
	this->m_numberYears = t_numberYears;
	this->m_monthlyDeposit = t_monthlyDeposit;
}


///Accessors and Mutators
///Setters include throw for cases where user inputs negative values and clear buffer.
double MyInvest::getInvestmentAmount() const {
	return this->m_investmentAmount;
}
void MyInvest::setInvestmentAmount(double t_investmentAmount) {

	if (t_investmentAmount < 0) {
		throw out_of_range("Please enter a valid amount.");
		cin.clear();
	}

	else {
		this->m_investmentAmount = t_investmentAmount;
	}
}
double MyInvest::getInterestRate() const{
	return this->m_interestRate;
}
void MyInvest::setInterestRate(double t_interestRate){
	if (t_interestRate < 0) {
		throw out_of_range("Please enter a valid interest rate." );	
		cin.clear();
		
	}
	else {
		this->m_interestRate = t_interestRate;
	}
}
double MyInvest::getMonthlyDeposit() const {
	return this->m_monthlyDeposit;
}
void MyInvest::setMonthlyDeposit(double t_monthlyDeposit) {
	if (t_monthlyDeposit <= 0) {
		throw out_of_range("Please enter more than $0.00.");
		cin.clear();
		
	}
	else {
		this->m_monthlyDeposit = t_monthlyDeposit;
	}
}
int MyInvest::getNumberYears() const{
	return this->m_numberYears;
}
void MyInvest::setNumberYears(int t_numberYears){
	if (t_numberYears <= 0) {
		throw out_of_range("Please enter a valid year.");
		cin.clear();
		
	}
	else{
		this->m_numberYears = t_numberYears;
	}
}


///Function calculates and displays both reports.
void MyInvest::reportsDisplay() {
	noMonthlyDepositReport();
	monthlyDepositReport();
	
}


///Function prints the data input display and then prompts and allows user input.
void MyInvest::dataInputDisplay() {
	int tempInvestment;					//Local variables created for setters.
	int tempYear;
	int tempInterest;
	int tempMonthly;
	bool isValid;						//Flag


	cout << "******************************" << endl;		//Print static Data Input display
	cout << "**********Data Input**********" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;
	system("pause");										 //Prompt user to enter any key to continue.
	cout << endl;
	cout << endl;
	

	//Try/catch statement handles exceptions and prompts user to reenter input if user input value is negative.
	//User will have an opportunity to correct their entry, otherwise an answer will be pre-populated for them.
	

		cout << "--------------------------------" << endl;			//Print display for data input
		cout << "Please enter numeric values only" << endl;
		cout << "********************************" << endl;
		cout << "**********Data Input************" << endl;
		
		
	
		cout << "Initial Investment Amount: $";						//Prompt and grab user input
		cin >> tempInvestment;
		isValid = false;
		do {
			try {

				if (cin.fail()) {									//If the last operation failed
					cin.clear();									//Clear the error
					tempInvestment = -1;							//Set to out of range value so existing catch block prompt the user for a new number. 
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip over the erroneous data entered

				}
				setInvestmentAmount(tempInvestment);					 //Pass local variable through setter.
				isValid = true;											//Set boolean to true to continue 
			}
			catch (out_of_range err) {
				cout << err.what() << endl;
				cout << "Initial Investment Amount: $";
				cin >> tempInvestment;
			}
		}
		while (isValid == false);

		cout << "Monthly Deposit: $";
		cin >> tempMonthly;
		isValid = false;
		do {
			try {
				if (cin.fail()) {
					cin.clear();
					tempMonthly = -1;
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				}
				setMonthlyDeposit(tempMonthly);
				isValid = true;
			}

			catch (out_of_range err) {
				cout << err.what() << endl;
				cout << "Monthly Deposit: $";
				cin >> tempMonthly;
			}
		}
		while (isValid == false);


		cout << "Annual Interest: %";
		cin >> tempInterest;
		isValid = false;
		do {
			try {
				if (cin.fail()) {
					cin.clear();
					tempInterest = -1;
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				}
				setInterestRate(tempInterest);
				isValid = true;
			}
			catch (out_of_range err) {
				cout << err.what() << endl;
				cout << "Annual Interest: %";
				cin >> tempInterest;
			}
		} 
		while (isValid == false);
		

		cout << "Number of years: ";
		cin >> tempYear;
		isValid = false;
		do {
			try {
				if (cin.fail()) {
					cin.clear();
					tempYear = -1;
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				}
				setNumberYears(tempYear);
				isValid = true;
			}
			catch (out_of_range err) {
				cout << err.what() << endl;
				cout << "Number of years: ";
				cin >> tempYear;
			}
		}
		while (isValid == false);
	



		
		cout << endl; intputDisplay();			//Function display user input without errors
		cout << endl; reportsDisplay();			//Function runs calculations and displays reports.
		cout << endl; userInput();				//Function offers user option to restart or quit.

}
			

//Function displays user entered data
void MyInvest::intputDisplay() {
	system("CLS");											//Clear console of errors displayed
	cout << "******************************" << endl;		//Print static Data Input display
	cout << "**********Data Input**********" << endl;		//With userinput
	cout << "Initial Investment Amount: $" << m_investmentAmount << endl;
	cout << "Monthly Deposit: $" << m_monthlyDeposit << endl;
	cout << "Annual Interest: %" << m_interestRate << endl;
	cout << "Number of years: " << m_numberYears << endl;

}
	

///Function displays report calculations that include monthly deposits.
void MyInvest::monthlyDepositReport() {
	int year = 1;										//Initialize local variable to 1 as the interest are annual.
	double yearlyBalance = this->m_investmentAmount;	//Create local variable for initial amount.

	cout << "           Balance and Interest With Additional Monthly Deposits " << endl;			//Print headers display.
	cout << "============================================================================" << endl;
	cout << setw(10) << "Year"
		<< setw(27) << "Year End Balance"
		<< setw(40) << "Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------------------" << endl;


	//Loop calculates the yearly balance with the additional interest earned from the added monthly investment.
	while (year <= this->m_numberYears) {						//While-loop iterates the user entered amount.
		int month = 1;											//Month initiated to start at beginning of year.
		double earnedInterest = 0.0;							//Clears interests earned.
		double monthlyBalance = yearlyBalance;
		while (month <= 12) {									//Nested loop calculates interests for 12 months.
			monthlyBalance += this->m_monthlyDeposit;			//Monthly deposit added to balance.
			double monthlyInterest = monthlyBalance * this->m_interestRate / (100.0 * 12); //Interests earned calculated.
			earnedInterest += monthlyInterest;					//Interest calculated to interest of previous loops.
			monthlyBalance += monthlyInterest;					//Interest added to total balance.
			month++;											//Increment months
		}
		yearlyBalance = monthlyBalance;							//Result of yearly balance becomes new opening amount for next loop.

		stringstream yearlyBalanceString;												//Converts type to string.
		stringstream earnedInterestString;
		yearlyBalanceString << "$" << fixed << setprecision(2) << yearlyBalance;		//Formats string $00.00 (2 places after decimal).
		earnedInterestString << "$" << fixed << setprecision(2) << earnedInterest;

		cout << right << setw(8) << year												//Print user input in report display.
			<< fixed << setprecision(2) << setw(20) << yearlyBalanceString.str()
			<< setw(35) << earnedInterestString.str() << endl;;

		year++;																			//Increment year

	}

	return;
}

//function displays report with calculations that do not include monthly deposits.		
void MyInvest::noMonthlyDepositReport() {
	int year = 1;																	//Initialize current year to 1.
	double yearlyBalance = this->m_investmentAmount;								//Create local variable for user's initial investment.
	
	cout << "         Balance and Interest Without Additional Monthly Deposits " << endl;	//Print display header.
	cout << "============================================================================" << endl;
	cout << setw(10) << "Year"
		 << setw(27) << "Year End Balance"
		 << setw(39) << "Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	
	while(year <= this->m_numberYears) {											//While-loop's iterates he user's year input.
		double earnedInterest = yearlyBalance * this->m_interestRate/100;			//Calculates interest earned per year.
		yearlyBalance += earnedInterest;											//Adds earning tobalance.
									
		
		stringstream yearlyBalanceString;											//Convert to string so that the display
		stringstream earnedInterestString;											//so that "$" does not affect alignment.
		yearlyBalanceString << "$" << fixed << setprecision(2) << yearlyBalance;
		earnedInterestString << "$" << fixed << setprecision(2) << earnedInterest;
																					
		cout << right << setw(8) << year 		  
			<< fixed << setprecision(2) << setw(20) << yearlyBalanceString.str()    //Print with modified variables.
			<< setw(35) << earnedInterestString.str() << endl;;

		year++;																	   
		
	}
	cout << endl;
	cout << endl;
	
	return;	
}




//Function gives user the option to run program with different data or end the program.
void MyInvest::userInput() {
	Sleep(1000);								 //Pause
	bool validInput = false;					//Flag
	char userInput;								//User will choose 'y' to enter new data or 'n' to quick program.

	
	while (validInput == false) {				//While-loop validates input
		
		try {									//Exception 
			cout << "Would you like to input new data? Enter Y to continue and N to quit. ";
			cin >> userInput;
			//If-loop user does not enter valid input
			if ((userInput != 'N') && (userInput != 'n') && (userInput != 'Y') && (userInput != 'y')) {
				throw out_of_range("Invalid Entry.");
				
			}

			else if ((userInput == 'Y') || (userInput == 'y')) {					//If-loop for 'y' or 'Y' input.
				system("CLS");														//Clear screen
				dataInputDisplay();													//Program begins again.
				validInput = false;
				break;
			}
			else if ((userInput == 'N') || (userInput == 'n')) {						//If-loop for 'n' or 'N' input.
				system("CLS");
				cout << "Thank you for using Airgead Banking App! Goodbye.";		 //Print goodbye message.
				Sleep(1000);														//Pause 
				exit(0);															//Terminate
			}
		}
		catch (out_of_range err) {
			cout << err.what() << endl;
			cout << "You entered '" << userInput << "' Please enter Y or N."<<endl;	//Print valid in put and prompt again.					
		

		}
	}

	
}

		
		




	


