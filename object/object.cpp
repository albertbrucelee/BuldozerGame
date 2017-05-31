
GLubyte colorObject[3] = {178, 68, 3};
class Object{
	protected:
		float x;
		float y;
		float width;
		float height;
		char* texture;
	
		
	public:
		void glTga(void)
		{
			glEnable (GL_DEPTH_TEST);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

			loadTGA(texture, 1);//load gambar texture box ke bidang

		}
		void quads(float w, float h){
			float tw = w/WIDTH;	//texture width
			float th = h/WIDTH;	//texture height
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
		
		void quads2(float w, float h){
			glBegin(GL_QUADS);
				glVertex2f(0, 0);
				glVertex2f(0+w, 0);
				glVertex2f(0+w, 0+h);
				glVertex2f(0, 0+h);
			glEnd();
		}
		
		void display(){
			glTga();
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
		void setTexture(char *texture2){
			texture=texture2;
		}
		
		
		
};

