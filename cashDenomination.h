class CashDenominations {
    public:
	int fiveHundred;
	int twoThousand;
    int oneHundred;
	
	CashDenominations(int tT,int fH,int oH)
	{
		fiveHundred=fH;
		oneHundred=oH;
		twoThousand=tT;
	}
	
	CashDenominations add(CashDenominations obj)
	{
		int tT=twoThousand+obj.twoThousand,fH=fiveHundred+obj.fiveHundred,oH=oneHundred+obj.oneHundred;
		CashDenominations result(tT,fH,oH);
		return result;
	}
	CashDenominations subtract(CashDenominations obj)
	{
		int tT=twoThousand-obj.twoThousand,fH=fiveHundred-obj.fiveHundred,oH=oneHundred-obj.oneHundred;
		CashDenominations result(tT,fH,oH);
		return result;
	}
};