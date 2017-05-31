
GLubyte colorBuldozer[3] = {178, 68, 3};
char textureBuldozer[] = "texture/Buldozer.tga";
class Buldozer: public Moveobject{
	
	public:
	
		void display(){
			//glColor3ubv(colorBuldozer);
			setTexture(textureBuldozer);
			Object::display();
		}
		
		//############ Apakah buldozer kena object lain ############
		//true jika nempel dengan object
		bool hitRockTop(Object& object){
			if(coordTop()<object.coordDown())	// posisi buldozer di bawah object. tidak bisa push jika coord paling atas object kurang dari coord paling bawah object (tidak nempel)
				return false;
			if(coordDown()>=object.coordTop())	// posisi buldozer di atas object. tidak bisa push jika coord paling bawah buldozer lebih dari atau sama dengan coord paling atas object. karena buldozer berada di atas object
				return false;
			if(coordRight()<=object.coordLeft())	// posisi buldozer di kiri object. tidak bisa push jika coord paling kanan buldozer kurang dari atau sama dengan coord paling kiri object. karena buldozer berada di kiri object
				return false;
			if(coordLeft()>=object.coordRight())	// posisi buldozer di kanan object. tidak bisa push jika coord paling kiri buldozer lebih dari atau sama dengan paling kanan object. karena buldozer berada di kanan object
				return false;
			return true;
		}
		//true jika nempel dengan object
		bool hitRockDown(Object& object){
			if(coordDown()>object.coordTop())	// posisi buldozer di atas object. tidak bisa push jika coord paling bawah buldozer lebih dari coord paling atas object (tidak nempel)
				return false;
			if(coordTop()<=object.coordDown())	// posisi buldozer di bawah object. tidak bisa push jika coord paling atas buldozer kurang dari atau sama dengan coord paling bawah object. karena buldozer berada di bawah object
				return false;
			if(coordRight()<=object.coordLeft())	// posisi buldozer di kiri object. tidak bisa push jika coord paling kanan buldozer kurang dari atau sama dengan coord paling kiri object. karena buldozer berada di kiri object
				return false;
			if(coordLeft()>=object.coordRight())	// posisi buldozer di kanan object. tidak bisa push jika coord paling kiri buldozer lebih dari atau sama dengan coord paling kanan object. karena buldozer berada di kanan object
				return false;
			return true;
		}
		//true jika nempel dengan object
		bool hitRockLeft(Object& object){
			if(coordLeft()>object.coordRight())	// posisi buldozer di kanan object. tidak bisa push jika coord paling kiri buldozer lebih dari coord paling kanan object (tidak nempel)
				return false;
			if(coordRight()<=object.coordLeft())	// posisi buldozer di kiri object. tidak bisa push jika coord paling kanan buldozer kurang dari atau sama dengan coord paling kiri object. karena buldozer berada di kiri object
				return false;
			if(coordDown()>=object.coordTop())	// posisi buldozer di atas object. tidak bisa push jika coord paling bawah buldozer lebih dari atau sama dengan coord paling atas object. karena buldozer berada di atas object
				return false;
			if(coordTop()<=object.coordDown())	// posisi buldozer di bawah object. tidak bisa push jika coord paling atas buldozer kurang dari atau sama dengan coord paling bawah object. karena buldozer berada di bawah object
				return false;
			return true;
		}
		//true jika nempel dengan object
		bool hitRockRight(Object& object){
			if(coordRight()<object.coordLeft())	// posisi buldozer di kiri object. tidak bisa push jika coord paling kanan buldozer kurang dari coord paling kiri object (tidak nempel)
				return false;
			if(coordLeft()>=object.coordRight())	// posisi buldozer di kanan object. tidak bisa push jika coord paling kiri buldozer lebih dari atau sama dengan coord paling kanan object. karena buldozer berada di kanan object
				return false;
			if(coordDown()>=object.coordTop())	// posisi buldozer di atas object. tidak bisa push jika coord paling bawah buldozer lebih dari atau sama dengan coord paling atas object. karena buldozer berada di atas object
				return false;
			if(coordTop()<=object.coordDown())	// posisi buldozer di bawah object. tidak bisa push jika coord paling atas buldozer kurang dari atau sama dengan coord paling bawah object. karena buldozer berada di  object
				return false;
			return true;
		}
	
};
