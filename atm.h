#include "atmCard.h"
#include "cashDenomination.h"
//#include "C:\Users\Husain\Desktop\New folder\atm design\stateInformation\state.h"
class ATM
{
	public:
    ATMCard card;
    CashDenominations cash;
    State *atmMachineState;

    
    State* getCurrentState()
    {
        return atmMachineState;
    }
    void setCurrentState(State *nextState)
	{
		atmMachineState=nextState;
	}
	
	CashDenominations getCash()
	{
		return cash;
	}
	
	void setCash(CashDenominations newCash)
	{
		cash=newCash;
	}
};