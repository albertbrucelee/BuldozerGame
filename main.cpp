
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "object/grid.cpp"
#include "object/wall.cpp"
#include "object/buldozer.cpp"

Wall wall1(-100,-100,5,200);
Wall wall2(-100,45,200,5);
Wall wall3(95,-100,5,200);
Wall wall4(-100,-50,200,5);
Buldozer buldozer(0,0,10,10);

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE); // close program on ESC key
}

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

void turnLeft(){
	if(buldozer.coordLeft()>wall1.coordRight())	
		buldozer.turnLeft();
}
void turnUp(){
	if(buldozer.coordUp()<wall2.coordDown())	
		buldozer.turnUp();
}
void turnRight(){
	if(buldozer.coordRight()<wall3.coordLeft())	
		buldozer.turnRight();
}
void turnDown(){
	if(buldozer.coordDown()>wall4.coordUp())	
		buldozer.turnDown();
}
void processNormalKeys(GLFWwindow* window, int key, int scancode, int action, int mods) {
	//if(action==GLFW_PRESS){		
		switch(key) {
			case GLFW_KEY_UP:
				turnUp();
				break;
			case GLFW_KEY_DOWN:
				turnDown();
				break;
			case GLFW_KEY_LEFT:
				turnLeft();
				break;
			case GLFW_KEY_RIGHT:
				turnRight();
				break;
		}
	//}
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
    glfwSetKeyCallback(window, processNormalKeys);

    while (!glfwWindowShouldClose(window))
    {
        setup_viewport(window);
        grid_display();

        wall1.display();
        wall2.display();
        wall3.display();
        wall4.display();

        buldozer.display();




        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}


