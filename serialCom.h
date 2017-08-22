// serialCom.h

#ifndef _SERIALCOM_h
#define _SERIALCOM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


class serialCom
{
public:
	serialCom();
	~serialCom();
	void Init(int baudRate,int Port);
	String IncomingData(String NewData);
	//void SendCommand(char command, String* arguments, int argumentCount);

private:



	int baudRate;



	//static bool CheckCRC(String newCommand);
	//static int GetChecksum(String stringToSum);

};

#endif

