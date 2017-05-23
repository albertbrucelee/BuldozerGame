
GLubyte colorBuldozer[3] = {178, 68, 3};
class Buldozer{
	float x;
	float y;
	float width;
	float height;
	
	public:

	Buldozer(){
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
	
	
	//### fungsi buldozer tidak kena object ###
	//true jika turn up tidak kena object
	bool canTurnUp(Wall& object){
		if(coordTop()<object.coordDown())	// posisi buldozer di bawah object. canTurnUp jika coord paling atas buldozer kurang dari coord paling bawah object. jika coord nempel (<=), tidak bisa
			return true;
		if(coordDown()>=object.coordTop())	// posisi buldozer di atas object. canTurnUp jika coord paling bawah buldozer lebih dari atau sama dengan coord paling atas object
			return true;
		if(coordRight()<=object.coordLeft())	// posisi buldozer di kiri object. canTurnUp jika coord paling kanan buldozer kurang dari atau sama dengan coord paling kiri object
			return true;
		if(coordLeft()>=object.coordRight())	// posisi buldozer di kanan object. canTurnUp jika coord kiri buldozer lebih dari atau sama dengan coord paling kanan object
			return true;
		return false;
	}
	//true jika turn down tidak kena object
	bool canTurnDown(Wall& object){
		if(coordDown()>object.coordTop())	// posisi buldozer di atas object. canTurnDown jika coord paling bawah buldozer lebih dari coord paling atas object. jika coord nempel (>=), tidak bisa
			return true;
		if(coordTop()<=object.coordDown())	// posisi buldozer di bawah object. canTurnDown jika coord paling atas buldozer kurang dari atau sama dengan coord paling bawah object
			return true;
		if(coordRight()<=object.coordLeft())	// posisi buldozer di kiri object. canTurnDown jika coord paling kanan buldozer kurang dari atau sama dengan coord paling kiri object
			return true;
		if(coordLeft()>=object.coordRight())	// posisi buldozer di kanan object. canTurnDown jika coord kiri buldozer lebih dari atau sama dengan coord paling kanan object
			return true;
		return false;
	}
	//true jika turn left tidak kena object
	bool canTurnLeft(Wall& object){
		if(coordLeft()>object.coordRight())	// posisi buldozer di kanan object. canTurnLeft jika coord kiri buldozer lebih dari coord paling kanan object. jika coord nempel (>=), tidak bisa
			return true;
		if(coordRight()<=object.coordLeft())	// posisi buldozer di kiri object. canTurnLeft jika coord paling kanan buldozer kurang dari atau sama dengan coord paling kiri object
			return true;
		if(coordDown()>=object.coordTop())	// posisi buldozer di atas object. canTurnLeft jika coord paling bawah buldozer lebih dari atau sama dengan coord paling atas object
			return true;
		if(coordTop()<=object.coordDown())	// posisi buldozer di bawah object. canTurnLeft jika coord paling atas buldozer kurang dari atau sama dengan coord paling bawah object
			return true;
		return false;
	}
	//true jika turn right tidak kena object
	bool canTurnRight(Wall& object){
		if(coordRight()<object.coordLeft())	// posisi buldozer di kiri object. canTurnRight jika coord paling kanan buldozer kurang dari coord paling kiri object. jika coord nempel (<=), tidak bisa
			return true;
		if(coordLeft()>=object.coordRight())	// posisi buldozer di kanan object. canTurnRight jika coord kiri buldozer lebih dari atau sama dengan coord paling kanan object
			return true;
		if(coordDown()>=object.coordTop())	// posisi buldozer di atas object. canTurnRight jika coord paling bawah buldozer lebih dari atau sama dengan coord paling atas object
			return true;
		if(coordTop()<=object.coordDown())	// posisi buldozer di bawah object. canTurnRight jika coord paling atas buldozer kurang dari atau sama dengan coord paling bawah object
			return true;
		return false;
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
      glColor3ubv(colorBuldozer);
      quads(width,height);
		glPopMatrix();
	}
};
