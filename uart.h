/*
 * uart.h
 *
 *  Created on: 13 cze 2017
 *      Author: tomek
 */

#ifndef UART_H_
#define UART_H_
#include <inttypes.h>
#include <iostream>
#include "masz.h"
using namespace std;

class Uart_Param : public Param
{
public:
	uint8_t znak;
};

class Uart : public Maszyna
{
public:
	Uart();
	void ZD_NowyZnak(Uart_Param *Dane);
	void ST_Gotowy(Uart_Param *Dane);
	void ST_OdebranyZnak(Uart_Param *Dane);
	void ST_OdebranyString(Uart_Param *Dane);
	void ST_Blad(Uart_Param *Dane);
	void ST_Wysylam(Uart_Param *Dane);
	void ST_Nic(Uart_Param *Dane);
	void ST_Cos(Uart_Param *Dane);
private:
	void (Uart::*wsk_f[10])(Uart_Param *Dane);
	enum Stany {ST_GOTOWY = 0, ST_ODEBRANY_ZNAK, ST_ODEBRANY_STRING, ST_BLAD};
	uint8_t i;
	uint8_t buf[30];
};

#endif /* UART_H_ */
