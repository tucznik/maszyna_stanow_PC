/*
 * main.cpp
 *
 *  Created on: 13 cze 2017
 *      Author: tomek
 */
#include "uart.h"
int main()
{
	char znak;
	Param_Uart Dane_Uart;
	Uart uart;
	cout << "STAN: " << uart.PobierzStan() << endl;
	Dane_Uart.znak = 'a';
	uart.ZD_NowyZnak(&Dane_Uart);
	cout << "STAN: " << uart.PobierzStan() << endl;
	//return 0;
	Dane_Uart.znak = 'b';
	uart.ZD_NowyZnak(&Dane_Uart);
	cout << "STAN: " << uart.PobierzStan() << endl;
	Dane_Uart.znak = 't';
	uart.ZD_NowyZnak(&Dane_Uart);
	cout << "STAN: " << uart.PobierzStan() << endl;
	Dane_Uart.znak = 'o';
	uart.ZD_NowyZnak(&Dane_Uart);
	cout << "STAN: " << uart.PobierzStan() << endl;
	while(1)
	{
		cin >> znak;
		Dane_Uart.znak = znak;
		uart.ZD_NowyZnak(&Dane_Uart);
	}

}


