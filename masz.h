/*
 * masz.h
 *
 *  Created on: 13 cze 2017
 *      Author: tomek
 */

#ifndef MASZ_H_
#define MASZ_H_

class Param
{
public:

};

class Maszyna
{
public:
	Maszyna();
	uint16_t PobierzStan();
	void Zdarzenie(uint16_t NowyStan, Param *Dane = NULL);
	void ZdarzenieWewn(uint16_t NowyStan, Param *Dane);
protected:
	uint16_t StanBiezacy;
private:
	bool JestZdarzenie;
	void ZmienStan(uint16_t nowy_stan);
	void SilnikStanow();
	void (Maszyna::*wsk_f[])(Param *Dane);
	enum Stany {ST_NIEDOZWOLONY = 0xFF};
};

#endif /* MASZ_H_ */
