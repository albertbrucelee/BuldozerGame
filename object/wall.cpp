
GLubyte colorWall[3] = {66, 244, 101};
class Wall{
	float x;
	float y;
	float width;
	float height;
	
	public:

	void set(float width2, float height2, float x2, float y2){
		x=x2;
		y=y2;
		width=width2;
		height=height2;
		//color=color2;
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
	/*
	bool hitLeft(Buldozer *buldozer){
		//jika buldozer di sebelah kiri
		if(buldozer->coordRight < coordLeft())
			return false;
		//jika tidak kena batas bawah object (kondisi buldozer dibawah object)
		if(!(buldozer.coordDown<coordDown && buldozer.coordUp<coordDown))
			return false;
		//jika tidak kena batas atas object (kondisi buldozer diatas object)
		if(!(buldozer.coordUp>coordUp && buldozer.coordDown>coordUp))
			return false;
		return true;
		
	}
	*/
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
      glColor3ubv(colorWall);
      quads(width,height);
		glPopMatrix();
	}
};
