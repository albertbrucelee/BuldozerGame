
GLubyte colorWin[3] = {23, 10, 209};
GLubyte colorLoose[3] = {214, 10, 10};
class Finish{
	
	float x;
	float y;
	float width;
	float height;
	
	public:
		Finish(){
			width = 100;
			height = 50;
			
			x = -width/2;
			y = -height/2;
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
				quads(width,height);
			glPopMatrix();
		}
		void displayLoose(){
			glColor3ubv(colorLoose);
			display();
		}
		void displayWin(){
			glColor3ubv(colorWin);
			display();
		}
};
