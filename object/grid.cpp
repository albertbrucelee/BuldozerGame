
void grid(int column, int row)
{
	glColor3f(0.2,0.2,0.2);
	int i, xMin=-column/2, yMin=-row/2, xMax=column/2, yMax=row/2;
	glBegin(GL_LINES);
	for(i=xMin; i<=xMax; i++){
		if(i==0)
			glColor3f(0.5,0.5,0.5);
		glVertex2f(i,yMin);
		glVertex2f(i,yMax);
		if(i==0)
			glColor3f(0.2,0.2,0.2);
	}
	for(i=yMin; i<=yMax; i++){
		if(i==0)
			glColor3f(0.5,0.5,0.5);
		glVertex2f(xMin,i);
		glVertex2f(xMax,i);
		if(i==0)
			glColor3f(0.2,0.2,0.2);
	}
	glEnd();
}
void grid_display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	grid(200,100);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glFlush();
}
