/*
 * Buldozer Game
 * May 2017
 * Institut Pertanian Bogor, Indonesia
 * Developed in OpenGL
 * 
 * Developed by:
 * 	Albert Alfrianta - albert.brucelee@gmail.com
 * 	Aprilian Nur
 *  Michael Julyus Christopher Manullang
 * 
 * You can freely modify the program, under the GNU License :)
 * 
*/

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <iostream>
using namespace std;


#define frameWidth 200
#define frameHeight 100

#define totalWall 8
#define totalRock 2

#include "object/grid.cpp"

#include "object/object.cpp"
#include "object/moveobject.cpp"
#include "object/rock.cpp"
#include "object/wall.cpp"
#include "object/buldozer.cpp"
#include "object/point.cpp"
#include "finish.cpp"
#include "gameplay.cpp"

Gameplay gameplay;


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
    glOrtho(-frameWidth/2, frameWidth/2, -frameHeight/2, frameHeight/2, 1.f, -1.f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}




static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	if(action==GLFW_PRESS || action==GLFW_REPEAT){	
		//gameplay key input (while not loose and not win)
		if(!gameplay.calcFailed() && !gameplay.calcFinish()){
			switch(key) {
				// close program on ESC key
				case GLFW_KEY_ESCAPE:
					glfwSetWindowShouldClose(window, GL_TRUE); 
					break;
				case GLFW_KEY_UP:
					gameplay.keyUp();
					break;
				case GLFW_KEY_DOWN:
					gameplay.keyDown();
					break;
				case GLFW_KEY_LEFT:
					gameplay.keyLeft();
					break;
				case GLFW_KEY_RIGHT:
					gameplay.keyRight();
					break;
			}
		}
	}
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
	
	//buat object
	gameplay.createObject();

    while (!glfwWindowShouldClose(window))
    {
        setup_viewport(window);
        
        grid_display();
        
        //tampilkan object
		gameplay.displayObject();
		
		//apakah kalah?
        if(gameplay.calcFailed()){
			gameplay.loose();
		}
		//apakah menang?
		else if(gameplay.calcFinish()){
			gameplay.win();
		}
		

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
