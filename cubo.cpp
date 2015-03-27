#include <stdio.h>
#include <GL/glut.h>
#include <GL/gl.h>


void display();
void specialKeys();
 

double rotate_y=0; 
double rotate_x=0;
double rotate_z=0; 

GLfloat X = 0.0f;
GLfloat Y = 0.0f;
GLfloat Z = 0.0f;
GLfloat scale = 1.0f;

void display(){
 

  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 
  
  glLoadIdentity();
  
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  glRotatef(rotate_z, 0.0, 0.0, 1.0 );
  glTranslatef(X, Y, Z); 
  
      glScalef(scale, scale, scale);
 
  //Unión de 4 colores Blanco, Amarillo, Azul y Rojo
  glBegin(GL_POLYGON);
 
  glColor3f(   1.0,  1.0, 1.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // Blanco
  glColor3f(   1.0,  1.0,  0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // Amarillo
  glColor3f(   0.0,  0.0,  1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // Azul
  glColor3f(   1.0,  0.0,  0.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // Rojo
 
  glEnd();
 
  
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  0.5, -0.5, 0.5 );
  glVertex3f(  0.5,  0.5, 0.5 );
  glVertex3f( -0.5,  0.5, 0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();
 
 
  glBegin(GL_POLYGON);
  glColor3f(  0.0,  1.0,  0.0 );
  glVertex3f( 0.5, -0.5, -0.5 );
  glVertex3f( 0.5,  0.5, -0.5 );
  glVertex3f( 0.5,  0.5,  0.5 );
  glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();
 
  
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  1.0,  0.0 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  1.0 );
  glVertex3f(  0.5,  0.5,  0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();
 
  
  glBegin(GL_POLYGON);
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  glFlush();
  glutSwapBuffers();
 
}
 

void specialKeys( int key, int x, int y ) {
 
  //  Flecha derecha para aumentar rotación 7 grados
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 7;
 
  //  Flecha izquierda para disminuir rotación 7 grados
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 7;
 
  else if (key == GLUT_KEY_UP)
    rotate_x += 7;
 
  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 7;
    
  else if (key == GLUT_KEY_F2)
    rotate_z += 7;

  else if (key == GLUT_KEY_F2)
    rotate_z -= 7;


  glutPostRedisplay();
 
}

 void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        scale=0.5;
        break;
    case 'S':
        scale=1.5;
        break;
    case 'X' :
        X += 0.1f;
        break;
    case 'x' :
        X -= 0.1f;
        break;
    case 'y' :
        Y -= 0.1f;
        break;
    case 'Y' :
        Y += 0.1f;
        break;
    case 'z':
        Z += 0.1f;
        break;
    case 'Z':
        Z -= 0.1f;
        break;
    case 27 :
        exit(0);			// Salir
    }

    glutPostRedisplay();		  
}

int main(int argc, char* argv[]){
 
  
  glutInit(&argc,argv);
 
  
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (800, 600);
	glutInitWindowPosition (100,100);
  glutCreateWindow("Jonatan");
  glEnable(GL_DEPTH_TEST);
 
  glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);
 glutKeyboardFunc(keyboard); 
  glutMainLoop();
 
  //  retorna un valor
  return 0;
 
}
