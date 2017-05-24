
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <iostream>

#include "object/grid.cpp"

#include "object/wall.cpp"
#include "object/rock.cpp"
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


void turnUp(){
	for(int i=0; i<totalWall; i++){
		if(!(buldozer.canTurnUp(wall[i])))
			return;
	}
	buldozer.turnUp();
}
void turnDown(){
	for(int i=0; i<totalWall; i++){
		if(!(buldozer.canTurnDown(wall[i])))
			return;
	}
	buldozer.turnDown();
}
void turnLeft(){
	for(int i=0; i<totalWall; i++){
		if(!(buldozer.canTurnLeft(wall[i])))
			return;
	}
	buldozer.turnLeft();
}
void turnRight(){
	for(int i=0; i<totalWall; i++){
		if(!(buldozer.canTurnRight(wall[i])))
			return;
	}
	buldozer.turnRight();
}


bool pushUp(){
	for(int i=0; i<totalRock; i++){
		if(buldozer.canPushUp(rock[i])){
			
			buldozer.turnUp();
			rock[i].turnUp();
			return true;
		}
	}
	return false;
}
bool pushDown(){
	for(int i=0; i<totalRock; i++){
		if(buldozer.canPushDown(rock[i])){
			buldozer.turnDown();
			rock[i].turnDown();
			return true;
		}
	}
	return false;
}
bool pushLeft(){
	for(int i=0; i<totalRock; i++){
		if(buldozer.canPushLeft(rock[i])){
			buldozer.turnLeft();
			rock[i].turnLeft();
			return true;
		}
	}
	return false;
}
bool pushRight(){
	for(int i=0; i<totalRock; i++){
		if(buldozer.canPushRight(rock[i])){
			buldozer.turnRight();
			rock[i].turnRight();
			return true;
		}
	}
	return false;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	//if(action==GLFW_PRESS){		
	switch(key) {
		// close program on ESC key
		case GLFW_KEY_ESCAPE:
			glfwSetWindowShouldClose(window, GL_TRUE); 
			break;
		case GLFW_KEY_UP:
			if(!pushUp())
			turnUp();
			break;
		case GLFW_KEY_DOWN:
			if(!pushDown())
			turnDown();
			break;
		case GLFW_KEY_LEFT:
			if(!pushLeft())
			turnLeft();
			break;
		case GLFW_KEY_RIGHT:
			if(!pushRight())
			turnRight();
			break;
	}
}

void createObject(){
	buldozer.set(0,0,10,10);
	
	wall[0].set(5,200,-100,-100);	//wall kiri
	wall[1].set(200,5,-100,45);		//wall atas
	wall[2].set(5,200,95,-100);		//wall kanan
	wall[3].set(200,5,-100,-50);	//wall bawah
	
	wall[4].set(10,30,-10,-15);
	wall[5].set(10,30,10,-15);
	wall[6].set(50,10,-15,-35);
	wall[7].set(50,10,-15,25);
	
	
	rock[0].set(10,10,-20,-25);
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
