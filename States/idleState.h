#include<bits/stdc++.h>
using namespace std;
#include "state.h"
#include "verificationState.h"
#include "dispenseState.h"
#include "operationState.h"
class IdleState:public State {

    public:
	
	void insertCard(ATM atmMachine, ATMCard card) {
		atmMachine.card=card;
		cout<<"Card Successfully inserted";
		State *nextState=new VerificationState();
		atmMachine.setCurrentState(nextState);
	}

	
	void insertPin(ATM atmMachine) {
		cout<<"Cant Enter PIN at this stage!!";
	}

	
	void performOperation(ATM atmMachine) {
		cout<<"Can't choose any operation at this stage!!";
	}

	
	void collectInformation(ATM atmMachine) {
		cout<<"No Information found";
	}

	
	void cancelTransaction(ATM atmMachine) {
		cout<<"Transaction Not Started";
	}

};