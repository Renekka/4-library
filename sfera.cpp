#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

float position = 0.0;

void Light()
{
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);

    GLfloat dif[] = { 1.0, 0.0, 0.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
    GLfloat pos[] = { 1.0, 1.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, pos);

}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glPushMatrix();

    glTranslatef(0.0, -1.5, 0.0);
    glRotatef(position, 0.5, 1.0, 0.5);

    glutWireSphere(2, 25, 15);
    //glutSolidSphere(2, 40, 30);
    glPopMatrix();
    glutSwapBuffers();
    glFlush();
}

void shift() {
    position += 0.15;
    glutPostRedisplay();
}

void Pose_() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 4.0);
    glMatrixMode(GL_MODELVIEW);
}

void main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowPosition(300, 50);
    glutInitWindowSize(500, 500);

    glutCreateWindow("СФЕРА");
    glClearColor(0.75, 0.75, 0.75, 0.75); //1.0, 1.0, 1.0, 1.0 - БЕЛЫЙ
    Light();
    glutDisplayFunc(display);
    glutIdleFunc(shift);
    glEnable(GL_DEPTH_TEST);
    Pose_();
    glutMainLoop();
}
