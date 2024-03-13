/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <stb/stb_image.h>

#include "constants.h"
#include "lodepng.h"
#include "board.h"
#include "game.h"
#include "structures.h"
#include "signals.h"


#include "shaderprogram.h"

#define X 8
#define Y 20
#define Z 8

float speed_x=0; //angular speed in radians
float speed_y=0; //angular speed in radians
float aspectRatio=1;
float movingSpeed = 0;

float posX = 0;
float posY = 0;

float returnTick(int ct) {
	if (ct < 40)return 1.0f - 0.00048828125 * ct * ct;
	return 0.22f;
}

bool SIG_ACTION_MOVEMENT_DOWN = false;
bool SIG_ACTION_MOVEMENT_W = false;
bool SIG_ACTION_MOVEMENT_S = false;
bool SIG_ACTION_MOVEMENT_A = false;
bool SIG_ACTION_MOVEMENT_D = false;

bool SIG_ACTION_ROTATION_X = false;
bool SIG_ACTION_ROTATION_Y = false;
bool SIG_ACTION_ROTATION_Z = false;
bool SIG_END_GAME = false;
bool SIG_DEBUG_OCCUPANCY = false;

bool SIG_BLOCK_SPAWNED = false;
int turnCounter = 0;
int blockInControl = -1;
int rotationParameter = 0;
std::vector<std::vector<std::vector<int>>>occupancyMatrix = createOccupancyMatrix(X, Y, Z);
std::vector<std::vector<std::vector<int>>>rotationMatrix = getRotationMatrix();
std::vector<std::vector<std::vector<int>>>rotationCoords = getRotationCoords();
std::vector<std::vector<std::vector<int>>>textureMatrix = createOccupancyMatrix(X, Y, Z);
std::vector<int> centralCoord;
std::vector<float>gameTickFunction;
GLuint tex_block;//
GLuint tex_board;//1
GLuint tex_stone;//
GLuint tex_bedrock;//
GLuint tex_dirt;//
GLuint tex_diamond;//3
GLuint tex_walk;//
ShaderProgram* sp;
//Error processing callback procedure
std::vector<float> initGameTickFunction() {
	std::vector<float>gtf;
	gtf.push_back(1.0f);
	for (int i = 0; i < 8192; i++)
	{
		gtf.push_back(returnTick(i));
	}
	return gtf;
}
void error_callback(int error, const char* description) {
	fputs(description, stderr);
}
void keyCallback(GLFWwindow* window,int key,int scancode,int action,int mods) {
	
    if (action==GLFW_PRESS) {
		switch (key) {
		case GLFW_KEY_O:
			SIG_DEBUG_OCCUPANCY = true;
			break;
		case GLFW_KEY_F:
			SIG_ACTION_MOVEMENT_DOWN = true;
			break;
		case GLFW_KEY_LEFT:
			speed_x = -PI / 2;
			break;
		case GLFW_KEY_RIGHT:
			speed_x = PI / 2;
			break;
		case GLFW_KEY_UP:
			speed_y = PI / 2;
			break;
		case GLFW_KEY_DOWN:
			speed_y = -PI / 2;
			break;
		case GLFW_KEY_W:
			SIG_ACTION_MOVEMENT_W = true;
			break;
		case GLFW_KEY_A:
			SIG_ACTION_MOVEMENT_A = true;
			break;
		case GLFW_KEY_S:
			SIG_ACTION_MOVEMENT_S = true;
			break;
		case GLFW_KEY_D:
			SIG_ACTION_MOVEMENT_D = true;
			break;
		case GLFW_KEY_Z:
			SIG_ACTION_ROTATION_X = true;
			break;

		case GLFW_KEY_X:
			SIG_ACTION_ROTATION_Y = true;
			break;

		case GLFW_KEY_C:
			SIG_ACTION_ROTATION_Z = true;
			break;
		}
	}

    
    if (action==GLFW_RELEASE) {
        if (key==GLFW_KEY_LEFT) speed_x=0;
        if (key==GLFW_KEY_RIGHT) speed_x=0;
        if (key==GLFW_KEY_UP) speed_y=0;
        if (key==GLFW_KEY_DOWN) speed_y=0;
		if (key == GLFW_KEY_W) movingSpeed = 0;
		
    }
}
void windowResizeCallback(GLFWwindow* window,int width,int height) {
    if (height==0) return;
    aspectRatio=(float)width/(float)height;
    glViewport(0,0,width,height);
}
GLuint readTexture(const char* filename) {
	GLuint tex;
	glActiveTexture(GL_TEXTURE0);
	//Read into computers memory
	std::vector<unsigned char> image; //Allocate memory
	unsigned width, height; //Variables for image size
	//Read the image
	unsigned error = lodepng::decode(image, width, height, filename);
	//Import to graphics card memory
	glGenTextures(1, &tex); //Initialize one handle
	glBindTexture(GL_TEXTURE_2D, tex); //Activate handle
	//Copy image to graphics cards memory reprezented by the active handle
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, (unsigned char*)image.data());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	return tex;
}
//Initialization code procedure
void initOpenGLProgram(GLFWwindow* window) {
	//************Place any code here that needs to be executed once, at the program start************
	glClearColor(0,0,0,1);
	glEnable(GL_DEPTH_TEST);
	glfwSetWindowSizeCallback(window,windowResizeCallback);
	glfwSetKeyCallback(window,keyCallback);
	sp = new ShaderProgram("v_block.glsl", NULL, "f_block.glsl");
	tex_board = readTexture("textures/lines.png");//GL_TEXTURE1
	tex_block = readTexture("textures/bricks.png");//GL_TEXTURE0
	tex_stone = readTexture("textures/stone.png");//GL_TEXTURE2
	tex_bedrock = readTexture("textures/bedrock.png");//GL_TEXTURE3
	tex_dirt = readTexture("textures/coal.png");//GL_TEXTURE4
	tex_diamond = readTexture("textures/diamond.png");//GL_TEXTURE5
	tex_walk = readTexture("textures/blackstone.png");
	//sp = new ShaderProgram("v_simplest.glsl", NULL, "f_simplest.glsl");

}
//Release resources allocated by the program
void freeOpenGLProgram(GLFWwindow* window) {
	//************Place any code here that needs to be executed once, after the main loop ends************
	delete sp;
	glDeleteTextures(1, &tex_block);
	glDeleteTextures(1, &tex_board);
	glDeleteTextures(1, &tex_stone);
	glDeleteTextures(1, &tex_bedrock);
	glDeleteTextures(1, &tex_dirt);
	glDeleteTextures(1, &tex_diamond);
	glDeleteTextures(1, &tex_walk);
}

