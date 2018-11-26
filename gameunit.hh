/*
 * gameunit.hh
 *
 *  Created on: Nov 25, 2018
 *      Author: h2obrother
 */

#ifndef GAMEUNIT_HH_
#define GAMEUNIT_HH_


#include "battlefield.hh"

enum unitType  {BASE,INFANTRY,SENTRY,ENGINEER,DRONE};

class gameUnit{ //base class of all game unit, hero ,infantry, sentry ,etc

	unitType role;
	uint hp;
	Point position();
	bool isTeammate;// True means teammate , False means enemy
	int  buffStatus;// |2 unattackable(only for base and drone) |1 increase 50 % hurts|0 ignore 50% hurts


public:
	virtual gameUnit();
	virtual gameUnit(unitType uT,Point initPos,uint healthPoint, bool _isTeammate);
	virtual ~gameUnit();
};



#endif /* GAMEUNIT_HH_ */
