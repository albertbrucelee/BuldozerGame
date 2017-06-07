template<typename T, size_t N>
size_t arraySize( T(&)[N] )
{
  return(N);
}
class Moveobject: public Object {
	Sound sound;
		
	public:
		void setSound(char *soundLocation, int volume){
			sound.set(soundLocation, volume);
		}
		void moveLeft(){
			sound.stop();
			sound.play();
			x--;
		}
		void moveUp(){
			sound.stop();
			sound.play();
			y++;
		}
		void moveRight(){
			sound.stop();
			sound.play();
			x++;
		}
		void moveDown(){
			sound.stop();
			sound.play();
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
		//index adalah kode object yg dikecualikan (tidak ikut diperhitungkan)
		//set index=-1, jika tidak ada pengecualian
		bool notHitTop(Object object[], int n, int index){
			for(int i=0; i<n; i++){
				if(index!=i){
					if(!(canTurnUp(object[i])))
						return false;
				}
			}
			return true;
		}
		bool notHitDown(Object object[], int n, int index){
			for(int i=0; i<n; i++){
				if(index!=i){
					if(!(canTurnDown(object[i])))
						return false;
				}
			}
			return true;
		}
		bool notHitLeft(Object object[], int n, int index){
			for(int i=0; i<n; i++){
				if(index!=i){
					if(!(canTurnLeft(object[i])))
						return false;
				}
			}
			return true;
		}
		bool notHitRight(Object object[], int n, int index){
			for(int i=0; i<n; i++){
				if(index!=i){
					if(!(canTurnRight(object[i])))
						return false;
				}
			}
			return true;
		}
		
};


