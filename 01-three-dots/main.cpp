#include <GL/glut.h>

void display() {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set the clear color to black
            glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer

                glEnable(GL_POINT_SMOOTH); // Enable point smoothing for smoother points
                    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST); // Set the hint for point smoothing to achieve the highest quality

                        glEnable(GL_BLEND); // Enable blending for transparency
                            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Set the blending function to control transparency

                                glColor3f(1.0f, 1.0f, 1.0f); // Set the color to white

                                    glPointSize(5.0f); // Set the point size to 5 units

                                        glBegin(GL_POINTS); // Begin drawing points
                                            glVertex2f(-0.5f, 0.0f); // Specify the first point at (-0.5, 0)
                                                glVertex2f(0.0f, 0.5f); // Specify the second point at (0, 0.5)
                                                    glVertex2f(0.5f, 0.0f); // Specify the third point at (0.5, 0)
                                                        glEnd(); // End drawing points

                                                            glFlush(); // Ensure all OpenGL commands are processed and executed
}

int main(int argc, char** argv) {
        glutInit(&argc, argv); // Initialize GLUT
            glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode to single buffer and RGB color mode
                glutInitWindowSize(400, 400); // Set the window size to 400x400 pixels
                    glutInitWindowPosition(200, 200); // Set the window position
                        glutCreateWindow("OpenGL Points"); // Create a window with the specified title

                            glutDisplayFunc(display); // Register the display callback function

                                glutMainLoop(); // Enter the main loop and start handling events

                                    return 0; // Return 0 to indicate successful program execution
}

