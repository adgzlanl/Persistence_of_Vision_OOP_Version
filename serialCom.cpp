// 
// 
// 

#include "serialCom.h"
#include"POV.h"
POV CallPopup;
serialCom::serialCom()
{

}
serialCom::~serialCom()
{

}
void serialCom::Init(int baudRate,  int Port)
{
	this->baudRate=baudRate;
	
	switch (Port)
	{
	
	case 0:
		Serial.begin(baudRate);
		break;
	case 1:
		Serial1.begin(baudRate);
		break;
	case 2:
		Serial2.begin(baudRate);
		break;
	case 3:
		Serial3.begin(baudRate);
		break;
	}
}

String serialCom::IncomingData(String NewData)
{
	String PrintString=CallPopup.PopUp(NewData);
	

	return PrintString;
}




