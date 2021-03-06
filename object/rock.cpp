
GLubyte colorRock[3] = {66, 185, 244};
char textureRock[] = "texture/box.tga";
char textureRockDone[] = "texture/box_done.tga";
char rockSound[] = "sound/rock.wav";
int rockSoundVolume = 80;

class Rock: public Moveobject{
	public:
		Rock(){
			setSound(rockSound, rockSoundVolume);
		}
		void display(){
			setTexture(textureRock);
			Object::display();
		}
		void displayDone(){
			setTexture(textureRockDone);
			Object::display();
		}
		
		bool notHitTopRock(Rock object[], int n, int index){
			for(int i=0; i<n; i++){
				if(index!=i){
					if(n==6) //cout << "#" << i ;
					//if(n==6) //cout<< "#" << i << " " << index << endl;
					if(!(canTurnUp(object[i])))
						return false;
				}
			}
			//cout << "#true" << endl;
			return true;
		}
		bool notHitDownRock(Rock object[], int n, int index){
			for(int i=0; i<n; i++){
				if(index!=i){
					if(n==6) //cout << "#" << i ;
					//if(n==6) //cout<< "#" << i << " " << index << endl;
					if(!(canTurnDown(object[i])))
						return false;
				}
			}
			//cout << "#true" << endl;
			return true;
		}
		bool notHitLeftRock(Rock object[], int n, int index){
			for(int i=0; i<n; i++){
				if(index!=i){
					if(n==6) //cout << "#" << i ;
					//if(n==6) //cout<< "#" << i << " " << index << endl;
					if(!(canTurnLeft(object[i])))
						return false;
				}
			}
			//cout << "#true" << endl;
			return true;
		}
		bool notHitRightRock(Rock object[], int n, int index){
			for(int i=0; i<n; i++){
				if(index!=i){
					if(n==6) //cout << "#" << i ;
					//if(n==6) //cout<< "#" << i << " " << index << endl;
					if(!(canTurnRight(object[i])))
						return false;
				}
			}
			//cout << "#true" << endl;
			return true;
		}
		/*
		//############ Apakah Object tidak berhimpit dengan batu lain ############
		bool notHitRockTop(Rock rock[], int index){
			for(int i=0; i<totalRock; i++){
				if(index!=i && !(canTurnUp(rock[i])))
					return false;
			}
			return true;
		}
		bool notHitRockDown(Rock rock[], int index){
			for(int i=0; i<totalRock; i++){
				if(index!=i && !(canTurnDown(rock[i])))
					return false;
			}
			return true;
		}
		bool notHitRockLeft(Rock rock[], int index){
			for(int i=0; i<totalRock; i++){
				if(index!=i && !(canTurnLeft(rock[i])))
					return false;
			}
			return true;
		}
		bool notHitRockRight(Rock rock[], int index){
			for(int i=0; i<totalRock; i++){
				if(index!=i && !(canTurnRight(rock[i])))
					return false;
			}
			return true;
		}
		*/
		
		
		//fungsi apakah rock telah diatas point
		//true jika coord atas batu sama dengan coord atas object, coord bawah batu sama dengan coord bawah object, coord kiri batu sama dengan coord kiri object, coord kanan batu sama dengan coord kanan object, 
		//return id point jika true
		//return -1 jika tidak
		int calcPoint(Object object[]){
			for(int i=0; i<totalRock; i++){
				////cout << "calcPoint" << i << endl;
				////cout << coordTop() << " " << object[i].coordTop() << endl;
				////cout << coordDown() << " " << object[i].coordDown() << endl;
				////cout << coordLeft() << " " << object[i].coordLeft() << endl;
				////cout << coordRight() << " " << object[i].coordRight() << endl;
				////cout << endl;
				if(coordTop()!=object[i].coordTop())
					continue;
				if(coordDown()!=object[i].coordDown())	
					continue;
				if(coordLeft()!=object[i].coordLeft())	
					continue;
				if(coordRight()==object[i].coordRight())
					return i;			
			}
			return -1;
		}
		
		//fungsi apakah rock berhimpit dengan tembok
		bool calcFailed(Object object[]){
			//tembok kiri
			if(coordLeft() == object[0].coordRight())
				return true;
			//tembok atas
			if(coordTop() == object[1].coordDown())
				return true;
			//tembok kanan
			if(coordRight() == object[2].coordLeft())
				return true;
			//tembok bawah
			if(coordDown() == object[3].coordTop())
				return true;
			return false;
		}
};
