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
	Lockerbox lockerbox;
	Dynabox dynabox;
	Maszyna *m;
	switch (typ)
	{
		case TLockerbox:
		{

			m = &lockerbox;
		}
		break;
		case TDynabox:
		{

			m = &dynabox;
		}
		break;
		default:
		{
			// Nie odczyta z EEPROM
		}
		break;
	}

	m->ZmienStan(4);
	cout << m->PobierzStan() << endl;
	cout << m->PrzedstawSie() << endl;
	m = &lockerbox;
	cout << m->PobierzStan() << endl;
	cout << m->PrzedstawSie() << endl;
}


