/*
 * gameunit.hh
 *
 *  Created on: Nov 25, 2018
 *      Author: h2obrother
 */

#ifndef GAMEUNIT_HH_
#define GAMEUNIT_HH_


#include "battlefield.hh"

enum unitType  {EMPTY,OCCUPIED,BASE,INFANTRY,SENTRY,ENGINEER,DRONE};

class gameUnit{ //base class of all game unit, hero ,infantry, sentry ,etc

	unitType role;
	uint HP;
	Point position;
	bool isTeammate;// True means teammate , False means enemy
	uint  buffStatus;// |2 unattackable(only for base and drone) |1 increase 50 % hurts|0 ignore 50% hurts
    float volcity;// unit in m/s
    uint  damagePerSec;

public:
	gameUnit(){};
	gameUnit(unitType uT,Point &initPos,uint healthPoint, bool _isTeammate);
	virtual ~gameUnit(){};

	uint getHP(){return HP;}

	Point getPosition(){return  position;};

};

class base : public gameUnit{

public:
	base(Point &loc,uint _hp = 300){role = BASE;position = loc;HP = _hp;volcity = 0;damagePerSec = 0;};
	~base(){};

};

class infantry : public gameUnit{

public:
	infantry(Point &loc,uint _hp = 200,uint damPS = 10,float v = 10){role = BASE;position = loc;HP = _hp;volcity = v;damagePerSec = damPS;};

}


#endif /* GAMEUNIT_HH_ */
