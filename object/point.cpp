
GLubyte colorPoint[3] = {255, 68, 3};
char texturePoint[] = "texture/point.tga";
class Point: public Object{
	
	public:
		void display(){
			setTexture(texturePoint);
			Object::display();
		}
	
};
