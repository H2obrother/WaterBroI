 /* Implement  a class  to represent the RM battle field */


using namespace std;
//start with chess board 
class battlefield{
typedef struct 
	int width height;	//normally the battlefield will be squre means width == height
	int mapSacle;		//map distance  * mapScale == realWorld Distance ,it probably 
				//is not a interger,just pick a interger.


public:
	battlefield(int _width,int _mapSacle);
	battlefield();
	~battlefield();
}

battlefield::battlefield(int _width,int _mapSacle){
	if(_width < 0 || _mapSacle <0)
		throw runtime_error.what("battleField size can't be negative");

}
