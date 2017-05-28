
GLubyte colorPoint[3] = {255, 68, 3};
class Point: public Object{
	
	public:
		void display(){
			glColor3ubv(colorPoint);
			Object::display();
		}
	
};
