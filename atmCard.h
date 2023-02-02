#include<bits/stdc++.h>
using namespace std;

class ATMCard {

	int pin;
	string AccNo;
	long long balance;
     
    public:

	
    ATMCard(int pin,string AccNo,int balance)
	{
		pin=pin;
		AccNo=AccNo;
		balance=balance;
	}
	
	int getPin()
	{
		return pin;
	}
	
	void setPin(int newPin)
	{
		pin=newPin;
	}
	
	string getAccNo()
	{
		return AccNo;
	}
	
	long long getBalance()
	{
		return balance;
	}
	
	void setBalance(long newBalance)
	{
		balance=newBalance;
	}

    void updateBalance(int newBalance)
	{
		balance=newBalance;
	}
};