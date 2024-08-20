/*
Practica 1 Dibujo de primitivas 2D
Alumno: Mejia Alba Israel Hipolito 
Fecha de entrega: 19-08-24
*/
#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
	glfwInit();
	//Verificaci�n de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Israel Mejia - P1: Dibujo de Primitivas en 2D", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);
	
	//Verificaci�n de errores de creacion  ventana
	if (window== NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificaci�n de errores de inicializaci�n de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	// Define las dimensiones del viewport
	//glViewport(0, 0, screenWidth, screenHeight);
	
	// Se carga los el shader de vertice y de fragmentos
    Shader ourShader("Shader/core.vs", "Shader/core.frag");

	// Set up vertex data (and buffer(s)) and attribute pointers
	float vertices[] = {
		//x    , y   , z		R  ,  G  , B
		 0.5f,  0.5f, 0.0f,    0.9f, 0.9f, 0.9f,  // 0 - top right 
		 0.5f, -0.5f, 0.0f,    0.1f,0.1f,0.1f,  // 1 - bottom right  
		-0.5f, -0.5f, 0.0f,    0.1f,0.1f,0.1f,  // 2 - bottom left
		-0.5f,  0.5f, 0.0f,    0.1f,0.1f,0.1f, //  3 - top left 

		 0.55f,  0.55f, 0.0f,    1.0f,0.0f,0.0f,  // 4 - P1
		 0.65f,  0.40f, 0.0f,   1.0f,0.0f,0.0f,  //  5 - P2wi 
		 0.55f,  0.3f, 0.0f,    1.0f,0.0f,0.0f,  //  6 - P2.1

		0.55f,  0.55f, 0.0f,    1.0f,0.0f,0.0f,  // 4 - P1
		0.55f,  0.0f, 0.0f,    0.0f,0.3f,0.9f,  //  7 - P3
		0.1f,  0.40f, 0.0f,    1.0f,0.0f,0.1f,  // 13 - P6

		0.55f,  0.0f, 0.0f,    0.7f,0.5f,0.5f,  //  7 - P3
		-0.4f, -0.8f, 0.0f,    0.0f,0.5f,0.5f,  //  8 - P4
		-0.3f,  0.0f, 0.0f,    0.1f,0.5f,0.5f,  // 12 - P5

		0.55f,  0.0f, 0.0f,    0.0f,0.9f,0.7f,  //  7 - P3
		-0.3f,  0.0f, 0.0f,    0.0f,0.9f,0.0f,  // 12 - P5
		0.1f,  0.40f, 0.0f,    0.0f,0.9f,0.0f,  // 13 - P6

		
		-0.1f, -0.54f, 0.0f,     0.9f,0.3f,0.6f, //   9 - P4.1
		-0.1f, -0.7f, 0.0f,     0.9f,0.3f,0.0f,  //  10 - P4.2
		-0.4f, -0.8f, 0.0f,    0.3f,0.1f,0.9f,  //  8 - P4

		-0.4f, -0.8f, 0.0f,    0.0f,0.9f,0.7f,  //  8 - P4
		-0.1f, -0.7f, 0.0f,     0.9f,0.9f,0.0f,  //  10 - P4.2
		-0.4f, -0.95f, 0.0f,    0.1f,0.9f,0.0f,  // 11 - P4.3
 

		-0.25f, 0.75f, 0.0f,    1.0f,0.0f,0.1f,  // 14 - P7 
		0.1f,  0.40f, 0.0f,    0.0f,0.5f,0.0f,  // 13 - P6
		-0.3f,  0.0f, 0.0f,    0.0f,0.5f,0.0f,  // 12 - P5

		-0.7f,  0.85f, 0.0f,     0.0f,0.0f,0.9f,  // 16 - P8.1
		-0.25f, 0.75f, 0.0f,    1.0f,0.0f,0.1f,  // 14 - P7 
		-0.7f,  0.75f, 0.0f,     0.0f,0.0f,0.9f,  // 17 - P8.2

		-0.25f, 0.75f, 0.0f,    0.3f,0.9f,0.1f,  // 14 - P7  
		-0.3f,  0.0f, 0.0f,     0.4f,0.9f,0.7f,  // 12 - P5
		-0.9f,  0.75f, 0.0f,    0.7f,0.9f,0.1f,  // 15 - P8

		 0.55f,  0.0f, 0.0f,    0.0f,0.3f,0.9f,  //  7 - P3
		 -0.4f, -0.8f, 0.0f,    0.0f,0.3f,0.9f,  //  8 - P4
		-0.1f, -0.5f, 0.0f,     0.0f,0.3f,0.9f, //   9 - P4.1
		-0.1f, -0.7f, 0.0f,     0.1f,0.9f,0.0f,  //  10 - P4.2
		-0.4f, -0.95f, 0.0f,    0.1f,0.9f,0.0f,  // 11 - P4.3
		 -0.3f,  0.0f, 0.0f,    0.1f,0.9f,0.0f,  // 12 - P5
		 0.1f,  0.40f, 0.0f,    1.0f,0.0f,0.1f,  // 13 - P6
		-0.25f, 0.75f, 0.0f,    1.0f,0.0f,0.1f,  // 14 - P7
		-0.9f,  0.75f, 0.0f,    0.3f,0.9f,0.1f,  // 15 - P8
		-0.7f,  0.7f, 0.0f,     0.0f,0.0f,0.9f,  // 16 - P8.1
		-0.7f,  0.6f, 0.0f,     0.0f,0.0f,0.9f,  // 17 - P8.2
	};
	unsigned int indices[] = {  // note that we start from 0!
		6,7,8
	};



	GLuint VBO, VAO,EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3*sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)


	// Dibujar cuadros por segundo
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Draw our first triangle
        ourShader.Use();
        glBindVertexArray(VAO);
		// GL_POLYGON toma 4 vertices para hacer un poligono
		//Dibujar primitivas basicas PUNTOS
        glPointSize(10);
        glDrawArrays(GL_POINTS,0,35);// arreglo, apartir de que elemento, num de elemetos a dibujar  
        
		//Dibujar LINEAS
        //glDrawArrays(GL_LINES,0,2); //Apartir del elemento 0, usar dos vertices para dibujar una linea
		//glDrawArrays(GL_LINES, 0, 4); // une 2 vertices a la vez , hace 2 lineas
		//glDrawArrays(GL_LINE_LOOP,0,18); //GL_LINE_LOOP permite unir todos los vertices del arreglo
        
		//glDrawArrays(GL_LINE_LOOP,3,4); // puebra primer tiangulo por lineas 
		
		//Dibujar Triangulos GL_TRIANGLES
        //glDrawArrays(GL_TRIANGLES,0,3);
		/*glDrawArrays(GL_TRIANGLES,4,2);
		glDrawArrays(GL_TRIANGLES,4,6);
		glDrawArrays(GL_TRIANGLES,4,9);
		glDrawArrays(GL_TRIANGLES,4,12);*/
		glDrawArrays(GL_TRIANGLES,4,27);
        //glDrawElements(GL_TRIANGLES, 3,GL_UNSIGNED_INT,0);
		//glDrawArrays(GL_TRIANGLES,0,3);
		//glDrawArrays(GL_TRIANGLES,7,9);
		//glDrawElements(GL_TRIANGLES, 7,GL_UNSIGNED_INT,9);
 
		//glDrawArrays(GL_TRIANGLES,1,3);
		//glDrawArrays(GL_POLYGON, 3, 5);
        
         
        glBindVertexArray(0);
    
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}



	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}