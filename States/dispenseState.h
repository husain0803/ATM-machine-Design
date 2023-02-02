#include<bits/stdc++.h>
using namespace std;
#include "state.h"
#include "verificationState.h"
#include "idleState.h"
#include "operationState.h"

class DispenseState: public State {

    public:
	string output;
	CashDenominations *cash=nullptr;
	DispenseState(CashDenominations *obj,string message,int flag)
	{
		if(flag==1)
		{
			output=message;
		}
		else
		{
			cash=obj;
		}
	}
	
	void insertCard(ATM atmMachine, ATMCard card) {
		cout<<"Card Already inserted!!";

	}

	
	void insertPin(ATM atmMachine) {
		cout<<"Already have your pin";

	}

	
	void performOperation(ATM atmMachine) {
		cout<<"Operation already performed!!";

	}

	
	void collectInformation(ATM atmMachine){
		if(cash==nullptr)
		{
			cout<<output;
		}
		else
		{
			printCash(cash);
		}
		State *nextState=new IdleState();
		atmMachine.setCurrentState(nextState);
	}

	
	void cancelTransaction(ATM atmMachine) {
		cout<<"Transaction already completed";
	}
	
	void printCash(CashDenominations *cash)
	{
		cout<<"Please take your cash";
		cout<<"Rs 2000 :- "<<cash->twoThousand<<" Rs 500 :- "+cash->fiveHundred<<" Rs 100 :- "+cash->oneHundred;
	}

};