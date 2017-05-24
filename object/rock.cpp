
GLubyte colorRock[3] = {66, 185, 244};
class Rock: public Object{
	
	public:
	void display(){
		glColor3ubv(colorRock);
		Object::display();
	}
	
	bool noRockAbove(Rock rock[], int index){
		for(int i=0; i<(int)sizeof(&rock); i++){
			if(index!=i && !(canTurnUp(rock[i])))
				return false;
		}
		return true;
	}
	bool noRockBelow(Rock rock[], int index){
		for(int i=0; i<(int)sizeof(&rock); i++){
			if(index!=i && !(canTurnDown(rock[i])))
				return false;
		}
		return true;
	}
	bool noRockLeft(Rock rock[], int index){
		for(int i=0; i<(int)sizeof(&rock); i++){
			if(index!=i && !(canTurnLeft(rock[i])))
				return false;
		}
		return true;
	}
	bool noRockRight(Rock rock[], int index){
		for(int i=0; i<(int)sizeof(&rock); i++){
			if(index!=i && !(canTurnRight(rock[i])))
				return false;
		}
		return true;
	}
};
