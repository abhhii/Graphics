#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <string.h>
#include <GL/freeglut.h>
#include <math.h>
// #include <graphics.h>
void display();
void reshape(int, int);
void drawLight(double);
void keyboard(unsigned char key, int x, int y);
void init()
{
	glClearColor(0.6,1.0,0.2,0.0); 
}

int main(int argc, char**argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);

	glutInitWindowPosition(200,100);
	glutInitWindowSize(1500,1000);

	glutCreateWindow("Watch this");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	init();

	glutMainLoop();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	int width = glutGet(GLUT_WINDOW_WIDTH);
	int height = glutGet(GLUT_WINDOW_HEIGHT);

	// road layer
	glColor3f(0.5, 0.5, 0.5); // gray
	glBegin(GL_TRIANGLES);
		glVertex2f(-2,-10);
		glVertex2f(3 ,0);
		glVertex2f(8,-10);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
		glVertex2f(3,0);
		glVertex2f(-2,-10);
	glEnd();

	glBegin(GL_LINES);
		glVertex2f(3,0);
		glVertex2f(8,-10);
	glEnd();

	//--------ROAD STRIP-------------------
	glColor3f(1, 1, 1); // white
	glBegin(GL_TRIANGLES);
		glVertex2f(2.5,-10);
		glVertex2f(3 ,0);
		glVertex2f(3.5,-10);
	glEnd();

	glColor3f(0.5, 0.5, 0.5);
	// grey patches to give illusion of discontinous strips
	glBegin(GL_POLYGON);
		glVertex2f(2.5,-4);
		glVertex2f(3.5,-4);
		glVertex2f(3.5,-3);
		glVertex2f(2.5,-3);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(2.5,-7);
		glVertex2f(3.5,-7);
		glVertex2f(3.5,-6);
		glVertex2f(2.5,-6);
	glEnd();


	// sky layer
	glColor3f(0.4, 1.0, 1.0); // blue
	glBegin(GL_POLYGON);
		glVertex2f(-(width/2),-2);
		glVertex2f(width/2, -2);
		glVertex2f(width/2,height/2);
		glVertex2f(-(width/2), height/2);
	glEnd();

	//  right mountain
	glColor3f(0.4, 0.2, 0.0); // brown
	glBegin(GL_TRIANGLES);
		glVertex2f(0, -2);
		glVertex2f(10,-2);
		glVertex2f(3 ,1);
		
	glEnd();

	// left mountain
	glColor3f(0.4, 0.2, 0.0); // brown
	glBegin(GL_TRIANGLES);
		glVertex2f(-10, -2);
		glVertex2f(3,-2);
		glVertex2f(-5 ,1);
		
	glEnd();

	glPointSize(10.0f); // set point size
	// START drawing
	//-------------------------------------------------------------------------------------
		// DRAWING POINTS
			// glBegin(GL_POINTS);
			// 	// specify vertex with 2 arguments of float type
			// 	glVertex2f(5,5);
			// 	glVertex2f(-5, -5);

			// // finish drawing
			// glEnd();
	//-------------------------------------------------------------------------------------
		// DRAWING POLYGONS
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
		glVertex2f(-8,-5);
		glVertex2f(-1,-5);
		glVertex2f(-1,0);
		glVertex2f(-8,0);
	glEnd();


//--------------- outline for bill board--as separate lines-------
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
		glVertex2f(-8,-5);
		glVertex2f(-1,-5);
	glEnd();
	glLineWidth(3.0f);
	glBegin(GL_LINES);
		glVertex2f(-1,-5);
		glVertex2f(-1,0);
	glEnd();
	glLineWidth(3.0f);
	glBegin(GL_LINES);
		glVertex2f(-1,0);
		glVertex2f(-8,0);
	glEnd();
	glLineWidth(10.0f);
	glBegin(GL_LINES);
		glVertex2f(-8,0);
		glVertex2f(-8,-5);
	glEnd();


//----------------OUTLINE AS A POLYGON---------------------------
	// glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
	// glLineWidth(6.0f);
	// glColor3f(0.0, 0.0, 0.0);
	// glBegin(GL_POLYGON);
	// 	glVertex2f(-7,-2);
	// 	glVertex2f(9,-2);
	// 	glVertex2f(9,5);
	// 	glVertex2f(-7, 5);
	// glEnd();
	// glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
	
//-----------lights-------------------------------------
	drawLight(7.8);
	drawLight(5.8);
	drawLight(3.8);
	drawLight(1.8);

//------------------ stem of bill board-------------------
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
		glVertex2f(-5,-10);
		glVertex2f(-4,-10);
		glVertex2f(-4,-5);
		glVertex2f(-5,-5);
	glEnd();
// 	---------------- outline of stem of bill board---------
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
		glVertex2f(-5,-10);
		glVertex2f(-4,-10);
	glEnd();
	glLineWidth(3.0f);
	glBegin(GL_LINES);
		glVertex2f(-4,-10);
		glVertex2f(-4,-5);
	glEnd();
	glLineWidth(3.0f);
	glBegin(GL_LINES);
		glVertex2f(-5,-10);
		glVertex2f(-5,-5);
	glEnd();
	


