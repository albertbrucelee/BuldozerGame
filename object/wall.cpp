
GLubyte colorWall[3] = {66, 244, 101};
char textureWall[] = "texture/wall.tga";
class Wall: public Object{
	
	public:
		void display(){
			setTexture(textureWall);
			Object::display();
		}
};
