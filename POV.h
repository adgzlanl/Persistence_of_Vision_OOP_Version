// POV.h

#ifndef _POV_h
#define _POV_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class POV
{
public:
	POV();
	~POV();
	void Init();
	void PrintString(String WriteData);
	String PopUp(String DelimitedString);
	//void ReversPrintString();


private:

	String delimitedString;
	int spaceLetter;
	int DotTime;
	void cleanLed();
	void PrintLetter(char ch);
	
	//void ReversePrintLetter(char ch);


};



#endif

