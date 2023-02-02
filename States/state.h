
#include "C:\Users\Husain\Desktop\New folder\atm design\classes\atm.h"
#include "C:\Users\Husain\Desktop\New folder\atm design\classes\atmCard.h"

// this is the abstract class State 
//all other states will inherit and implement the functions of state

class State {
    public:
	virtual void insertCard(ATM atmMachine,ATMCard card)=0;
	virtual void insertPin(ATM atmMachine)=0;
	virtual void performOperation(ATM atmMachine)=0; // chooseOption ke andar perform operation rakhenge
	virtual void collectInformation(ATM atmMachine)=0;
	virtual void cancelTransaction(ATM atmMachine)=0;
};