#pragma once

#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>


//#include "shaderprogram.h"
#include "structures.h"
#include "constants.h"


std::vector<std::vector<std::vector<int>>> createOccupancyMatrix(int , int , int);
std::vector<std::vector<std::vector<int>>>createTextureMatrix(int dim1, int dim2, int dim3);
void drawFromOccupancyMatrix(std::vector<std::vector<std::vector<int>>>&, int, int, int, glm::mat4 , ShaderProgram*,GLuint t, GLuint t1, GLuint t2, GLuint t3, GLuint t4, GLuint t5, std::vector<std::vector<std::vector<int>>>& tm,int bic);
void printOccupancyMatrix(std::vector<std::vector<std::vector<int>>>& om);
void occupancyMatrixReset2(std::vector<std::vector<std::vector<int>>>& om);
bool checkForSpawnPrerequisites(int, std::vector<std::vector<std::vector<int>>>&, std::vector<std::vector<std::vector<int>>>&);
void spawnBlock(int bic, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, std::vector<std::vector<std::vector<int>>>& tm);
void deleteFullRows(std::vector<std::vector<std::vector<int>>>& om,std::vector<std::vector<std::vector<int>>>& tm);
bool checkIfRowFull(std::vector<std::vector<std::vector<int>>>& om, int y); 
bool checkForDownMovement(int bic, int rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, bool& sig1, std::vector<std::vector<std::vector<int>>>& tm);
void downMovement(int bic, int rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, std::vector<std::vector<std::vector<int>>>& tm);
bool checkForXAxisMovement(int bic, int rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, int pm);
void xAxisMovement(int bic, int rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, int pm, std::vector<std::vector<std::vector<int>>>& tm);
bool checkForZAxisMovement(int bic, int rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, int pm);
void zAxisMovement(int bic, int rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, int pm, std::vector<std::vector<std::vector<int>>>& tm);
bool checkForXAxisRotation(int bic, int& rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, std::vector<std::vector<std::vector<int>>>& rm);
void xAxisRotation(int bic, int& rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, std::vector<std::vector<std::vector<int>>>& rm, std::vector<std::vector<std::vector<int>>>& tm);
bool checkForYAxisRotation(int bic, int& rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, std::vector<std::vector<std::vector<int>>>& rm);
void yAxisRotation(int bic, int& rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, std::vector<std::vector<std::vector<int>>>& rm, std::vector<std::vector<std::vector<int>>>& tm);
bool checkForZAxisRotation(int bic, int& rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, std::vector<std::vector<std::vector<int>>>& rm);
void zAxisRotation(int bic, int& rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, std::vector<std::vector<std::vector<int>>>& rm, std::vector<std::vector<std::vector<int>>>& tm);


/*int spawnBlock(glm::mat4, ShaderProgram*);
void drawBlock(glm::mat4, ShaderProgram*, int);
std::vector<glm::vec4> getBlockCoords(glm::mat4 mat, int blockType);
bool checkForDownMovement(std::vector<std::vector<std::vector<int>>>& om, glm::mat4 mat, int blockType);
bool checkForWMovement(std::vector<std::vector<std::vector<int>>>& om, glm::mat4 mat, int blockType);
bool checkForSMovement(std::vector<std::vector<std::vector<int>>>& om, glm::mat4 mat, int blockType);
bool checkForAMovement(std::vector<std::vector<std::vector<int>>>& om, glm::mat4 mat, int blockType);
bool checkForDMovement(std::vector<std::vector<std::vector<int>>>& om, glm::mat4 mat, int blockType);
bool afterRotationPrerequisites(std::vector<std::vector<std::vector<int>>>& om, std::vector<glm::vec4> c);
bool checkForXposURotation(std::vector<std::vector<std::vector<int>>>& om, glm::mat4 mat, int blockType);
bool checkForXnegMRotation(std::vector<std::vector<std::vector<int>>>& om, glm::mat4 mat, int blockType);
bool checkForYposHRotation(std::vector<std::vector<std::vector<int>>>& om, glm::mat4 mat, int blockType);
bool checkForYnegKRotation(std::vector<std::vector<std::vector<int>>>& om, glm::mat4 mat, int blockType);
bool checkForZposNRotation(std::vector<std::vector<std::vector<int>>>& om, glm::mat4 mat, int blockType);
bool checkForZnegIRotation(std::vector<std::vector<std::vector<int>>>& om, glm::mat4 mat, int blockType);

void updateOccupancyMatrix(std::vector<glm::vec4> coords, std::vector<std::vector<std::vector<int>>>& om);
void printBlockCoords(glm::mat4 mat, int blockType, std::vector<glm::vec4>& c);*/