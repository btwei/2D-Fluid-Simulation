#ifndef RENDERER_H
#define RENDERER_H

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Solver.h"

class Renderer{
public:
    void init(GLFWwindow* window, SPH* solver);
    void mainLoop();
    void cleanup();
private:
    SPH* _solver;
    GLFWwindow* _window;

    GLuint VAO = 0;
    GLuint pointsProgram = 0;

    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    std::vector<float> properties;

    void configureBuffers();
    void compileAndLoadShaders();

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    static std::vector<char> readFile(const std::string& filename);

    GLuint buildShaderFromSource(const std::string& filenameFrag, const std::string& filenameVert);
};

#endif