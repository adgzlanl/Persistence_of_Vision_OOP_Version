// 
// 
// 

#include "POV.h"
#include"Font8x5.h"

POV::POV()
{
	
}
POV::~POV()
{

}

void POV::Init()
{
	
	for (int i = 3; i < 14; i++)
	{
		pinMode(i, OUTPUT);
	}

	spaceLetter = 6;
	DotTime = 6;

}

void POV::cleanLed()
{
	int LedPinOUT[] = { 12,11,10,9,8,7,6,5 };

	for (int i = 0; i < 8; i++)
	{
		digitalWrite(LedPinOUT[i], LOW);
	}
}

void POV::PrintLetter(char ch)
{
	int LedPinOUT[] = { 12,11,10,9,8,7,6,5 };
	int i;
	int j;
	int x;
	
	if (ch < 32 || ch >126)
	{
		ch = 32;
	}

	ch -= 32;

	for (i = 4; i > -1; i--)
	{
		byte b=font[ch][i];

		for ( j = 0; j < 8; j++)
		{
			digitalWrite(LedPinOUT[j], bitRead(b, j));
		}
		delay(DotTime);
		cleanLed();

	}

	for (x = 0; x<8; x++)
	{
		digitalWrite(LedPinOUT[x], 0);
	}

	delay(spaceLetter);
}
	


void POV::PrintString(String WriteData)
{



	for (int i = 0; i < WriteData.length(); i++)
	{
		char Character = WriteData.charAt(i);
		PrintLetter(Character);
			
	}
}

String POV::PopUp(String delimitedString)
{
	String word = "";
	String parameter1 = delimitedString.substring(0, delimitedString.indexOf('|'));
	String parameter2 = delimitedString.substring(delimitedString.indexOf('|') + 1, delimitedString.lastIndexOf('|'));

	if (parameter1 == "S")
	{
		Serial3.println("S Geldi");
		spaceLetter = parameter2.toInt();
	}
	else if (parameter1 == "D")
	{
		Serial3.println("D Geldi");
		DotTime = parameter2.toInt();
	}

	else if (parameter1 == "W")
	{
		word = parameter2;
		Serial3.println(word);
	}

	else
	{
		word == "";
	}

	return word;
}