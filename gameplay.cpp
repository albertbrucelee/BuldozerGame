

Wall wall[totalWall];
Rock rock[totalRock];
Point point[totalRock];

Buldozer buldozer;

/*
//pasangan rock dengan point. nilai 0 jika rock tidak berpasangan. bernilai index point, jika rock berpasangan
int pairedRockPoint[totalRock];
//total rock yang telah di atas point
int totalRockFinish;
*/
//pasangan rock dengan point. nilai 0 jika rock tidak berpasangan. bernilai index point, jika rock berpasangan
map<int, int> finishRock;
map<int, int>::iterator finishRock_it;
//rock berhimpit dengan tembok
bool rockFailed;


class Gameplay{
	private:
	
	public:
		void restart(){
			createObject();
		}
		//membuat semua object
		void createObject(){
			//for(int i=0; i<totalRock; i++)
			//	pairedRockPoint[i] = -1;
			//totalRockFinish = 0;
			rockFailed = false;
			
			buldozer.set(WIDTH,WIDTH, 0, -10);
			
			wall[0].set(5,200,-100,-100);	//wall kiri
			wall[1].set(200,5,-100,45);		//wall atas
			wall[2].set(5,200,95,-100);		//wall kanan
			wall[3].set(200,5,-100,-50);	//wall bawah

			wall[4].set(10,20,-70,25);
			wall[5].set(20,10,-80,5);
			wall[6].set(20,10,-70,-15);
			wall[7].set(10,20,-60,-45);
			wall[8].set(10,10,-30,-35);

			wall[9].set(10,20,20,25);
			wall[10].set(10,20,10,15);
			wall[11].set(10,20,0,5);
			wall[12].set(10,40,-10,-25);
			wall[13].set(10,10,-20,25);


			wall[14].set(10,20,30,-45);
			wall[15].set(10,30,40,-35);
			wall[16].set(30,10,40,-25);
			wall[17].set(30,10,30,-5);

			wall[18].set(10,20,50,25);
			wall[19].set(20,10,75,10);

			point[0].set(WIDTH,WIDTH,-80,-15);
			point[1].set(WIDTH,WIDTH,-75,-40);
			point[2].set(WIDTH,WIDTH,-40,-35);
			point[3].set(WIDTH,WIDTH,50,-35);
			point[4].set(WIDTH,WIDTH,80,30);
			point[5].set(WIDTH,WIDTH,80,0);




			rock[0].set(WIDTH,WIDTH,-80,25);	//-20,-25
			rock[1].set(WIDTH,WIDTH,20,-25);
			rock[2].set(WIDTH,WIDTH,10,-10);
			rock[3].set(WIDTH,WIDTH,40,25);
			rock[4].set(WIDTH,WIDTH,65,-10);
			rock[5].set(WIDTH,WIDTH,75,-25);
			
		}
		//display semua object
		void displayObject(){ 
			buldozer.display();
			for(int i=0; i<totalWall; i++){
				wall[i].display();
			}
			for(int i=0; i<totalRock; i++){
				rock[i].display();
			}
			for(int i=0; i<totalRock; i++){
				point[i].display();
			}
			
		}
				
		
		//Menghitung apakah suatu rock berada diatas point
		void calcRockFinish(int i){
			finishRock_it = finishRock.find(i);
			//jika sebelumnya batu belum berpasangan dengan point
			if(finishRock_it == finishRock.end()){
				int indexPoint = rock[i].calcPoint(point);
				//jika batu telah diatas suatu point
				if(indexPoint!=-1){
					finishRock[i] = indexPoint;
					cout << "Finish: Rock-" << i << " with point-" << indexPoint << endl;
					cout << "Total Finish: " << finishRock.size() << endl;
				}
			}
			//jika sebelumnya batu telah berpasangan dengan point, maka lokasi batu sekarang telah bergeser menjadi tidak diatas point
			else{
				cout << "Not Finish: " << i << endl;
				//unset, bahwa batu tidak lagi berpasangan dengan point manapun
				finishRock.erase(i);
			}
			/*
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
			* */
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
					//jika di atas batu tidak ada dinding && di atas batu tidak ada batu yang lain && di atas buldozer tidak ada dinding (kondisi hanya sebagian buldozer yang mengenai batu, dan sebagian lainnya mengenai dinding) && di atas buldozer tidak ada rock lain (kondisi hanya sebagian buldozer yang mengenai batu, dan sebagian lainnya mengenai batu lain)
					if(rock[i].notHitTop(wall,totalWall, -1) && rock[i].notHitTop(rock, totalRock, i) && buldozer.notHitTop(wall,totalWall, -1) && buldozer.notHitTop(rock, totalRock, i)) {	// && rock[i].turnUp(rock)
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
					if(rock[i].notHitDown(wall,totalWall, -1) && rock[i].notHitDown(rock, totalRock, i) && buldozer.notHitDown(wall,totalWall, -1) && buldozer.notHitDown(rock, totalRock, i)) {	// && rock[i].turnUp(rock)
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
					if(rock[i].notHitLeft(wall,totalWall, -1) && rock[i].notHitLeft(rock, totalRock, i) && buldozer.notHitLeft(wall,totalWall, -1) && buldozer.notHitLeft(rock, totalRock, i)) {	// && rock[i].turnUp(rock)
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
					if(rock[i].notHitRight(wall,totalWall, -1) && rock[i].notHitRight(rock, totalRock, i) && buldozer.notHitRight(wall,totalWall, -1) && buldozer.notHitRight(rock, totalRock, i)) {	// && rock[i].turnUp(rock)
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
				if(buldozer.notHitTop(wall, totalWall, -1))
					//buldozer bergerak ke atas
					buldozer.moveUp();
			}
		}
		void keyDown(){
			if(!pushDown()){
				if(buldozer.notHitDown(wall, totalWall, -1))
					buldozer.moveDown();
			}
		}
		void keyLeft(){
			if(!pushLeft()){
				if(buldozer.notHitLeft(wall, totalWall, -1))
					buldozer.moveLeft();
			}
		}
		void keyRight(){
			if(!pushRight()){
				if(buldozer.notHitRight(wall, totalWall, -1))
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
			if(finishRock.size() == totalRock)
				return true;
			return false;
		}
		
		//kalah
		void loose(){
			//cout << "You loose :( " << endl;
			//tampilkan pop up kalah
			Finish finish;
			finish.displayLoose();
		}
		//menang
		void win(){
			//cout << "You win :) " << endl;
			//tampilkan pop up menang
			Finish finish;
			finish.displayWin();
		}
};
	
