
const float width = 10;

Wall wall[totalWall];
Rock rock[totalRock];
Point point[totalRock];

Buldozer buldozer;

//pasangan rock dengan point. nilai 0 jika rock tidak berpasangan. bernilai index point, jika rock berpasangan
int pairedRockPoint[totalRock];
//total rock yang telah di atas point
int totalRockFinish = 0;
//rock berhimpit dengan tembok
bool rockFailed = false;


class Gameplay{
	private:
	
	public:
		//membuat semua object
		void createObject(){
			for(int i=0; i<totalRock; i++)
				pairedRockPoint[i] = -1;
			
			buldozer.set(10,10, 0, 0);
			
			wall[0].set(5,200,-100,-100);	//wall kiri
			wall[1].set(200,5,-100,45);		//wall atas
			wall[2].set(5,200,95,-100);		//wall kanan
			wall[3].set(200,5,-100,-50);	//wall bawah
			
			wall[4].set(10,30,-10,-15);
			wall[5].set(10,30,10,-15);
			wall[6].set(50,10,-15,-35);
			wall[7].set(50,10,-15,25);
			
			point[0].set(width,width,-50,-20);
			point[1].set(width,width,-75,-40);
			
			rock[0].set(width,width,-20,-25);	//-20,-25
			rock[1].set(width,width,20,-25);
		}
		//display semua object
		void displayObject(){ 
			for(int i=0; i<totalWall; i++){
				wall[i].display();
			}
			
			for(int i=0; i<totalRock; i++){
				point[i].display();
			}
			for(int i=0; i<totalRock; i++){
				rock[i].display();
			}
			
			buldozer.display();
		}
				
		
		//Menghitung apakah suatu rock berada diatas point
		void calcRockFinish(int i){
			//jika sebelumnya batu belum berpasangan dengan point
			if(pairedRockPoint[i]==-1){
				int indexPoint = rock[i].calcPoint(point);
				//jika batu telah diatas suatu point
				if(indexPoint!=-1){
					pairedRockPoint[i] = indexPoint;
					totalRockFinish++;
					cout << "Finish: Rock-" << i << " with point-" << pairedRockPoint[i] << endl;
					cout << "Total Finish: " << totalRockFinish << endl;
				}
			}
			//jika sebelumnya batu telah berpasangan dengan point, maka lokasi batu sekarang telah bergeser menjadi tidak diatas point
			else{
				cout << "Not Finish: " << i << endl;
				//set, bahwa batu tidak lagi berpasangan dengan point manapun
				pairedRockPoint[i] = -1;
				totalRockFinish--;
			}
		}
		//menghitung apakah rock berdempet dengan tembok
		void calcRockFailed(int i){
			if(rock[i].calcFailed(wall))
				rockFailed = true;
		}
		
		//############ Buldozer push batu ############
		bool pushUp(){
			for(int i=0; i<totalRock; i++){
				//jika di atas buldozer ada rock
				if(buldozer.hitRockTop(rock[i])){
					//jika di atas batu tidak ada dinding && di atas batu tidak ada batu yang lain && di atas buldozer tidak ada dinding (kondisi hanya sebagian buldozer yang mengenai batu, dan sebagian lainnya mengenai dinding)
					if(rock[i].notHitTop(wall) && rock[i].notHitRockTop(rock, i) && buldozer.notHitTop(wall)){	// && rock[i].turnUp(rock)
						//buldozer move ke atas
						buldozer.moveUp();
						//rock move ke atas
						rock[i].moveUp();
						
						calcRockFailed(i);
						calcRockFinish(i);
						
						//push berhasil
						return true;
					}
					//true karena di atas buldozer ada rock
					return true;
				}
			}
			return false;
		}
		bool pushDown(){
			for(int i=0; i<totalRock; i++){
				//jika di bawah buldozer ada rock
				if(buldozer.hitRockDown(rock[i])){
					//jika di bawah batu tidak ada dinding && di bawah batu tidak ada batu yang lain
					if(rock[i].notHitDown(wall) && rock[i].notHitRockDown(rock, i) && buldozer.notHitDown(wall)){	// && rock[i].turnUp(rock)
						//buldozer move ke bawah
						buldozer.moveDown();
						//rock move ke bawah
						rock[i].moveDown();
						
						calcRockFailed(i);
						calcRockFinish(i);
						
						//push berhasil
						return true;
					}
					//true karena di bawah buldozer ada rock
					return true;
				}
			}
			return false;
		}
		bool pushLeft(){
			for(int i=0; i<totalRock; i++){
				//jika di kiri buldozer ada rock
				if(buldozer.hitRockLeft(rock[i])){
					//jika di kiri batu tidak ada dinding && di kiri batu tidak ada batu yang lain
					if(rock[i].notHitLeft(wall) && rock[i].notHitRockLeft(rock, i) && buldozer.notHitLeft(wall)){	// && rock[i].turnUp(rock)
						//buldozer move ke kiri
						buldozer.moveLeft();
						//rock move ke kiri
						rock[i].moveLeft();
						
						calcRockFailed(i);
						calcRockFinish(i);
						
						//push berhasil
						return true;
					}
					//true karena di kiri buldozer ada rock
					return true;
				}
			}
			return false;
		}
		bool pushRight(){
			for(int i=0; i<totalRock; i++){
				//jika di kanan buldozer ada rock
				if(buldozer.hitRockRight(rock[i])){
					//jika di kanan batu tidak ada dinding && di kanan batu tidak ada batu yang lain
					if(rock[i].notHitRight(wall) && rock[i].notHitRockRight(rock, i) && buldozer.notHitRight(wall)){	// && rock[i].turnUp(rock)
						//buldozer move ke kanan
						buldozer.moveRight();
						//rock move ke kanan
						rock[i].moveRight();
						
						calcRockFailed(i);
						calcRockFinish(i);
						
						//push berhasil
						return true;
					}
					//true karena di kanan buldozer ada rock
					return true;
				}
			}
			return false;
		}
		
		
		//############ Apa yang dilakukan setelah keyboard ditekan ############
		void keyUp(){
			//panggil buldozer push up
			if(!pushUp()){
				// jika buldozer gagal push up (di atas buldozer tidak ada batu), maka buldozer bisa bergerak ke atas.
				// bisa ke atas jika di atas buldozer tidak ada dinding
				if(buldozer.notHitTop(wall))
					//buldozer bergerak ke atas
					buldozer.moveUp();
			}
		}
		void keyDown(){
			if(!pushDown()){
				if(buldozer.notHitDown(wall))
					buldozer.moveDown();
			}
		}
		void keyLeft(){
			if(!pushLeft()){
				if(buldozer.notHitLeft(wall))
					buldozer.moveLeft();
			}
		}
		void keyRight(){
			if(!pushRight()){
				if(buldozer.notHitRight(wall))
					buldozer.moveRight();
			}
		}
		
		//apakah rock berhimpit tembok
		bool calcFailed(){
			if(rockFailed)
				return true;
			return false;
		}
		//apakah semua rock telah berada di atas point
		bool calcFinish(){
			if(totalRockFinish == totalRock)
				return true;
			return false;
		}
		
		//kalah
		void loose(){
			cout << "You loose :( " << endl;
			//tampilkan pop up kalah
			Finish finish;
			finish.displayLoose();
		}
		//menang
		void win(){
			cout << "You win :) " << endl;
			//tampilkan pop up menang
			Finish finish;
			finish.displayWin();
		}
};
	
