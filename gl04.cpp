/*
 * GL01Hello.cpp: Test OpenGL/GLUT C/C++ Setup
 * Tested under Eclipse CDT with MinGW/Cygwin and CodeBlocks with MinGW
 * To compile with -lfreeglut -lglu32 -lopengl32
 */
//#include <windows.h>  // for MS Windows

#include <stdio.h>
#include <stdint.h>
#define GL_GLEXT_LEGACY
//#include <GL/gl.h>
#include <GL/glew.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
//#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include "include/gui.h"

#ifdef main
#undef main
#endif


void errorCallback(int32_t error, const char* desc) {
    fprintf(stderr, "Error: %s\n", desc);
}


static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}


uint32_t loadBitmap(const char *filename) {
	BMP *b;
	uint32_t texture;
	
	b = new BMP(filename);
	//b->read(filename);
	
	glGenTextures(1, &texture);
	
	//glActiveTexture(GL_TEXTURE);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, b->bmp_info_header.width, b->bmp_info_header.height, 0, GL_BGR, GL_UNSIGNED_BYTE, &b->data[0]);
	
	return texture;
}

void draw() {
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glViewport(0,0,1024, 681);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1024,0.0,681);
             
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS);

    glTexCoord2i(0,0);
    glVertex2i(0,0);
    
    glTexCoord2i(0,1);
    glVertex2i(0,681);
    
    glTexCoord2i(1,1);
    glVertex2i(1024,681);
    
    glTexCoord2i(1,0);
    glVertex2i(1024,0);

    glEnd();
           
    glFlush();
}


int main(int argc, char *argv[]) {
	uint32_t t;
	
	if(!glfwInit()) {
		printf("error initializing glfw\n");
		return 0;
		// Initialization failed
	}
	
	printf("glfw initialized successfully\n");
	
	glfwSetErrorCallback(errorCallback);

	GLFWwindow* window = glfwCreateWindow(1024, 681, "My Title", NULL, NULL);

	if(!window) {
		// Window or OpenGL context creation failed
		printf("error creating window.\n");
		return 0;
	}
	
	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, keyCallback);
	
	t = loadBitmap("wallpaper.bmp");
	while(!glfwWindowShouldClose(window)) {
		draw();
		glfwSwapBuffers(window);
		// Keep running
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 1;
}