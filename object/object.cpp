
GLubyte colorObject[3] = {178, 68, 3};
class Object{
	protected:
		float x;
		float y;
		float width;
		float height;
	
	private:
		
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
	
	protected:
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
		
	public:
		void set(float width2, float height2, float x2, float y2){
			x=x2;
			y=y2;
			width=width2;
			height=height2;
			//color=color2;
		}
		
		void moveLeft(){
			x--;
		}
		void moveUp(){
			y++;
		}
		void moveRight(){
			x++;
		}
		void moveDown(){
			y--;
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
		bool existRockAbove(Object& object){
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
		bool existRockBelow(Object& object){
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
		bool existRockLeft(Object& object){
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
		bool existRockRight(Object& object){
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
		
		bool noObjectAbove(Object object[]){
			for(int i=0; i<(int)sizeof(&object); i++){
				if(!(canTurnUp(object[i])))
					return false;
			}
			return true;
		}
		bool noObjectBelow(Object object[]){
			for(int i=0; i<(int)sizeof(&object); i++){
				if(!(canTurnDown(object[i])))
					return false;
			}
			return true;
		}
		bool noObjectLeft(Object object[]){
			for(int i=0; i<(int)sizeof(&object); i++){
				if(!(canTurnLeft(object[i])))
					return false;
			}
			return true;
		}
		bool noObjectRight(Object object[]){
			for(int i=0; i<(int)sizeof(&object); i++){
				if(!(canTurnRight(object[i])))
					return false;
			}
			return true;
		}
};