// 	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
// 	glLineWidth(4.0f);
// 	glColor3f(0.0, 0.0, 0.0);
// 	glBegin(GL_POLYGON);
// 		glVertex2f(0,-8);
// 		glVertex2f(2,-8);
// 		glVertex2f(2,-2);
// 		glVertex2f(0,-2);
// 	glEnd();
// 	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);

//----------------------FOOT OF BILLBOARD---------
// 	glColor3f(0.5, 0.5, 0.5);
// 	glBegin(GL_POLYGON);
// 		glVertex2f(-1,-8.5);
// 		glVertex2f(3,-8.5);
// 		glVertex2f(3,-8);
// 		glVertex2f(-1,-8);
// 	glEnd();
// 	// outline for foot
// 	glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
// 	glLineWidth(4.0f);
// 	glColor3f(0.0, 0.0, 0.0);
// 	glBegin(GL_POLYGON);
// 		glVertex2f(-1,-8.5);
// 		glVertex2f(3,-8.5);
// 		glVertex2f(3,-8);
// 		glVertex2f(-1,-8);
// 	glEnd();
// 	glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);

// 	// glLineWidth(4.0f);
// 	// glColor3f(0.0, 0.0, 0.0);
// 	// glBegin(GL_LINES);
// 	// 	glVertex2f(-3,-2);
// 	// 	glVertex2f(-3, -8);
// 	// glEnd();
// 	// glBegin(GL_LINES);
// 	// 	glVertex2f(3,-2);
// 	// 	glVertex2f(3, -8);
// 	// glEnd();
// 	// glColor3f(0.0, 1.0, 1.0);
// 	// glBegin(GL_POLYGON);
// 	// 	glVertex2f(-4,-8.5);
// 	// 	glVertex2f(-2,-8.5);
// 	// 	glVertex2f(-2,-8);
// 	// 	glVertex2f(-4,-8);
// 	// glEnd();
// 	// glBegin(GL_POLYGON);
// 	// 	glVertex2f(2,-8.5);
// 	// 	glVertex2f(4, -8.5);
// 	// 	glVertex2f(4,-8);
// 	// 	glVertex2f(2,-8);
// 	// glEnd();

	// lines of o in got
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(4.0f);
	glBegin(GL_LINES);
		glVertex2f(-3.35,-0.9);
		glVertex2f(-3.35,-2);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-3.25,-0.9);
		glVertex2f(-3.25,-2);
	glEnd();
	glBegin(GL_LINES);
		glVertex2f(-3.45,-0.9);
		glVertex2f(-3.45,-2);
	glEnd();


// 	//-----------------Writing Text------------------------------------
// 	glColor3f(0.0, 0.0, 0.0);
	
// 	int w;
// 	// set font face and the actual string
// 	// w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);

// 	// set text position
// 	// glRasterPos3f(-8,3,1);
  
// 	// set font color
// 	// glClear(GL_COLOR_BUFFER_BIT);

	unsigned char string[] = " GOT\nRocks!";
	glPushMatrix();
		glTranslatef(-6, -2,1);
		glScalef(0.011,0.011,1);
		// glutStrokeWidth(GLUT_STROKE_ROMAN, 100);
		glLineWidth(4.0f);
		glutStrokeString(GLUT_STROKE_ROMAN, string);//(unsigned char*)
	glPopMatrix();

// // HEART
// glPointSize(3);
//     glColor3ub(255, 0, 0);  // Color Red
//     glBegin(GL_POINTS);
//         for (float x = -15.139; x <= -1.139; x += 0.0001) 
//         {
//             float delta = cbrt(x*x) * cbrt(x*x) - 4*x*x + 4;
//             float y1 = (cbrt(x*x) + sqrt(delta)) / 2;
//             float y2 = (cbrt(x*x) - sqrt(delta)) / 2;
//             glVertex2f(x, y1);
//             glVertex2f(x, y2);
//         }
//     glEnd();



	// for(i=0; i<len; i++)
	// {
		// glutStrokeCharacter(GLUT_STROKE_ROMAN, string[i]);
	// }
	//-------------------Writing Text Ends--------------------------------
	// displays frame buffer
	glFlush();
}

void drawLight(double x)
{
	glLineWidth(2.0f);
	glBegin(GL_LINES);
		glVertex2f(-x,0);
		glVertex2f(-x+0.8,0.4);
	glEnd();

	glBegin(GL_LINES);
		glVertex2f(-x+0.8,0);
		glVertex2f(-x+0.8,0.4);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2f(-x+0.6, -0.2);
		glVertex2f(-x+1, -0.2);
		glVertex2f(-x+1, 0.2);
		glVertex2f(-x+0.6, 0.2);
	glEnd();
}

void reshape(int w, int h)
{
	// set viewport
	glViewport(0,0,w,h);
	
	// set projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);
}
void keyboard(unsigned char key, int x, int y)
{
    switch(key) {
        case 27:            // ESC key
            exit(0);
            break;
        default:
        	exit(0);
            break;
    }
}
