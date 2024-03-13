#pragma once

#include "shaderprogram.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdlib.h>
#include <stdio.h>
#include<vector>
 
std::vector<std::vector<std::vector<int>>>getRotationMatrix();
std::vector<std::vector < std::vector<int>>>getRotationCoords();
void drawSingleBlock(ShaderProgram*,GLuint t, GLuint t1, GLuint t2, GLuint t3, GLuint t4, GLuint t5, std::vector<std::vector<std::vector<int>>>& tm,int x,int y,int z,bool is1,int bic);


/*void drawBlockJ(glm::mat4, ShaderProgram*);
void drawBlockL(glm::mat4 , ShaderProgram* );
void drawBlockT(glm::mat4 , ShaderProgram* );
void drawBlockI(glm::mat4, ShaderProgram* );
void drawBlockO(glm::mat4 , ShaderProgram* );
void drawBlockZ(glm::mat4 , ShaderProgram* );
void drawBlockS(glm::mat4 , ShaderProgram* );

std::vector<glm::vec4> coordJ(glm::mat4 originMatrix);
std::vector<glm::vec4> coordL(glm::mat4 originMatrix);
std::vector<glm::vec4> coordT(glm::mat4 originMatrix);
std::vector<glm::vec4> coordI(glm::mat4 originMatrix);
std::vector<glm::vec4> coordO(glm::mat4 originMatrix);
std::vector<glm::vec4> coordZ(glm::mat4 originMatrix);
std::vector<glm::vec4> coordS(glm::mat4 originMatrix);*/