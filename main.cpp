/*
 * main.cpp
 *
 *  Created on: 13 cze 2017
 *      Author: tomek
 */
#include "uart.h"
#include "lockerbox.h"
#include "dynabox.h"

enum TypMaszyny {TLockerbox, TDynabox};
TypMaszyny typ = TDynabox; 		// odczytywane z EEPROM

int main()
{
	Maszyna *m;
	switch (typ)
	{
		case TLockerbox:
		{
			Lockerbox_Param param;
			Lockerbox lockerbox;
			m = &lockerbox;
		}
		break;
		case TDynabox:
		{
			Dynabox_Param param;
			Dynabox dynabox;
			m = &dynabox;
		}
		break;
		default:
		{
			// Nie odczyta z EEPROM
		}
		break;
	}

	char znak;
	Uart_Param Dane_Uart;
	Uart uart;
	cout << m->PrzedstawSie() << endl;
	uint16_t stan1, stan2;
	//stan1 = uart.PobierzStan();

	//Dane_Uart.znak = 'f';
	//uart.ZD_NowyZnak(&Dane_Uart);
	//stan1 = uart.PobierzStan();


	//while(1)
	//{
		//cin >> znak;
		//Dane_Uart.znak = znak;
		//uart.ZD_NowyZnak(&Dane_Uart);
	//}

}


