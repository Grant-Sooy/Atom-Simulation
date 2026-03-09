#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>



void framebuffer_size_callback(GLFWwindow* window, int width, int height); //Forward definition so it doesn't brake when called in main
void processInput(GLFWwindow* window);

int main(void) // This creates the initialization of using OpenGL
{
    glfwInit ();
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);



// Time to create the window object

GLFWwindow* window = glfwCreateWindow(800, 600, "PuppyDog", NULL, NULL); // makes a window names window of given dimensions and name
if (window == NULL) // make a way of seeing if nothing was made
{
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate ();
    return -1;
}

glfwMakeContextCurrent (window); //makes the window on screen


if (!gladLoadGLLoader ( (GLADloadproc)glfwGetProcAddress)) // Check to make sure glad is working
{
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
}

glViewport(0, 0, 800, 600); //THis tells opengl how to display the data and coordinates with respect to the window


glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // gather information about the resizing window so the framebuffer_size_callback function can resize the display

//making a rendering loop to keep the window open
while(!glfwWindowShouldClose(window)) 
{

    // Input
    processInput(window); // check the function below to see if a key has been pressed

    // Rendering Commands Here
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    float vertices[] = {  // making the vertices of a triangle
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    unsigned int VBO; // using an object for the first part of the graphics pipeline
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO); // binding the vertices to a buffer

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); // This copies the currently bound zertex data to the buffer's memory

    

    // check and call events and swap the buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
}

glfwTerminate(); //clean up all the resources GLFW was using
    return 0;
}

// make it so resizing the window changes the display size as well
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// gives ability to press a key and change the state of the window
void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) // pressing the esc key will close the window
        glfwSetWindowShouldClose(window, true);
}
