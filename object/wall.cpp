
GLubyte colorWall[3] = {66, 244, 101};
class Wall: public Object{
	
	public:
		void display(){
			glColor3ubv(colorWall);
			Object::display();
		}
};
