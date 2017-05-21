
GLubyte colorBuldozer[3] = {178, 68, 3};
class Buldozer{
	public:

  float x;
  float y;
  float width;
  float height;

	Buldozer(float x2, float y2, float width2, float height2){
		x=x2;
		y=y2;
		width=width2;
		height=height2;
		//color=color2;
	}
	
	void turnLeft(){
		x--;
	}
	void turnUp(){
		y++;
	}
	void turnRight(){
		x++;
	}
	void turnDown(){
		y--;
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
      glColor3ubv(colorBuldozer);
      quads(width,height);
		glPopMatrix();
	}
};
