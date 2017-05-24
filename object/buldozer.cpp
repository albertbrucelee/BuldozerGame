
GLubyte colorBuldozer[3] = {178, 68, 3};
class Buldozer: public Object{
	
	public:
	void display(){
		glColor3ubv(colorBuldozer);
		Object::display();
	}
	
	
};
