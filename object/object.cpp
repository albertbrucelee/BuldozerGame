
GLubyte colorObject[3] = {178, 68, 3};
class Object{
	protected:
		float x;
		float y;
		float width;
		float height;
	
		
	public:
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
		
		void set(float width2, float height2, float x2, float y2){
			x=x2;
			y=y2;
			width=width2;
			height=height2;
			//color=color2;
		}
		
		
		
};