//Drawing procedure
glm::vec3 pos = glm::vec3(0.0f, 10.0f, -5.0f);
glm::vec3 dir = glm::vec3(4.0f, 0.0f, 4.0f);
glm::mat4 matrixBefore;

void drawScene(GLFWwindow* window,float angle_x,float angle_y, glm::vec3 currentTranslation, std::vector<float> currentRotation) {
	//************Place any code here that draws something inside the window******************l

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glm::mat4 V = glm::lookAt(glm::vec3(float(centralCoord[0]), float(centralCoord[1])+10.0f, float(centralCoord[2])), glm::vec3(4.0f, 4.0f, 4.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 V = glm::lookAt(glm::vec3(0.0f, 25.0f, 4.0f), glm::vec3(4.0f, 8.0f, 4.0f), glm::vec3(0.0f, 1.0f, 0.0f)); //Compute view matrix - position of camera/point at which the camera looks at/vector upwards
    glm::mat4 P=glm::perspective(50.0f*PI/180.0f, 1920.0f/1080.0f, 1.0f, 50.0f); //compute projection matrix
	glm::mat4 M=glm::mat4(1.0f);
	M = glm::translate(M, glm::vec3(4.0f, 0.0f, 4.0f));
	M = glm::rotate(M, angle_y, glm::vec3(0.0f, 0.0f, 1.0f));
	M = glm::rotate(M, angle_x, glm::vec3(0.0f, 1.0f, 0.0f));
	M = glm::translate(M, glm::vec3(-4.0f, 0.0f, -4.0f));
	glm::mat4 I = M;
	//glm::mat4 M1 = glm::mat4(1.0f);//matrix used for calculating game logic
	sp->use();//activate shading program
    //Send parameters to graphics card
	glUniformMatrix4fv(sp->u("P"), 1, false, glm::value_ptr(P));
	glUniformMatrix4fv(sp->u("V"), 1, false, glm::value_ptr(V));
	glUniformMatrix4fv(sp->u("M"), 1, false, glm::value_ptr(M));
	glUniformMatrix4fv(sp->u("I"), 1, false, glm::value_ptr(I));

	//glEnableVertexAttribArray(sp->u("color"));
	//glUniform4f(sp->u("color"), 0, 1, 1, 0);
	//glDisableVertexAttribArray(sp->u("color"));
	
   
	//-----------------Board Drawing---------------------//
	
	
    glEnableVertexAttribArray(sp->a("vertex"));
    glVertexAttribPointer(sp->a("vertex"),4,GL_FLOAT,false,0,boardVertices);
	glEnableVertexAttribArray(sp->a("texCoord"));
	glVertexAttribPointer(sp->a("texCoord"), 2, GL_FLOAT, false, 0, boardTexCoords);
	//glEnableVertexAttribArray(sp->a("color"));
	//glVertexAttribPointer(sp->a("color"), 4, GL_FLOAT, false, 0, boardColors);
	
	glUniform1i(sp->u("t"), 1);
	glUniform1i(sp->u("material"), 1);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, tex_board);
	
	glDrawArrays(GL_LINES,0,boardVertexCount);
	glDisableVertexAttribArray(sp->a("vertex")); //Disable sending data to the attribute vertex
	glDisableVertexAttribArray(sp->a("color"));
	glDisableVertexAttribArray(sp->a("texCoord"));
	
	drawFromOccupancyMatrix(occupancyMatrix,X,Y+3,Z,M,sp,tex_block,tex_stone,tex_bedrock,tex_dirt,tex_diamond,tex_walk,textureMatrix,blockInControl);
	if (!SIG_BLOCK_SPAWNED&&!SIG_END_GAME) {
		blockInControl = rand() % 6;
		centralCoord = { 3,19,3 };
		rotationParameter = 0;
		bool cfsp = checkForSpawnPrerequisites(blockInControl,occupancyMatrix,rotationCoords);
		if (cfsp == true) {
			turnCounter++;
			spawnBlock(blockInControl, occupancyMatrix, rotationCoords,textureMatrix);
		}
		else {
			SIG_END_GAME = true;
		}
		SIG_BLOCK_SPAWNED = true;
	}
	
    glfwSwapBuffers(window);
}

int main(void)
{
	gameTickFunction=initGameTickFunction();
	srand(time(NULL));
	GLFWwindow* window; //Pointer to object that represents the application window
	glfwSetErrorCallback(error_callback);//Register error processing callback procedure

	if (!glfwInit()) { //Initialize GLFW library
		fprintf(stderr, "Can't initialize GLFW.\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(1920, 1080, ".", NULL, NULL);  //Create a window 500pxx500px titled "OpenGL" and an OpenGL context associated with it.
	glfwSetWindowTitle(window, u8"Tetris 3D by Z£JB");
	int w, h;
	int channels;
	unsigned char* pixels = stbi_load("tetris_icon.png", &w, &h, &channels,4);
	GLFWimage images[1];
	images[0].width = w;
	images[0].height = h;
	images[0].pixels = pixels;
	glfwSetWindowIcon(window, 1, images);
	if (!window) //If no window is opened then close the program
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window); //Since this moment OpenGL context corresponding to the window is active and all OpenGL calls will refer to this context.
	glfwSwapInterval(1); //During vsync wait for the first refresh

	GLenum err;
	if ((err=glewInit()) != GLEW_OK) { //Initialize GLEW library
		fprintf(stderr, "Can't initialize GLEW: %s\n", glewGetErrorString(err));
		exit(EXIT_FAILURE);
	}

	initOpenGLProgram(window); //Call initialization procedure


	float angle_x=0; //current rotation angle of the object, x axis
	float angle_y=0; //current rotation angle of the object, y axis
	float walk = 0;
	glfwSetTime(0); //Zero the timer
	double timer = 0;
	int licznikprzerwan = 0;

	glm::vec3 blockTranslation =glm::vec3(4.0f, 19.0f, 4.0f);
	std::vector<float> blockRotation = {0.0f,0.0f,0.0f};
	while (!glfwWindowShouldClose(window)) //As long as the window shouldnt be closed yet...
	{
		
        angle_x+=speed_x*glfwGetTime(); //Add angle by which the object was rotated in the previous iteration
		angle_y+=speed_y*glfwGetTime(); //Add angle by which the object was rotated in the previous iteration
		walk = movingSpeed * glfwGetTime();
		timer += glfwGetTime();
		if (timer >= gameTickFunction[turnCounter]) {//it can be changed--------------------------------------------------------------------------------------------------------------------------------------
			timer = 0;
			licznikprzerwan++;
			//std::cout << licznikprzerwan << std::endl;
			if (blockInControl != -1) {
				SIG_ACTION_MOVEMENT_DOWN = true;
			}
			
		}
		//std::cout << glfwGetTime();
        glfwSetTime(0); //Zero the timer
		if (SIG_DEBUG_OCCUPANCY) {
			printOccupancyMatrix(occupancyMatrix);
			sig_debug_occupancy(SIG_DEBUG_OCCUPANCY);
		}
		if (blockInControl != -1 && SIG_ACTION_MOVEMENT_DOWN) {
			if (checkForDownMovement(blockInControl, rotationParameter, centralCoord, occupancyMatrix, rotationCoords, SIG_BLOCK_SPAWNED,textureMatrix)) {
				downMovement(blockInControl, rotationParameter, centralCoord, occupancyMatrix, rotationCoords,textureMatrix);
			}
			else {
				//std::cout << "TRIED TO MOVE DOWNWARDS" << std::endl;
				
			}
			SIG_ACTION_MOVEMENT_DOWN = false;
		}
		if (SIG_ACTION_MOVEMENT_W) {
			if (checkForXAxisMovement(blockInControl, rotationParameter, centralCoord, occupancyMatrix, rotationCoords, 1)) {
				xAxisMovement(blockInControl, rotationParameter, centralCoord, occupancyMatrix, rotationCoords, 1,textureMatrix);
			}
			else {
				//std::cout << "TRIED TO MOVE W" << std::endl;
				
			}
			SIG_ACTION_MOVEMENT_W = false;
		}
		if (SIG_ACTION_MOVEMENT_S) {
			if (checkForXAxisMovement(blockInControl, rotationParameter, centralCoord, occupancyMatrix, rotationCoords, -1)) {
				xAxisMovement(blockInControl, rotationParameter, centralCoord, occupancyMatrix, rotationCoords, -1,textureMatrix);
			}
			else {
				//std::cout << "TRIED TO MOVE S" << std::endl;
				
			}
			SIG_ACTION_MOVEMENT_S = false;
		}
		if (SIG_ACTION_MOVEMENT_D) {
			if (checkForZAxisMovement(blockInControl, rotationParameter, centralCoord, occupancyMatrix, rotationCoords, 1)) {
				zAxisMovement(blockInControl, rotationParameter, centralCoord, occupancyMatrix, rotationCoords, 1,textureMatrix);
			}
			else {
				//std::cout << "TRIED TO MOVE D" << std::endl;

			}
			SIG_ACTION_MOVEMENT_D = false;
		}
		if (SIG_ACTION_MOVEMENT_A) {
			if (checkForZAxisMovement(blockInControl, rotationParameter, centralCoord, occupancyMatrix, rotationCoords, -1)) {
				zAxisMovement(blockInControl, rotationParameter, centralCoord, occupancyMatrix, rotationCoords, -1,textureMatrix);
			}
			else {
				//std::cout << "TRIED TO MOVE A" << std::endl;

			}
			SIG_ACTION_MOVEMENT_A = false;
		}
		if (SIG_ACTION_ROTATION_X) {
			if (checkForXAxisRotation(blockInControl, rotationParameter, centralCoord, occupancyMatrix, rotationCoords, rotationMatrix)) {
				xAxisRotation(blockInControl, rotationParameter, centralCoord, occupancyMatrix, rotationCoords, rotationMatrix,textureMatrix);
			}
			else {
				//std::cout << "TRIED TO ROTATE AROUND X AXIS" << std::endl;
			}
			SIG_ACTION_ROTATION_X = false;
		}
		if (SIG_ACTION_ROTATION_Y) {
			if (checkForYAxisRotation(blockInControl, rotationParameter, centralCoord, occupancyMatrix, rotationCoords, rotationMatrix)) {
				yAxisRotation(blockInControl, rotationParameter, centralCoord, occupancyMatrix, rotationCoords, rotationMatrix, textureMatrix);
			}
			else {
				//std::cout << "TRIED TO ROTATE AROUND Y AXIS" << std::endl;
			}
			SIG_ACTION_ROTATION_Y = false;
		}
		if (SIG_ACTION_ROTATION_Z) {
			if (checkForZAxisRotation(blockInControl, rotationParameter, centralCoord, occupancyMatrix, rotationCoords, rotationMatrix)) {
				zAxisRotation(blockInControl, rotationParameter, centralCoord, occupancyMatrix, rotationCoords, rotationMatrix, textureMatrix);
			}
			else {
				//std::cout << "TRIED TO ROTATE AROUND Z AXIS" << std::endl;
			}
			SIG_ACTION_ROTATION_Z= false;
		}

		
		drawScene(window,angle_x,angle_y,blockTranslation,blockRotation); //Execute drawing procedure
		glfwPollEvents(); //Process callback procedures corresponding to the events that took place up to now
	}
	freeOpenGLProgram(window);

	glfwDestroyWindow(window); //Delete OpenGL context and the window.
	glfwTerminate(); //Free GLFW resources
	exit(EXIT_SUCCESS);

}
