
class Moveobject: public Object {
		
	public:
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
		
		
		//######### fungsi object1 bisa bergerak, jika setelah bergerak tidak kena object2 #########
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
			//cout << "canTurnLeft" << endl;
			//cout << coordLeft() << ">" << object2.coordRight() << endl;
			//cout << coordRight() << "<=" << object2.coordLeft() << endl;
			//cout << coordDown() << ">=" << object2.coordTop() << endl;
			//cout << coordTop() << "<=" << object2.coordDown() << endl;
			//cout << endl;
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
		
		//########## Fungsi object1 tidak kena object lain #############
		bool notHitTop(Object object[]){
			for(int i=0; i<(int)sizeof(&object); i++){
				if(!(canTurnUp(object[i])))
					return false;
			}
			return true;
		}
		bool notHitDown(Object object[]){
			for(int i=0; i<(int)sizeof(&object); i++){
				if(!(canTurnDown(object[i])))
					return false;
			}
			return true;
		}
		bool notHitLeft(Object object[]){
			for(int i=0; i<(int)sizeof(&object); i++){
				if(!(canTurnLeft(object[i])))
					return false;
			}
			return true;
		}
		bool notHitRight(Object object[]){
			for(int i=0; i<(int)sizeof(&object); i++){
				if(!(canTurnRight(object[i])))
					return false;
			}
			return true;
		}
		
};


