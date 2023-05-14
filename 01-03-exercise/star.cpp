#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer
    glLoadIdentity();              // Load the identity matrix

    // Draw the Cartesian plane
    glColor3f(0.5, 0.5, 0.5);      // Set the color to gray

    glBegin(GL_LINES);             // Begin drawing lines
    glVertex2f(-1.0, 0.0);         // Draw the x-axis
    glVertex2f(1.0, 0.0);

    glVertex2f(0.0, -1.0);         // Draw the y-axis
    glVertex2f(0.0, 1.0);
    glEnd();                       // End drawing lines

    glBegin(GL_TRIANGLE_FAN);      // Begin drawing a triangle fan
    glColor3f(1.0, 0.0, 0.0);      // Set the color to red

    glVertex2f(0.0, 0.0);          // Define the center of the star
    glVertex2f(0.0, 0.5);          // Define the top vertex of the star

    const int numPoints = 10;      // Define the number of points on the star
    const float angle = 36.0f;     // Define the angle between each point (360 / numPoints)

    // Calculate and draw the outer points of the star
    for (int i = 1; i <= numPoints; i++) {
        float theta = angle * i * 3.1415926f / 180.0f;  // Convert the angle to radians
        float radius = (i % 2 == 0) ? 0.25f : 0.5f;     // Determine the inner and outer radii
        float x = radius * std::sin(theta);             // Calculate the x-coordinate
        float y = radius * std::cos(theta);             // Calculate the y-coordinate
        glVertex2f(x, y);                               // Draw the vertex
    }

    glEnd();                       // End drawing the triangle fan

    glFlush();                     // Flush the OpenGL pipeline
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                         // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   // Set the display mode
    glutInitWindowSize(400, 400);                  // Set the window size
    glutCreateWindow("Five-Pointed Star - OpenGL"); // Create the window with a title
    glClearColor(0.0, 0.0, 0.0, 0.0);              // Set the clear color to black
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);               // Set the orthogonal projection
    glutDisplayFunc(display);                      // Set the display callback function
    glutMainLoop();                                // Enter the GLUT event loop

    return 0;
}
