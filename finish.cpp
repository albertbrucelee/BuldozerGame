
GLubyte colorWin[3] = {23, 10, 209};
GLubyte colorLoose[3] = {214, 10, 10};
char textureFinish[] = "texture/win.tga";
char textureLoose[] = "texture/lose.tga";
		
char winSoundLocation[] = "sound/bell.wav";
char loseSoundLocation[] = "sound/explosion.wav";
int finishSoundVolume = 100;

class Finish : public Object{
	float width;
	float height;
	Sound finishMusic;
	bool isFinish;
	
	public:
		Finish(){
			width = 100;
			height = 50;
			isFinish = false;
		}
		
		void glTga(void)
		{
			glEnable (GL_DEPTH_TEST);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

			loadTGA(texture, 1);//load gambar texture box ke bidang

		}
		void quads(float w, float h){
			float tw = 1.0f;	//texture width
			float th = 1.0f;	//texture height
			glEnable(GL_TEXTURE_2D);
			glBindTexture (GL_TEXTURE_2D, 1); 
			glBegin(GL_QUADS);
				//kiri bawah
				glTexCoord2f(0.0f, 0.0f);
				glVertex2f(0, 0);
				//kanan bawah
				glTexCoord2f(tw, 0.0f);
				glVertex2f(0+w, 0);
				//kanan atas
				glTexCoord2f(tw, th);
				glVertex2f(0+w, 0+h);
				//kiri atas
				glTexCoord2f(0.0f, th);
				glVertex2f(0, 0+h);
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}
		void display(){
			set(width, height, -width/2, -height/2);
			glTga();
			glPushMatrix();
				glTranslatef(x,y,0);
				quads(width,height);
			glPopMatrix();
		}
		void displayLoose(){
			setTexture(textureLoose);
			display();
		}
		void displayWin(){
			setTexture(textureFinish);
			display();
		}
		void playLoseSound(){
			if(!isFinish){
				finishMusic.set(loseSoundLocation, finishSoundVolume);
				finishMusic.loop();
				finishMusic.play();
				isFinish = true;
			}
		}
		void playWinSound(){
			if(!isFinish){
				finishMusic.set(winSoundLocation, finishSoundVolume);
				finishMusic.loop();
				finishMusic.play();
				isFinish = true;
			}
		}
		void stop(){
			isFinish = false;
			finishMusic.stop();
		}
		
};
