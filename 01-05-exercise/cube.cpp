#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <cmath> // Add this line to include the <cmath> header

// Window size
const int WIDTH = 800;
const int HEIGHT = 600;

// Cube rotation
float cubeRotation = 0.0f;

// Cube vertices
GLfloat cubeVertices[] = {
    // Front face
    -0.5f, -0.5f, 0.5f, // Bottom-left vertex
    0.5f, -0.5f, 0.5f,  // Bottom-right vertex
    0.5f, 0.5f, 0.5f,   // Top-right vertex
    -0.5f, 0.5f, 0.5f,  // Top-left vertex

    // Back face
    -0.5f, -0.5f, -0.5f, // Bottom-left vertex
    0.5f, -0.5f, -0.5f,  // Bottom-right vertex
    0.5f, 0.5f, -0.5f,   // Top-right vertex
    -0.5f, 0.5f, -0.5f,  // Top-left vertex

    // Left face
    -0.5f, -0.5f, -0.5f, // Bottom-left vertex
    -0.5f, 0.5f, -0.5f,  // Top-left vertex
    -0.5f, 0.5f, 0.5f,   // Top-right vertex
    -0.5f, -0.5f, 0.5f,  // Bottom-right vertex

    // Right face
    0.5f, -0.5f, 0.5f,   // Bottom-left vertex
    0.5f, 0.5f, 0.5f,    // Top-left vertex
    0.5f, 0.5f, -0.5f,   // Top-right vertex
    0.5f, -0.5f, -0.5f,  // Bottom-right vertex

    // Top face
    -0.5f, 0.5f, 0.5f,   // Bottom-left vertex
    0.5f, 0.5f, 0.5f,    // Bottom-right vertex
    0.5f, 0.5f, -0.5f,   // Top-right vertex
    -0.5f, 0.5f, -0.5f,  // Top-left vertex

    // Bottom face
    -0.5f, -0.5f, -0.5f, // Bottom-left vertex
    0.5f, -0.5f, -0.5f,  // Bottom-right vertex
    0.5f, -0.5f, 0.5f,   // Top-right vertex
    -0.5f, -0.5f, 0.5f   // Top-left vertex
};

// Cube colors
GLfloat cubeColors[] = {
    // Front face (red)
    1.0f, 0.0f, 0.0f, // Bottom-left vertex
    1.0f, 0.0f, 0.0f, // Bottom-right vertex
    1.0f, 0.0f, 0.0f, // Top-right vertex
    1.0f, 0.0f, 0.0f, // Top-left vertex

    // Back face (green)
    0.0f, 1.0f, 0.0f, // Bottom-left vertex
    0.0f, 1.0f, 0.0f, // Bottom-right vertex
    0.0f, 1.0f, 0.0f, // Top-right vertex
    0.0f, 1.0f, 0.0f, // Top-left vertex

    // Left face (blue)
    0.0f, 0.0f, 1.0f, // Bottom-left vertex
    0.0f, 0.0f, 1.0f, // Top-left vertex
    0.0f, 0.0f, 1.0f, // Top-right vertex
    0.0f, 0.0f, 1.0f, // Bottom-right vertex

    // Right face (yellow)
    1.0f, 1.0f, 0.0f, // Bottom-left vertex
    1.0f, 1.0f, 0.0f, // Top-left vertex
    1.0f, 1.0f, 0.0f, // Top-right vertex
    1.0f, 1.0f, 0.0f, // Bottom-right vertex

    // Top face (cyan)
    0.0f, 1.0f, 1.0f, // Bottom-left vertex
    0.0f, 1.0f, 1.0f, // Bottom-right vertex
    0.0f, 1.0f, 1.0f, // Top-right vertex
    0.0f, 1.0f, 1.0f, // Top-left vertex

    // Bottom face (magenta)
    1.0f, 0.0f, 1.0f, // Bottom-left vertex
    1.0f, 0.0f, 1.0f, // Bottom-right vertex
    1.0f, 0.0f, 1.0f, // Top-right vertex
    1.0f, 0.0f, 1.0f  // Top-left vertex
};

// Mouse variables
double prevMouseX = 0.0;
double prevMouseY = 0.0;
bool mousePressed = false;

// Function to handle mouse button events
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        if (action == GLFW_PRESS) {
            mousePressed = true;
        } else if (action == GLFW_RELEASE) {
            mousePressed = false;
        }
    }
}

// Function to handle mouse movement
void cursorPosCallback(GLFWwindow* window, double xpos, double ypos) {
    if (mousePressed) {
        double dx = xpos - prevMouseX;
        double dy = ypos - prevMouseY;
        cubeRotation += dx * 0.05f;
    }

    prevMouseX = xpos;
    prevMouseY = ypos;
}

// Function to draw the cube
void drawCube() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Translate the cube away from the camera
    glTranslatef(0.0f, 0.0f, -2.0f);

    // Rotate the cube around the Y-axis
    glRotatef(cubeRotation, 0.0f, 1.0f, 0.0f);

    // Enable vertex and color arrays
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    // Set the vertex and color pointers
    glVertexPointer(3, GL_FLOAT, 0, cubeVertices);
    glColorPointer(4, GL_FLOAT, 0, cubeColors);

    // Draw the cube
    glDrawArrays(GL_QUADS, 0, 24);

    // Disable vertex and color arrays
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}


int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }
    // Create a window
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Cube", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Set mouse button callback
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    // Set cursor position callback
    glfwSetCursorPosCallback(window, cursorPosCallback);

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window)) {
        // Clear the color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Set the viewport
        glViewport(0, 0, WIDTH, HEIGHT);

        // Set the projection matrix
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        // Set the projection matrix
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        float aspectRatio = static_cast<float>(WIDTH) / HEIGHT;
        float fov = 45.0f;
        float nearPlane = 0.1f;
        float farPlane = 100.0f;
        float top = nearPlane * std::tan(fov * 0.5f * M_PI / 180.0f);
        float bottom = -top;
        float left = bottom * aspectRatio;
        float right = top * aspectRatio;
        glFrustum(left, right, bottom, top, nearPlane, farPlane);

        // Set the modelview matrix
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Draw the cube
        drawCube();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    return 0;
}

