////////////////////////////////////////////////////////////
//
//		Static Data and Static Methods
//
////////////////////////////////////////////////////////////

class Font {};
class PrinterPort {};

class MyOnlyPrinter
{
private:
	// All data static
	static Font defaultFont;
	static PrinterPort printerPort;
public:
	// all methods static
	static void AddPrintJob() {}
	static void CancelPrintJob() {}
};


/////

int main()
{
	// 1) static functions can't be virtual
	// 		so can use polymorphism in derived classes
	// 2) initialization and cleanup difficult
	//		not in one place (static defined outside class)
	// 3) can't cope with dependencies 
	//		such as default font depending on the printer port
	
	MyOnlyPrinter::AddPrintJob();
	MyOnlyPrinter::CancelPrintJob();	
}
