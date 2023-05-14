#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 1.0); // Color blanco para las líneas

    // Dibujo de las líneas en el centro
    glVertex2f(0.0, -0.5);
    glVertex2f(0.0, 0.5);

    glVertex2f(-0.5, 0.0);
    glVertex2f(0.5, 0.0);

    // Dibujo de la estrella de 5 picos
    glColor3f(1.0, 0.0, 0.0); // Color rojo para la estrella

    glVertex2f(-0.4, 0.2);
    glVertex2f(-0.15, 0.15);

    glVertex2f(-0.15, 0.15);
    glVertex2f(0.0, 0.4);

    glVertex2f(0.0, 0.4);
    glVertex2f(0.15, 0.15);

    glVertex2f(0.15, 0.15);
    glVertex2f(0.4, 0.2);

    glVertex2f(0.4, 0.2);
    glVertex2f(0.15, -0.15);

    glVertex2f(0.15, -0.15);
    glVertex2f(0.3, -0.4);

    glVertex2f(0.3, -0.4);
    glVertex2f(0.0, -0.25);

    glVertex2f(0.0, -0.25);
    glVertex2f(-0.3, -0.4);

    glVertex2f(-0.3, -0.4);
    glVertex2f(-0.15, -0.15);

    glVertex2f(-0.15, -0.15);
    glVertex2f(-0.4, 0.2);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Estrella de 5 picos con líneas en el centro - OpenGL");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
