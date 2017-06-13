/*
 * lockerbox.h
 *
 *  Created on: 13 cze 2017
 *      Author: tomek
 */

#ifndef LOCKERBOX_H_
#define LOCKERBOX_H_
#include "masz.h"

class Lockerbox_Param : public Param
{

};

class Lockerbox : public Maszyna
{
public:
//	Lockerbox();
	const char * PrzedstawSie() {return "Lockerbox";}
};


#endif /* LOCKERBOX_H_ */
