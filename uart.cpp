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
	i = 0;
	Zdarzenie(ST_GOTOWY);
}

void Uart::ZD_NowyZnak(Uart_Param *Dane)
{
	cout << "Odebrano nowy znak" << endl;
	const uint16_t TAB_PRZEJSC[] =
	{
		ST_ODEBRANY_ZNAK,				// ST_GOTOWY
		ST_ODEBRANY_ZNAK,				// ST_ODEBRANY_ZNAK
		ST_ODEBRANY_ZNAK,				// ST_ODEBRANY_STRING
		ST_GOTOWY 						// ST_BLAD
	};
	Zdarzenie(TAB_PRZEJSC[StanBiezacy], Dane);
}
void Uart::ST_Gotowy(Uart_Param *Dane)
{
	cout << "Stan: Gotowy" << endl;
}

void Uart::ST_OdebranyZnak(Uart_Param *Dane)
{
	buf[i++] = Dane->znak;
	cout << "Stan: Odebrany znak, ";
	cout << "dane: " << Dane->znak << endl;
	if(Dane->znak == 'n') Zdarzenie(ST_ODEBRANY_STRING, Dane);
	if(Dane->znak == 'x') Zdarzenie(ST_BLAD);
}

void Uart::ST_OdebranyString(Uart_Param *Dane)
{
	buf[i] = '\0';
	cout << "Stan: Odebrany string, ";
	cout << "dane: " << buf << endl;

	Zdarzenie(ST_GOTOWY, Dane);
}

void Uart::ST_Blad(Uart_Param *Dane)
{
	cout << "Blad" << endl;
	//Zdarzenie(ST_GOTOWY, Dane);
}

void Uart::ST_Wysylam(Uart_Param *Dane)
{
	cout << "Wysylam..." << endl;
}

void Uart::ST_Nic(Uart_Param *Dane)
{
	cout << "Nic" << endl;
}

void Uart::ST_Cos(Uart_Param *Dane)
{
	cout << "Dupa" << endl;
}

