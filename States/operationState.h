#include<bits/stdc++.h>
using namespace std;
#include "state.h"
#include "dispenseState.h"
#include "verificationState.h"
#include "idleState.h"
class OperationState:public State {

	int MAX_AMOUNT=10000;
	public:
	void insertCard(ATM atmMachine, ATMCard card) {
		cout<<"Card Already inserted!!";
	}

	
	void insertPin(ATM atmMachine) {
		cout<<"Already have your PIN!!";

	}

	
	void performOperation(ATM atmMachine){
		// TODO Auto-generated method stub
		
		int operationChoice;
        cin>>operationChoice;
		switch(operationChoice)
		{
		case 1: cashWithdrawl(atmMachine);
			    break;
		case 2: cashDeposit(atmMachine);
				break;
		case 3: checkBalance(atmMachine);
				break;
		case 4: changePin(atmMachine);
				break;
		default:;
		}
	}

	
	void collectInformation(ATM atmMachine) {
		cout<<"No Information found";
	}
	
	void cancelTransaction(ATM atmMachine) {
		cout<<"Transcation cancelled!!";
        return;

	}
	
	void changePin(ATM atmMachine)
	{
		cout<<"Please enter your new PIN!!";
		int newPin;
        cin>>newPin
		atmMachine.card.setPin(newPin);
		string output="PIN Successfully changed";
		State *nextState=new DispenseState(nullptr,output,1);
		atmMachine.setCurrentState(nextState);
	}
	
	void checkBalance(ATM atmMachine)
	{
		string output="Your current balance is Rs. "+atmMachine.card.getBalance();
		State *nextState=new DispenseState(nullptr,output,1);
		atmMachine.setCurrentState(nextState);
	}
	
	void cashDeposit(ATM atmMachine)
	{
		
		cout<<"Enter the count of Rs 2000 Notes";
		int tT;
        cin>>tT;
		cout<<"Enter the count of Rs 500 Notes";
		int fH;
        cin>>fH;
		cout<<"Enter the count of Rs 100 Notes";
		int oH;
        cin>>oH;
		
		CashDenominations cashDeposited(tT,fH,oH);
		CashDenominations atmCash=atmMachine.getCash();
		CashDenominations newCashState=cashDeposited.add(atmCash);
		atmMachine.setCash(newCashState);
		
		long balanceDeposited=2000*tT+500*fH+100*oH;
		long cardBalance=atmMachine.card.getBalance();
		atmMachine.card.setBalance(balanceDeposited+cardBalance);
		
		string output="Cash successfully deposited!";
		State *nextState=new DispenseState(nullptr,output,1);
		atmMachine.setCurrentState(nextState);
		
	}
	
	void cashWithdrawl(ATM atmMachine)
	{
		cout<<"Enter the amount of money to withdraw (two 0 at end)";
		
		int amount;
        cin>>amount;
		int withdrawnAmount=amount;
		if(amount>MAX_AMOUNT)
		{
			string output="Withdrawl over 10k not allowed, try again!!";
			State *nextState=new DispenseState(nullptr,output,1);
			atmMachine.setCurrentState(nextState);
		}
		else
		{
			long currBalance=atmMachine.card.getBalance();
			if(currBalance<amount)
			{
				string output="Enough Balance Not Available In Your Card!!";
				State *nextState=new DispenseState(nullptr,output,1);
				atmMachine.setCurrentState(nextState);
			}
			else
			{
				CashDenominations currentAtmCash=atmMachine.getCash();
				int tT=0,fH=0,oH=0;
				tT=amount/(2000);
				if(tT<currentAtmCash.twoThousand)
				{
					amount=amount%2000;
				}
				else
				{
					amount=amount-2000*currentAtmCash.twoThousand;
					tT=currentAtmCash.twoThousand;
				}
				fH=amount/(500);
				if(fH<currentAtmCash.fiveHundred)
				{
					amount=amount%500;
				}
				else
				{
					amount=amount-500*currentAtmCash.fiveHundred;
					fH=currentAtmCash.fiveHundred;
				}
				oH=amount/(100);
				if(oH<currentAtmCash.oneHundred)
				{
					amount=amount%100;
				}
				else
				{
					amount=amount-100*currentAtmCash.oneHundred;
					oH=currentAtmCash.oneHundred;
				}
				if(amount!=0)
				{
					string output="Bank Doesn't have enough notes or wrong amount entered!!";
					State *nextState=new DispenseState(nullptr,output,1);
					atmMachine.setCurrentState(nextState);
				}
				else
				{
					CashDenominations cashWithdrawn(tT,fH,oH);
					CashDenominations updatedAtmCash=currentAtmCash.subtract(cashWithdrawn);
					atmMachine.setCash(updatedAtmCash);
					long newBalance=currBalance-withdrawnAmount;
					atmMachine.card.setBalance(newBalance);
					State *nextState=new DispenseState(cashWithdrawn,"",0);
					atmMachine.setCurrentState(nextState);
				}
			}
		}
	}
};