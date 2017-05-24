
class Object{
	float x;
	float y;
	float width;
	float height;
	
	public:

	Object(){
	}
	
	void set(float x2, float y2, float width2, float height2){
		x=x2;
		y=y2;
		width=width2;
		height=height2;
		//color=color2;
	}
	
	void turnLeft(){
		x--;
	}
	void turnUp(){
		y++;
	}
	void turnRight(){
		x++;
	}
	void turnDown(){
		y--;
	}
	
	float coordTop(){
		return y+height;
	}
	float coordDown(){
		return y;
	}
	float coordLeft(){
		return x;
	}
	float coordRight(){
		return x+width;
	}
	
	
	//### fungsi object1 tidak kena object2 ###
	//true jika turn up tidak kena object2
	bool canTurnUp(Object& object2){
		if(coordTop()<object2.coordDown())	// posisi object1 di bawah object2. canTurnUp jika coord paling atas object1 kurang dari coord paling bawah object2. jika coord nempel (<=), tidak bisa
			return true;
		if(coordDown()>=object2.coordTop())	// posisi object1 di atas object2. canTurnUp jika coord paling bawah object1 lebih dari atau sama dengan coord paling atas object2
			return true;
		if(coordRight()<=object2.coordLeft())	// posisi object1 di kiri object2. canTurnUp jika coord paling kanan object1 kurang dari atau sama dengan coord paling kiri object2
			return true;
		if(coordLeft()>=object2.coordRight())	// posisi object1 di kanan object2. canTurnUp jika coord kiri object1 lebih dari atau sama dengan coord paling kanan object2
			return true;
		return false;
	}
	//true jika turn down tidak kena object2
	bool canTurnDown(Object& object2){
		if(coordDown()>object2.coordTop())	// posisi object1 di atas object2. canTurnDown jika coord paling bawah object1 lebih dari coord paling atas object2. jika coord nempel (>=), tidak bisa
			return true;
		if(coordTop()<=object2.coordDown())	// posisi object1 di bawah object2. canTurnDown jika coord paling atas object1 kurang dari atau sama dengan coord paling bawah object2
			return true;
		if(coordRight()<=object2.coordLeft())	// posisi object1 di kiri object2. canTurnDown jika coord paling kanan object1 kurang dari atau sama dengan coord paling kiri object2
			return true;
		if(coordLeft()>=object2.coordRight())	// posisi object1 di kanan object2. canTurnDown jika coord kiri object1 lebih dari atau sama dengan coord paling kanan object2
			return true;
		return false;
	}
	//true jika turn left tidak kena object2
	bool canTurnLeft(Object& object2){
		if(coordLeft()>object2.coordRight())	// posisi object1 di kanan object2. canTurnLeft jika coord kiri object1 lebih dari coord paling kanan object2. jika coord nempel (>=), tidak bisa
			return true;
		if(coordRight()<=object2.coordLeft())	// posisi object1 di kiri object2. canTurnLeft jika coord paling kanan object1 kurang dari atau sama dengan coord paling kiri object2
			return true;
		if(coordDown()>=object2.coordTop())	// posisi object1 di atas object2. canTurnLeft jika coord paling bawah object1 lebih dari atau sama dengan coord paling atas object2
			return true;
		if(coordTop()<=object2.coordDown())	// posisi object1 di bawah object2. canTurnLeft jika coord paling atas object1 kurang dari atau sama dengan coord paling bawah object2
			return true;
		return false;
	}
	//true jika turn right tidak kena object2
	bool canTurnRight(Object& object2){
		if(coordRight()<object2.coordLeft())	// posisi object1 di kiri object2. canTurnRight jika coord paling kanan object1 kurang dari coord paling kiri object2. jika coord nempel (<=), tidak bisa
			return true;
		if(coordLeft()>=object2.coordRight())	// posisi object1 di kanan object2. canTurnRight jika coord kiri object1 lebih dari atau sama dengan coord paling kanan object2
			return true;
		if(coordDown()>=object2.coordTop())	// posisi object1 di atas object2. canTurnRight jika coord paling bawah object1 lebih dari atau sama dengan coord paling atas object2
			return true;
		if(coordTop()<=object2.coordDown())	// posisi object1 di bawah object2. canTurnRight jika coord paling atas object1 kurang dari atau sama dengan coord paling bawah object2
			return true;
		return false;
	}
	
	
	
