#include<bits/stdc++.h>
using namespace std;
#include "state.h"
#include "dispenseState.h"
#include "idleState.h"
#include "operationState.h"

class VerificationState: public State {

	
	void insertCard(ATM atmMachine, ATMCard card) {
		cout<<"Card already inserted!!";
	}

	
	void insertPin(ATM atmMachine) {
		
		cout<<"Please type your pin";
		int pin;
        cin>>pin;
		if(atmMachine.card.getPin()!=pin)
		{
			cout<<"Wrong Pin typed!! Please remove your card and try later";
            return;

		}
		else
		{
			cout<<"Pin matched!!";
			cout<<"\nPlease select your desired option";
			cout<<"1:- Cash Withdrawl";
			cout<<"2:- Cash Deposit";
			cout<<"3:- Check balance";
			cout<<"4:- Change PIN";
			State *nextState=new OperationState();
			atmMachine.setCurrentState(nextState);
		}
	}

	
	void performOperation(ATM atmMachine) {
		cout<<"Can't choose any operation at this stage!!";
	}

	
	void collectInformation(ATM atmMachine) {
		cout<<"No Information found";
	}

	
	void cancelTransaction(ATM atmMachine) throws Exception{
		cout<<"Transaction ended , please take your card";
        return;

	}

};