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

class Param_Uart : public Param
{
public:
	uint8_t znak;
};

class Uart : public Maszyna
{
public:
	Uart();
	void ZD_NowyZnak(Param_Uart *Dane);
	void ST_Gotowy(Param_Uart *Dane);
	void ST_OdebranyZnak(Param_Uart *Dane);
	void ST_OdebranyString(Param_Uart *Dane);
	void ST_Blad(Param_Uart *Dane);
	void ST_Wysylam(Param_Uart *Dane);
	void ST_Nic(Param_Uart *Dane);
	void ST_Cos(Param_Uart *Dane);
private:
	void (Uart::*wsk_f[10])(Param_Uart *Dane);
	enum Stany {ST_GOTOWY = 0, ST_ODEBRANY_ZNAK, ST_ODEBRANY_STRING, ST_BLAD, ST_WYSYLAM, ST_NIC, ST_COS};
	uint8_t i;
	uint8_t buf[30];
};

#endif /* UART_H_ */