	//### fungsi buldozer kena object ###
	//true jika nempel dengan object
	bool canPushUp(Object& object){
		if(coordTop()<object.coordDown())	// posisi buldozer di bawah object. tidak bisa push jika coord paling atas object kurang dari coord paling bawah object (tidak nempel)
			return false;
		if(coordDown()>=object.coordTop())	// posisi buldozer di atas object. tidak bisa push jika coord paling bawah buldozer lebih dari atau sama dengan coord paling atas object. karena buldozer berada di atas object
			return false;
		if(coordRight()<=object.coordLeft())	// posisi buldozer di kiri object. tidak bisa push jika coord paling kanan buldozer kurang dari atau sama dengan coord paling kiri object. karena buldozer berada di kiri object
			return false;
		if(coordLeft()>=object.coordRight())	// posisi buldozer di kanan object. tidak bisa push jika coord paling kiri buldozer lebih dari atau sama dengan paling kanan object. karena buldozer berada di kanan object
			return false;
		return true;
	}
	//true jika nempel dengan object
	bool canPushDown(Object& object){
		if(coordDown()>object.coordTop())	// posisi buldozer di atas object. tidak bisa push jika coord paling bawah buldozer lebih dari coord paling atas object (tidak nempel)
			return false;
		if(coordTop()<=object.coordDown())	// posisi buldozer di bawah object. tidak bisa push jika coord paling atas buldozer kurang dari atau sama dengan coord paling bawah object. karena buldozer berada di bawah object
			return false;
		if(coordRight()<=object.coordLeft())	// posisi buldozer di kiri object. tidak bisa push jika coord paling kanan buldozer kurang dari atau sama dengan coord paling kiri object. karena buldozer berada di kiri object
			return false;
		if(coordLeft()>=object.coordRight())	// posisi buldozer di kanan object. tidak bisa push jika coord paling kiri buldozer lebih dari atau sama dengan coord paling kanan object. karena buldozer berada di kanan object
			return false;
		return true;
	}
	//true jika nempel dengan object
	bool canPushLeft(Object& object){
		if(coordLeft()>object.coordRight())	// posisi buldozer di kanan object. tidak bisa push jika coord paling kiri buldozer lebih dari coord paling kanan object (tidak nempel)
			return false;
		if(coordRight()<=object.coordLeft())	// posisi buldozer di kiri object. tidak bisa push jika coord paling kanan buldozer kurang dari atau sama dengan coord paling kiri object. karena buldozer berada di kiri object
			return false;
		if(coordDown()>=object.coordTop())	// posisi buldozer di atas object. tidak bisa push jika coord paling bawah buldozer lebih dari atau sama dengan coord paling atas object. karena buldozer berada di atas object
			return false;
		if(coordTop()<=object.coordDown())	// posisi buldozer di bawah object. tidak bisa push jika coord paling atas buldozer kurang dari atau sama dengan coord paling bawah object. karena buldozer berada di bawah object
			return false;
		return true;
	}
	//true jika nempel dengan object
	bool canPushRight(Object& object){
		if(coordRight()<object.coordLeft())	// posisi buldozer di kiri object. tidak bisa push jika coord paling kanan buldozer kurang dari coord paling kiri object (tidak nempel)
			return false;
		if(coordLeft()>=object.coordRight())	// posisi buldozer di kanan object. tidak bisa push jika coord paling kiri buldozer lebih dari atau sama dengan coord paling kanan object. karena buldozer berada di kanan object
			return false;
		if(coordDown()>=object.coordTop())	// posisi buldozer di atas object. tidak bisa push jika coord paling bawah buldozer lebih dari atau sama dengan coord paling atas object. karena buldozer berada di atas object
			return false;
		if(coordTop()<=object.coordDown())	// posisi buldozer di bawah object. tidak bisa push jika coord paling atas buldozer kurang dari atau sama dengan coord paling bawah object. karena buldozer berada di  object
			return false;
		return true;
	}
	
	void quads(float w, float h){
		glBegin(GL_QUADS);
			glVertex2f(0, 0);
			glVertex2f(0+w, 0);
			glVertex2f(0+w, 0+h);
			glVertex2f(0, 0+h);
		glEnd();
	}


	void display(){
		glPushMatrix();
			glTranslatef(x,y,0);
			quads(width,height);
		glPopMatrix();
	}
};

