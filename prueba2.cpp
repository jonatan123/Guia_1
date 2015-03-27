
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
void init(void)
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); //Activamos las luces en 0
    glDepthFunc(GL_LESS); //comparación de profundidad
    glEnable(GL_DEPTH_TEST); //activa GL_DEPTH_TEST
}

float ponerMaterial(float tecla);

//se define y llena el arreglo que contendra los parametros para AMBIENT, DIFFUSE, ESPECULAR Y SHINE
double mate[10] = {0.329412, 0.223529, 0.027451, 0.780392, 0.568627, 0.113725, 0.992157, 0.941176, 0.807843, 27.8974};



void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
// Activamos la matriz de proyeccion.
    glMatrixMode(GL_PROJECTION);
// "limpiamos" esta con la matriz identidad.
    glLoadIdentity();
// Usamos proyeccion ortogonal
    glOrtho(-300, 300, -300, 300, -300, 300);
// Activamos la matriz de modelado/visionado.
    glMatrixMode(GL_MODELVIEW);
// "Limpiamos" la matriz
    glLoadIdentity();
}
void display(void)
{
    //Preparando las cosas de los colores
    GLfloat mat_ambient[] = { mate[0], mate[1], mate[2],1.0f };
    GLfloat mat_diffuse[] = { mate[3], mate[4], mate[5], 1.0f };
    GLfloat mat_specular[] = { mate[6], mate[7], mate[8], 1.0f };
    GLfloat shine[] = {mate[9]};
// "Limpiamos" el frame buffer con el color de "Clear", en este
// caso negro.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode( GL_MODELVIEW_MATRIX );
    glLoadIdentity();
// Rotacion de 25 grados en torno al eje x
    glRotated(25.0, 1.0, 0.0, 0.0);
// Rotacion de -30 grados en torno al eje y
    glRotated(-30.0, 0.0, 1.0, 0.0);
// Dibujamos una "Tetera" y le aplico el material
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shine);
//setMaterial
    glutSolidTeapot(125.0);
    glFlush();
}




void keyboard(unsigned char key, int x, int y)//Funcion que sirve para el uso de las teclas +,-,X,Y,Z y
{
    switch (key)
    {
    case 49:
        mate[0] = 0.135;
        mate[1] = 0.2225;
        mate[2] = 0.1575;
        mate[3] = 0.54;
        mate[4] = 0.89;
        mate[5] = 0.63;
        mate[6] = 0.316228;
        mate[7] = 0.316228;
        mate[8] = 0.316228;
        mate[9] = 0.1;

        //mate = {0.135, 0.2225, 0.1575, 0.54, 0.89, 0.63, 0.316228, 0.316228, 0.316228, 0.1};
        break;
    case 50:
        mate[0] = 0.05375;
        mate[1] = 0.05;
        mate[2] = 0.06625;
        mate[3] = 0.18275;
        mate[4] = 0.17;
        mate[5] = 0.22525;
        mate[6] = 0.332741;
        mate[7] = 0.328634;
        mate[8] = 0.346435;
        mate[9] = 0.3;
        break;
    case 51:
        mate[0] = 0.25;
        mate[1] = 0.20725;
        mate[2] = 0.20725;
        mate[3] = 0.1;
        mate[4] = 0.829;
        mate[5] = 0.829;
        mate[6] = 0.296648;
        mate[7] = 0.296648;
        mate[8] = 0.296648;
        mate[9] = 0.088;
        break;
    case 52:
        mate[0] = 0.1745;
        mate[1] = 0.01175;
        mate[2] = 0.01175;
        mate[3] = 0.61424;
        mate[4] = 0.04136;
        mate[5] = 0.04136;
        mate[6] = 0.727811;
        mate[7] = 0.626959;
        mate[8] = 0.626959;
        mate[9] = 0.6;
        break;
    case 53:
        mate[0] = 0.1;
        mate[1] = 0.18725;
        mate[2] = 0.1745;
        mate[3] = 0.396;
        mate[4] = 0.74151;
        mate[5] = 0.69102;
        mate[6] = 0.297254;
        mate[7] = 0.30829;
        mate[8] = 0.306678;
        mate[9] = 0.1;
        break;
    }

    glutPostRedisplay();//Actualización de visualización
}






int main(int argc, char **argv)
{
// Inicializo OpenGL
    glutInit(&argc, argv);
// Activamos buffer simple y colores del tipo RGB
    glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH);
// Definimos una ventana de medidas 800 x 600 como ventana
// de visualizacion en pixels
    glutInitWindowSize (800, 600);
// Posicionamos la ventana en la esquina superior izquierda de
// la pantalla.
    glutInitWindowPosition (0, 0);
// Creamos literalmente la ventana y le adjudicamos el nombre que se
// observara en su barra de titulo.
    glutCreateWindow ("Tetera");
// Inicializamos el sistema
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}


