
GLubyte colorWall[3] = {66, 244, 101};
class Wall{
	public:

  float x;
  float y;
  float width;
  float height;

	Wall(float x2, float y2, float width2, float height2){
		x=x2;
		y=y2;
		width=width2;
		height=height2;
		//color=color2;
	}
	
	float coordUp(){
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
