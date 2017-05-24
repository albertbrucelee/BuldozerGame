
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>

#include "object/grid.cpp"

#include "object/object.cpp"
#include "object/rock.cpp"
#include "object/wall.cpp"
#include "object/buldozer.cpp"


#define totalWall 8
#define totalRock 2

Wall wall[totalWall];
Rock rock[totalRock];

Buldozer buldozer;

void setup_viewport(GLFWwindow* window)
{
    // setting viewports size, projection etc
    //double ratio;
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    //ratio = width / (double) height;
    glViewport(0, 0, width, height);

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100, 100, -50, 50, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


void quads(float width, float height){
	glBegin(GL_QUADS);
		glVertex2f(0, 0);
		glVertex2f(0+width, 0);
		glVertex2f(0+width, 0+height);
		glVertex2f(0, 0+height);
	glEnd();
}


bool pushUp(){
	for(int i=0; i<totalRock; i++){
		//jika di atas buldozer ada rock
		if(buldozer.existRockAbove(rock[i])){
			//jika di atas batu tidak ada dinding && di atas batu tidak ada batu yang lain && di atas buldozer tidak ada dinding (kondisi hanya sebagian buldozer yang mengenai batu, dan sebagian lainnya mengenai dinding)
			if(rock[i].noObjectAbove(wall) && rock[i].noRockAbove(rock, i) && buldozer.noObjectAbove(wall)){	// && rock[i].turnUp(rock)
				//buldozer move ke atas
				buldozer.moveUp();
				//rock move ke atas
				rock[i].moveUp();
				return true;
			}
			//true karena di atas buldozer ada rock
			return true;
		}
	}
	return false;
}
bool pushDown(){
	for(int i=0; i<totalRock; i++){
		//jika di bawah buldozer ada rock
		if(buldozer.existRockBelow(rock[i])){
			//jika di bawah batu tidak ada dinding && di bawah batu tidak ada batu yang lain
			if(rock[i].noObjectBelow(wall) && rock[i].noRockBelow(rock, i) && buldozer.noObjectBelow(wall)){	// && rock[i].turnUp(rock)
				//buldozer move ke bawah
				buldozer.moveDown();
				//rock move ke bawah
				rock[i].moveDown();
				return true;
			}
			//true karena di bawah buldozer ada rock
			return true;
		}
	}
	return false;
}
bool pushLeft(){
	for(int i=0; i<totalRock; i++){
		//jika di kiri buldozer ada rock
		if(buldozer.existRockLeft(rock[i])){
			//jika di kiri batu tidak ada dinding && di kiri batu tidak ada batu yang lain
			if(rock[i].noObjectLeft(wall) && rock[i].noRockLeft(rock, i) && buldozer.noObjectLeft(wall)){	// && rock[i].turnUp(rock)
				//buldozer move ke kiri
				buldozer.moveLeft();
				//rock move ke kiri
				rock[i].moveLeft();
				return true;
			}
			//true karena di kiri buldozer ada rock
			return true;
		}
	}
	return false;
}
bool pushRight(){
	for(int i=0; i<totalRock; i++){
		//jika di kanan buldozer ada rock
		if(buldozer.existRockRight(rock[i])){
			//jika di kanan batu tidak ada dinding && di kanan batu tidak ada batu yang lain
			if(rock[i].noObjectRight(wall) && rock[i].noRockRight(rock, i) && buldozer.noObjectRight(wall)){	// && rock[i].turnUp(rock)
				//buldozer move ke kanan
				buldozer.moveRight();
				//rock move ke kanan
				rock[i].moveRight();
				//push berhasil
				return true;
			}
			//true karena di kanan buldozer ada rock
			return true;
		}
	}
	return false;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	if(action==GLFW_PRESS || action==GLFW_REPEAT){	
		switch(key) {
			// close program on ESC key
			case GLFW_KEY_ESCAPE:
				glfwSetWindowShouldClose(window, GL_TRUE); 
				break;
			case GLFW_KEY_UP:
				//panggil buldozer push up
				if(!pushUp()){
					// jika buldozer gagal push up (di atas buldozer tidak ada batu), maka buldozer bisa bergerak ke atas.
					// bisa ke atas jika di atas buldozer tidak ada dinding
					if(buldozer.noObjectAbove(wall))
						//buldozer bergerak ke atas
						buldozer.moveUp();
				}
				break;
			case GLFW_KEY_DOWN:
				if(!pushDown()){
					if(buldozer.noObjectBelow(wall))
						buldozer.moveDown();
				}
				break;
			case GLFW_KEY_LEFT:
				if(!pushLeft()){
					if(buldozer.noObjectLeft(wall))
						buldozer.moveLeft();
				}
				break;
			case GLFW_KEY_RIGHT:
				if(!pushRight()){
					if(buldozer.noObjectRight(wall))
						buldozer.moveRight();
				}
				break;
		}
	}
}

void createObject(){
	buldozer.set(10,10, 0, 0);
	
	wall[0].set(5,200,-100,-100);	//wall kiri
	wall[1].set(200,5,-100,45);		//wall atas
	wall[2].set(5,200,95,-100);		//wall kanan
	wall[3].set(200,5,-100,-50);	//wall bawah
	
	wall[4].set(10,30,-10,-15);
	wall[5].set(10,30,10,-15);
	wall[6].set(50,10,-15,-35);
	wall[7].set(50,10,-15,25);
	
	
	rock[0].set(10,10,-20,-25);	//-20,-25
	rock[1].set(10,10,20,-25);
}

int main(void)
{
    GLFWwindow* window;
    if (!glfwInit()) exit(EXIT_FAILURE);

    window = glfwCreateWindow(1200, 600, "Buldozer", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);

	createObject();

    while (!glfwWindowShouldClose(window))
    {
        setup_viewport(window);
        grid_display();
        
		for(int i=0; i<totalWall; i++){
			wall[i].display();
		}
		
		for(int i=0; i<totalRock; i++){
			rock[i].display();
		}
		
        buldozer.display();


        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}



/*
#include <vector>
using namespace std;

vector<Wall> walls;
vector<Wall>::iterator it_walls;

Wall wall;
wall.set(5,200,-100,-100);
walls.push_back(wall);
wall.set(200,5,-100,45);
walls.push_back(wall);
wall.set(5,200,95,-100);
walls.push_back(wall);
wall.set(200,5,-100,-50);
walls.push_back(wall);
wall.set(10,10,15,15);
walls.push_back(wall);


for(it_walls=walls.begin(); it_walls!=walls.end(); ++it_walls) {
	it_walls->display();
} 
for(it_walls=walls.begin(); it_walls!=walls.end(); ++it_walls) {
	if(!(buldozer.canTurnUp(*it_walls)))
		return;
}	
*/
