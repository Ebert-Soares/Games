#include <glad/glad.h>
#include "GLFW/include/glfw3.h"
#include <stdio.h>




int main(){
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_FALSE);


  GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);

  glfwMakeContextCurrent(window);


  if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    printf("error");
    return 1;
}
  glViewport(0, 0, 800, 600);


  return 0;

}
