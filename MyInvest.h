#pragma once
#ifndef FINALPROJECT2_AIRGEADAPP_MYINVEST_H_			//Define gaurd full source tree to guarantee uniqueness.
#define FINALPROJECT2_AIRGEADAPP_MYINVEST_H_
class MyInvest{

//Declare public data members and functions. 
//Label parameters inside constructor with "t_" syntax.
public:
	MyInvest();
	MyInvest(double t_investmentAmount, double t_interestRate, double t_monthlyDeposit, int t_numberYears= 1);
	double getInvestmentAmount() const;
	void setInvestmentAmount(double t_investmentAmount);
	double getInterestRate() const;
	void setInterestRate(double t_interestRate);
	double getMonthlyDeposit() const;
	void setMonthlyDeposit(double t_monthlyDeposit);
	int getNumberYears() const;
	void setNumberYears(int t_numberYears);
	void noMonthlyDepositReport();
	void monthlyDepositReport();
	void dataInputDisplay();
	
	
//Declare private data members and functions. 
//Label private member with "m_" syntax.
private:
	double m_investmentAmount;
	double m_interestRate;
	double m_monthlyDeposit;
	int m_numberYears;
	void reportsDisplay();
	void intputDisplay();
	void userInput();
	
	


	
};
#endif

