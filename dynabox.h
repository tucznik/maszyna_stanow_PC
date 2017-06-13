/*
 * dynabox.h
 *
 *  Created on: 13 cze 2017
 *      Author: tomek
 */

#ifndef DYNABOX_H_
#define DYNABOX_H_

class Dynabox_Param : public Param
{

};

class Dynabox : public Maszyna
{
public:
	const char * PrzedstawSie() {return "Dynabox";}
};



#endif /* DYNABOX_H_ */
