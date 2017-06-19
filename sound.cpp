class Sound{
	sf::Music music;
	bool isPlay;
	public:
		Sound(){
			isPlay=false;
		}
		void set(char *location, int volume){
			if (!music.openFromFile(location))
				return; // error
			music.setVolume(volume);
		}
		
		void play(){
			//jika music telah nyala, maka tidak bisa play
			//if(isPlay) return;
			music.play();
			isPlay=true;
		}
		void stop(){
			if(!isPlay)
				return;
			music.stop();
			isPlay=false;
		}
		void loop(){
			music.setLoop(true);
		}
};
