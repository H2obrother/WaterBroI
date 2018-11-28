 /* battlefield.hh
  *
  *Created on: Nov 25, 2018
  *      Author: h2obrother */


#ifndef BATTLEFIELD_HH
#define BATTLEFIELD_HH

#include <map>
#include <string>
#include <cmath>
#include "gameunit.hh"
#include <stdexcept>
using namespace std;
// A 2-dimensional point class!
// Coordinates are double-precision floating point.
typedef unsigned int uint;
class Point {

private:
  uint x_coord;
  uint y_coord;

public:
  // Constructors
  // default constructor
  Point(){x_coord = 0;y_coord=0;};
  // two-argument constructor
  Point(uint x, uint y){x_coord = x; y_coord=y;};

  // Destructor
  ~Point();

  // Accessor methods
  uint getX(){return x_coord;};
  uint getY(){return y_coord;};

  //compute the distance between 2 points
  double distanceTo(Point& p2){return sqrt(pow(x_coord-p2.getX(), 2) + pow(y_coord - p2.getY(), 2));};
};

class terrain{};//wait for cg learning

//start with chess board 
class battlefield{

	uint width , height;	//normally the battlefield will be squre means width == height
	uint mapSacle;		    //map distance  * mapScale == realWorld Distance unit in cm ,actual value
				            //is not a integer,just pick a integer.
	uint *board;

public:
	//empty battlefield consturtor
	battlefield(uint _width,uint _mapSacle);

	// input: a  map {terrain(key):point(value)} assign terrain to each location
	// specified by the map value as well as a 2d Point.
	// since the sizes shapes of each terrain are unknown,just put a point at 
	// that location 
	battlefield(uint _width, uint _height, uint _mapSacle,map<string,Point>);
	battlefield();
	~battlefield();

	const uint index(uint x,uint y){return width*y+x;};
	//output: 0 empty
	//        1 unrechable
	//        other number corresponding to game unit type

	uint getState(uint x,uint y);
	void setState(uint x,uint y,unitType u);
}


battlefield::battlefield(uint _width, uint _height ,uint _mapSacle){
	if(_width < 0 || _mapSacle <0)
		throw runtime_error("battleField size can't be negative");
	width 	= _width;
	height 	= _height;
	mapSacle=_mapSacle;

	uint	len = width * height;
	board = new uint[len];
	
	// initialize the battle field
	for (int i = 0; i < len; i++) 
		board[i] = 0;
}

battlefield::~battlefield(){
	delete[] board;
};

uint battlefield::getState(uint x,uint y){
    if(x > (width - 1)  || (y > height - 1))
    	throw out_of_range("Don't access outside the battlefield.\n");
	return board[index(x,y)];
}

void battlefield::setState(uint x,uint y,unitType u){
	if(x > (width - 1)  || (y > height - 1))
	    	throw out_of_range("Access outside the battlefield.\n");
	board[index(x,y)] = u;
}
#endif






