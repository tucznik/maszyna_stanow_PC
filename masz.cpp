/*
 * main.cpp
 *
 *  Created on: 13 cze 2017
 *      Author: tomek
 */

#include <inttypes.h>
#include <iostream>
using namespace std;

#include "masz.h"

Maszyna::Maszyna() : StanBiezacy(0)
{
	cout << "Podstawowa: Tworze obiekt, stan " << PobierzStan() << endl;
}

void Maszyna::ZmienStan(uint16_t NowyStan)
{
	StanBiezacy = NowyStan;
}

uint16_t Maszyna::PobierzStan()
{
	return StanBiezacy;
}
void Maszyna::Zdarzenie(uint16_t NowyStan, Param *Dane)
{
	JestZdarzenie = true;
	ZmienStan(NowyStan);
	while(JestZdarzenie)
	{
		(this->*wsk_f[StanBiezacy])(Dane);
		JestZdarzenie = false;
	}
}

void Maszyna::ZdarzenieWewn(uint16_t NowyStan, Param *Dane)
{
	ZmienStan(NowyStan);
	(this->*wsk_f[StanBiezacy])(Dane);
}
