#include <GL/glut.h>

void init() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 100.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0, -1.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

      //bottom
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0); //red
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glEnd();
    //top
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 0.0); //green
    glVertex3f(-0.25, -0.25, 0.5);
    glVertex3f(-0.25, 0.25, 0.5);
    glVertex3f(0.25, 0.25, 0.5);
    glVertex3f(0.25, -0.25, 0.5);
    glEnd();
    //front
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0); //yellow
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.25, -0.25, 0.5);
    glVertex3f(0.25, -0.25, 0.5);
    glVertex3f(0.5, -0.5, -0.5);
    glEnd();
    //back
    glBegin(GL_POLYGON);
    glColor3f(0.0, 1.0, 1.0); //cyan
    glVertex3f(-0.5, 0.5, -0.5);
    glVertex3f(-0.25, 0.25, 0.5);
    glVertex3f(0.25, 0.25, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glEnd();
    //left
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0); //blue
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.25, -0.25, 0.5);
    glVertex3f(-0.25, 0.25, 0.5);
    glVertex3f(-0.5, 0.5, -0.5);
    glEnd();
    //right
    glBegin(GL_POLYGON); //magenta
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(0.5, -0.5, -0.5);
    glVertex3f(0.25, -0.25, 0.5);
    glVertex3f(0.25, 0.25, 0.5);
    glVertex3f(0.5, 0.5, -0.5);
    glEnd();
//triangle in the shape
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 20.0, 1.0);
    glVertex3f(0.0, 0.0, 0.2);
   glVertex3f(0.4, 0.0, 0.2);
   glVertex3f(0.0, 0.4, 0.2);
   glEnd();

    glFlush();
}


void keyboard(int k, int x, int y) {
    switch (k) {
        case GLUT_KEY_PAGE_UP:
            glScalef(1.1, 1.1, 1.1);
            glutPostRedisplay();
            break;
        case GLUT_KEY_PAGE_DOWN:
            glScalef(1/1.1, 1/1.1, 1/1.1);
            glutPostRedisplay();
            break;
    }
  }

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("ASSIGNMENT 2");
    init();
    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutMainLoop();
    return 0;
}
