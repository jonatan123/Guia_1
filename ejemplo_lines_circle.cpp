#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
void display(void)
{
    GLfloat angulo;
    int i;
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        glPointSize(3);
        glBegin(GL_POINTS);
        for(i=0; i<360; i+=7)
        {
            angulo=(GLfloat)i*3.1416/180.0f;
            //glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f((cos(angulo))/2, (sin(angulo))/2,0.0f);
        }
        glFlush();
        glEnd();
    }
    glEnd();
    glFlush();
}
    void init (void)
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    }
    int main(int argc, char** argv)
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(600, 600);
        glutInitWindowPosition(100,100);
        glutCreateWindow("jonatan");
        init();
        glutDisplayFunc(display);
        glutMainLoop();
        return 0;
    }

