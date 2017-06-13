/*
 * uart.cpp
 *
 *  Created on: 13 cze 2017
 *      Author: tomek
 */
#include "uart.h"

Uart::Uart()
{
	cout << "Konstruktor UART" << endl;
	wsk_f[0] = &Uart::ST_Gotowy;
	wsk_f[1] = &Uart::ST_OdebranyZnak;
	wsk_f[2] = &Uart::ST_OdebranyString;
	wsk_f[3] = &Uart::ST_Blad;
	wsk_f[4] = &Uart::ST_Wysylam;
	wsk_f[5] = &Uart::ST_Nic;
	wsk_f[6] = &Uart::ST_Cos;
	i = 0;
}

void Uart::ZD_NowyZnak(Param_Uart *Dane)
{
	cout << "Odebrano nowy znak" << endl;
	const uint16_t TAB_PRZEJSC[] =
	{
		ST_ODEBRANY_ZNAK,				// ST_GOTOWY
		ST_ODEBRANY_ZNAK,				// ST_ODEBRANY_ZNAK
		//ST_ODEBRANY_ZNAK				// ST_ODEBRANY_STRING
	};
	Zdarzenie(TAB_PRZEJSC[StanBiezacy], Dane);
}
void Uart::ST_Gotowy(Param_Uart *Dane)
{
	cout << "Stan Gotowy" << endl;
}

void Uart::ST_OdebranyZnak(Param_Uart *Dane)
{
	//buf[i++] = Dane->znak;
	cout << "Stan: Odebrany znak, ";
	cout << "dane: " << Dane->znak << endl;
	if(Dane->znak == 't') Zdarzenie(ST_ODEBRANY_STRING, Dane);
}

void Uart::ST_OdebranyString(Param_Uart *Dane)
{
	cout << "Stan: Odebrany string, ";
	cout << "dane: " << Dane->znak << endl;

	Zdarzenie(ST_GOTOWY, Dane);
}

void Uart::ST_Blad(Param_Uart *Dane)
{
	cout << "Blad" << endl;
	//Zdarzenie(ST_GOTOWY, Dane);
}

void Uart::ST_Wysylam(Param_Uart *Dane)
{
	cout << "Wysylam..." << endl;
}

void Uart::ST_Nic(Param_Uart *Dane)
{
	cout << "Nic" << endl;
}

void Uart::ST_Cos(Param_Uart *Dane)
{
	cout << "Dupa" << endl;
}

