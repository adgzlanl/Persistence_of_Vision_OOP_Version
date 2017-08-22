#include "serialCom.h"
#include"POV.h"
serialCom comPort0, comPort1;
POV pov;
String RawData;
void setup()
{

	comPort0.Init(9600, 0);
	comPort1.Init(9600, 3);
	pov.Init();

	
}

void loop()
{

	pov.PrintString(comPort0.IncomingData(RawData)); 
	
}




void serialEvent3()
{
	 RawData = Serial3.readStringUntil('\n');
	
}