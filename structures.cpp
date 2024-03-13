
#include "structures.h"
#include "block.h"

std::vector<std::vector<std::vector<int>>>getRotationMatrix(){//rm[blockInControl][rotationParameter][nextRotationParameter (on X)(on Y)(on Z)]
	std::vector<std::vector<std::vector<int>>> rm = { 
		{ 
			{9,3,4},{5,0,8},{11,1,6},{7,2,10},//0 1 2 3
			{8,7,0},{1,4,9},{10,5,2},{3,6,11},//4 5 6 7
			{6,9,3},{2,8,7},{4,11,1},{0,10,4} //8 9 10 11
		},{ 
			{11,1,6},{5,0,10},{9,3,4},{7,2,8},//0 1 2 3
			{8,7,0},{3,4,11},{10,5,2},{1,6,9},//4 5 6 7
			{4,9,1},{0,10,7},{6,11,3},{2,8,5} //8 9 10 11
		},{
			{2,1,0},{1,0,2},{0,2,1}
		},{
			{1,0,2},{0,2,1},{2,1,0}
		},{
			{1,0,2},{0,2,1},{2,1,0}
		},{
			{1,0,2},{0,2,1},{2,1,0}
		}
	};
	return rm;
}
std::vector<std::vector < std::vector<int>>>getRotationCoords(){//rc[blockInControl][rotationParameter][ 4x (XYZ)]
	std::vector<std::vector<std::vector<int>>> rc = { 
		{ 
			{0,0,0,-1,0,0,1,0,0,0,0,1},{0,0,0,-1,0,0,0,0,-1,0,0,1},{0,0,0,-1,0,0,0,0,-1,1,0,0},{0,0,0,1,0,0,0,0,-1,0,0,1},
			{0,0,0,0,1,0,0,-1,0,0,0,1},{0,0,0,0,1,0,0,-1,0,0,0,-1},{0,0,0,0,1,0,0,-1,0,-1,0,0},{0,0,0,0,1,0,0,-1,0,1,0,0},
			{0,0,0,0,0,1,0,0,-1,0,1,0},{0,0,0,-1,0,0,1,0,0,0,1,0},{0,0,0,0,0,1,0,0,-1,0,-1,0},{0,0,0,-1,0,0,1,0,0,0,-1,0} 
		},{
			{0,0,0,-1,0,0,0,0,1,1,0,1},{0,0,0,0,0,-1,-1,0,0,-1,0,1},{0,0,0,1,0,0,0,0,1,-1,0,1},{0,0,0,-1,0,0,-1,0,-1,0,0,1},
			{0,0,0,0,-1,0,0,0,1,0,1,1},{0,0,0,0,1,0,1,0,0,1,-1,0},{0,0,0,0,1,0,0,0,1,0,-1,1},{0,0,0,0,1,0,-1,0,0,-1,-1,0},
			{0,0,0,0,1,0,0,1,-1,0,0,1},{0,0,0,0,1,0,1,0,0,-1,1,0},{0,0,0,0,1,0,0,1,1,0,0,-1},{0,0,0,0,1,0,-1,0,0,1,1,0}
		},{
			{0,0,0,0,0,1,0,0,-1,0,0,-2},{0,0,0,1,0,0,2,0,0,-1,0,0},{0,0,0,0,-1,0,0,1,0,0,2,0}
		},{
			{0,0,0,1,0,0,0,0,1,1,0,1},{0,0,0,0,1,0,1,0,0,1,1,0},{0,0,0,0,1,0,0,0,1,0,1,1}
		},{
			{0,0,0,1,0,0,-1,0,0,0,0,1,0,0,-1},{0,0,0,0,1,0,0,-1,0,-1,0,0,1,0,0},{0,0,0,0,1,0,0,-1,0,0,0,1,0,0,-1}
		},{
			{0,0,0,0,0,1,0,0,-1,1,0,0,-1,0,0,-1,0,-1,-1,0,1,1,0,-1,1,0,1},{0,0,0,-1,0,0,1,0,0,0,1,0,-1,1,0,1,1,0,0,-1,0,-1,-1,0,1,-1,0},{0,0,0,0,0,1,0,0,-1,0,1,0,0,1,-1,0,1,1,0,-1,0,0,-1,-1,0,-1,1}
		}
	};
		return rc;
}
void drawSingleBlock(ShaderProgram* shader, GLuint t, GLuint t1, GLuint t2, GLuint t3, GLuint t4, GLuint t5, std::vector<std::vector<std::vector<int>>>& tm, int x, int y, int z, bool is1, int bic ) {
	glEnableVertexAttribArray(shader->a("vertex"));
	glVertexAttribPointer(shader->a("vertex"), 4, GL_FLOAT, false, 0, blockVertices);
	glEnableVertexAttribArray(shader->a("normal"));
	glVertexAttribPointer(shader->a("normal"), 4, GL_FLOAT, false, 0, blockVerticesNormals);
	glEnableVertexAttribArray(shader->a("texCoord"));
	glVertexAttribPointer(shader->a("texCoord"), 2, GL_FLOAT, false, 0, blockTexCoords);

	switch (tm[x][y][z]) {
		case 0://gold
			glActiveTexture(GL_TEXTURE2);
			glBindTexture(GL_TEXTURE_2D, t1);
			glUniform1i(shader->u("t"), 2);
			glUniform1i(shader->u("material"), 2);
			break;
		case 1://terakota
			glActiveTexture(GL_TEXTURE3);
			glBindTexture(GL_TEXTURE_2D, t2);
			glUniform1i(shader->u("t"), 3);
			glUniform1i(shader->u("material"), 0);
			break;
		case 2://coal
			glActiveTexture(GL_TEXTURE4);
			glBindTexture(GL_TEXTURE_2D, t3);
			glUniform1i(shader->u("t"), 4);
			glUniform1i(shader->u("material"), 0);
			break;
		case 3://diamond
			glActiveTexture(GL_TEXTURE5);
			glBindTexture(GL_TEXTURE_2D, t4);
			glUniform1i(shader->u("t"), 5);
			glUniform1i(shader->u("material"), 5);
			break;
		case 4: //block
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, t);
			glUniform1i(shader->u("t"), 0);
			glUniform1i(shader->u("material"), 0);
			break;
		case 5://walkus
			glActiveTexture(GL_TEXTURE6);
			glBindTexture(GL_TEXTURE_2D, t5);
			glUniform1i(shader->u("t"), 6);
			glUniform1i(shader->u("material"), 0);
			break;
		default:
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, t);
			glUniform1i(shader->u("t"), 0);
			glUniform1i(shader->u("material"), 0);
			break;
	}
	glDrawArrays(GL_TRIANGLES, 0, blockVertexCount);
	glDisableVertexAttribArray(shader->a("normal"));
	glDisableVertexAttribArray(shader->a("vertex"));
	glDisableVertexAttribArray(shader->a("texCoord"));
}

