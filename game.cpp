
#include "game.h"

std::vector<std::vector<std::vector<int>>>createOccupancyMatrix(int dim1, int dim2, int dim3) {
	std::vector<std::vector<std::vector<int>>>om(dim1, std::vector<std::vector<int>>(dim2+4, std::vector<int>(dim3)));
	return om;
}
std::vector<std::vector<std::vector<int>>>createTextureMatrix(int dim1, int dim2, int dim3) {
	std::vector<std::vector<std::vector<int>>>tm(dim1, std::vector<std::vector<int>>(dim2 + 4, std::vector<int>(dim3)));
	return tm;
}
void drawFromOccupancyMatrix(std::vector<std::vector<std::vector<int>>>& om, int dim1, int dim2, int dim3, glm::mat4 draw,ShaderProgram* shader,GLuint t, GLuint t1, GLuint t2, GLuint t3, GLuint t4, GLuint t5, std::vector<std::vector<std::vector<int>>>& tm,int bic) {
	
	for (int x = 0; x < dim1; x++) {
		for (int y = 0; y < dim2; y++) {
			for (int z = 0; z < dim3; z++) {
				if (om[x][y][z] == 1) {
					glUniformMatrix4fv(shader->u("M"), 1, false, glm::value_ptr(draw));
					drawSingleBlock(shader,t,t1,t2,t3,t4,t5,tm,x,y,z,true,-1);
				}
				else if (om[x][y][z] == 2) {
					glUniformMatrix4fv(shader->u("M"), 1, false, glm::value_ptr(draw));
					drawSingleBlock(shader, t, t1,t2,t3,t4,t5,tm,x,y,z, false,bic);
				}
				draw=glm::translate(draw, glm::vec3(0.0f,0.0f,1.0f));//increases Z coordinate
			}
			draw=glm::translate(draw, glm::vec3(0.0f, 1.0f, float(-dim3)));//sets Z to 0, increases Y coordinate
		}
		draw=glm::translate(draw, glm::vec3(1.0f, float(-dim2), 0.0f));//sets Y to 0, increases X coordinate
	}
	draw=glm::translate(draw, glm::vec3(float(-dim1), 0.0f, 0.0f));//sets X to 0
}
void printOccupancyMatrix(std::vector<std::vector<std::vector<int>>>& om) {
	for (int y = 15; y < 20; y++) {
		std::cout << "\n-------------------------------------------------------\n OccupancyMatrix level " << y << "\n";
		for (int z = 7; z >= 0; z--) {
			for (int x = 7; x >= 0; x--) {
				std::cout << om[x][y][z];
			}
			std::cout << "\n";
		}
	}
}
void occupancyMatrixReset2(std::vector<std::vector<std::vector<int>>>& om) {
	for (int y = 0; y < 24; y++) {
		for (int z = 7; z >= 0; z--) {
			for (int x = 7; x >= 0; x--) {
				if (om[x][y][z] == 2)om[x][y][z] = 0;
			}
		}
	}
}
void setResidualBlocks(std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& tm) {
	for (int x = 0; x < 8; x++) {
		for (int y = 0; y < 24; y++) {
			for (int z = 0; z < 8; z++) {
				if (om[x][y][z] == 2)om[x][y][z] = 1;
			}
		}
	}
	deleteFullRows(om,tm);
}
void deleteFullRows(std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& tm) {
	std::vector<std::vector<std::vector<int>>> buf=createOccupancyMatrix(8,23,8); //keeps non-full layers
	std::vector<std::vector<std::vector<int>>> tbuf = createOccupancyMatrix(8, 23, 8);
	std::vector<int> nbuf;//keeps non-full layers y coordinate because i wrote occupancy matrix in a stupid way
	for (int y = 0; y < 23; y++) {
		if (!checkIfRowFull(om,y))nbuf.push_back(y);
	}
	int bufLevel = 0;
	for (int x = 0; x < 8; x++) {
		for (int z = 0; z < 8; z++) {
			for (int y = 0; y < nbuf.size(); y++) {
				buf[x][y][z] = om[x][nbuf[y]][z];
				tbuf[x][y][z] = tm[x][nbuf[y]][z];
			}
		}
	}
	om = buf;
	tm = tbuf;

}
bool checkIfRowFull(std::vector<std::vector<std::vector<int>>>& om, int y) {
	for (int x = 0; x < 8; x++) {
		for (int z = 0; z < 8; z++) {
			if (om[x][y][z] == 2 || om[x][y][z] == 0)return false;
		}
	}
	return true;
}
bool checkForSpawnPrerequisites(int bic, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc){
	//spawn on Central Coord, rotation parameter=0
	int centr_x = 3;
	int centr_y = 19;
	int centr_z = 3;
	
	for (int i = 0; i < rc[bic][0].size(); i += 3) {
		//std::cout << centr_x + rc[bic][0][i] << " " << centr_y + rc[bic][0][i + 1] << " " << centr_z + rc[bic][0][i + 2] << std::endl;
		if (om[centr_x + rc[bic][0][i]][centr_y + rc[bic][0][i + 1]][centr_z + rc[bic][0][i + 2]] == 1) {
			//std::cout << "ADIEU" << std::endl;
			return false;
		}
	}
	//std::cout << "SIEMA" << std::endl;
	return true;
}
void spawnBlock(int bic, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, std::vector<std::vector<std::vector<int>>>& tm) {
	int centr_x = 3;
	int centr_y = 19;
	int centr_z = 3;
	for (int i = 0; i < rc[bic][0].size(); i += 3) {
		//std::cout << centr_x + rc[bic][0][i] << " " << centr_y + rc[bic][0][i + 1] << " " << centr_z + rc[bic][0][i + 2] << std::endl;
		om[centr_x + rc[bic][0][i]][centr_y + rc[bic][0][i + 1]][centr_z + rc[bic][0][i + 2]] = 2;
		tm[centr_x + rc[bic][0][i]][centr_y + rc[bic][0][i + 1]][centr_z + rc[bic][0][i + 2]] = bic;
	}
	//std::cout << om[3][19][3] << " : OM 3 19 3\n";
}
bool checkForDownMovement(int bic, int rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, bool& sig1, std::vector<std::vector<std::vector<int>>>& tm) {
	//sig1 - SIG_BLOCK_SPAWNED
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {
		if ((cc[1] + rc[bic][rparam][i + 1] - 1)<0) {
			//std::cout << "ADIEU DOWN: KONIEC RUCHU" << std::endl;
			setResidualBlocks(om,tm);
			sig1 = false;
			return false;
		}
	}
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {
		
		//std::cout <<"cfdm "<< cc[0] + rc[bic][rparam][i] << " " << cc[1] + rc[bic][rparam][i + 1]-1 << " " << cc[2] + rc[bic][rparam][i + 2] << std::endl;
		if (om[ cc[0] + rc[bic][rparam][i] ][(cc[1] + rc[bic][rparam][i + 1])-1][cc[2] + rc[bic][rparam][i + 2]] == 1) {
			//std::cout << "ADIEU DOWN: KONIEC RUCHU BO KLOCEK" << std::endl;
			setResidualBlocks(om,tm);
			sig1 = false;
			return false;
		}
	}
	//std::cout << "SIEMA DOWN" << std::endl;
	return true;
}
void downMovement(int bic, int rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, std::vector<std::vector<std::vector<int>>>& tm) {
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {
		om[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 0;
		tm[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 0;
	}
	cc = { cc[0],cc[1] - 1,cc[2] };
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {
		om[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 2;
		tm[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = bic;
	}
}
bool checkForXAxisMovement(int bic, int rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc,int pm) {
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {
		if ((cc[0] + rc[bic][rparam][i] +pm) < 0|| (cc[0] + rc[bic][rparam][i] + pm) > 7) {
			//std::cout << "ADIEU X: KONIEC RUCHU" << std::endl;
			return false;
		}
	}
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {

		//std::cout << "cfxam " << cc[0] + rc[bic][rparam][i] << " " << cc[1] + rc[bic][rparam][i + 1] - 1 << " " << cc[2] + rc[bic][rparam][i + 2] << std::endl;
		if (om[cc[0] + rc[bic][rparam][i]+pm][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] == 1) {
			//std::cout << "ADIEU X" << std::endl;
			return false;
		}
	}
	//std::cout << "SIEMA X" << std::endl;
	return true;
}
void xAxisMovement(int bic, int rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc,int pm, std::vector<std::vector<std::vector<int>>>& tm) {
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {
		om[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 0;
		tm[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 0;
	}
	cc = { cc[0]+pm,cc[1],cc[2] };
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {
		om[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 2;
		tm[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = bic;
	}
}
bool checkForZAxisMovement(int bic, int rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, int pm) {
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {
		//std::cout << "Zc: " << cc[2] + rc[bic][rparam][i] + pm << std::endl;
		if ((cc[2] + rc[bic][rparam][i+2]+pm) < 0 || (cc[2] + rc[bic][rparam][i+2] + pm) > 7) {
			//std::cout << "ADIEU Z" << std::endl;
			return false;
		}
	}
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {

		//std::cout << "cfxam " << cc[0] + rc[bic][rparam][i] << " " << cc[1] + rc[bic][rparam][i + 1] - 1 << " " << cc[2] + rc[bic][rparam][i + 2] << std::endl;
		if (om[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]+pm] == 1) {
			//std::cout << "ADIEU Z" << std::endl;
			return false;
		}
	}
	//std::cout << "SIEMA Z" << std::endl;
	return true;
}
void zAxisMovement(int bic, int rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, int pm, std::vector<std::vector<std::vector<int>>>& tm) {
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {
		om[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 0;
		tm[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 0;
	}
	cc = { cc[0],cc[1],cc[2]+pm };
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {
		om[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 2;
		tm[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = bic;
	}
}
bool checkForXAxisRotation(int bic, int& rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, std::vector<std::vector<std::vector<int>>>& rm) {
	int nextRparam = rm[bic][rparam][0];
		for (int i = 0; i < rc[bic][nextRparam].size(); i += 3) {
			if (
				cc[0] + rc[bic][nextRparam][i] < 0 || cc[0] + rc[bic][nextRparam][i]>7 ||
				cc[1] + rc[bic][nextRparam][i + 1] < 0 || cc[1] + rc[bic][nextRparam][i + 1]>23 ||
				cc[2] + rc[bic][nextRparam][i + 2] < 0 || cc[2] + rc[bic][nextRparam][i + 2]>7
				)return false;
			if (om[cc[0] + rc[bic][nextRparam][i]][cc[1] + rc[bic][nextRparam][i + 1]][cc[2] + rc[bic][nextRparam][i + 2]] == 1)return false;
		}
		return true;
}
void xAxisRotation(int bic, int& rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, std::vector<std::vector<std::vector<int>>>& rm, std::vector<std::vector<std::vector<int>>>& tm) {
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {
		om[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 0;
		tm[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 0;
	}
	rparam = rm[bic][rparam][0];
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {
		om[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 2;
		tm[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = bic;
	}
}
bool checkForYAxisRotation(int bic, int& rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, std::vector<std::vector<std::vector<int>>>& rm) {
	int nextRparam = rm[bic][rparam][1];
	for (int i = 0; i < rc[bic][nextRparam].size(); i += 3) {
		if (
			cc[0] + rc[bic][nextRparam][i] < 0 || cc[0] + rc[bic][nextRparam][i]>7 ||
			cc[1] + rc[bic][nextRparam][i + 1] < 0 || cc[1] + rc[bic][nextRparam][i + 1]>23 ||
			cc[2] + rc[bic][nextRparam][i + 2] < 0 || cc[2] + rc[bic][nextRparam][i + 2]>7
			)return false;
		if (om[cc[0] + rc[bic][nextRparam][i]][cc[1] + rc[bic][nextRparam][i + 1]][cc[2] + rc[bic][nextRparam][i + 2]] == 1)return false;
	}
	return true;
}
void yAxisRotation(int bic, int& rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, std::vector<std::vector<std::vector<int>>>& rm, std::vector<std::vector<std::vector<int>>>& tm) {
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {
		om[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 0;
		tm[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 0;
	}
	rparam = rm[bic][rparam][1];
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {
		om[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 2;
		tm[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = bic;
	}
}
bool checkForZAxisRotation(int bic, int& rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, std::vector<std::vector<std::vector<int>>>& rm) {
	int nextRparam = rm[bic][rparam][2];
	for (int i = 0; i < rc[bic][nextRparam].size(); i += 3) {
		if (
			cc[0] + rc[bic][nextRparam][i] < 0 || cc[0] + rc[bic][nextRparam][i]>7 ||
			cc[1] + rc[bic][nextRparam][i + 1] < 0 || cc[1] + rc[bic][nextRparam][i + 1]>23 ||
			cc[2] + rc[bic][nextRparam][i + 2] < 0 || cc[2] + rc[bic][nextRparam][i + 2]>7
			)return false;
		if (om[cc[0] + rc[bic][nextRparam][i]][cc[1] + rc[bic][nextRparam][i + 1]][cc[2] + rc[bic][nextRparam][i + 2]] == 1)return false;
	}
	return true;
}
void zAxisRotation(int bic, int& rparam, std::vector<int>& cc, std::vector<std::vector<std::vector<int>>>& om, std::vector<std::vector<std::vector<int>>>& rc, std::vector<std::vector<std::vector<int>>>& rm, std::vector<std::vector<std::vector<int>>>& tm) {
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {
		om[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 0;
		tm[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 0;
	}
	rparam = rm[bic][rparam][2];
	for (int i = 0; i < rc[bic][rparam].size(); i += 3) {
		om[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = 2;
		tm[cc[0] + rc[bic][rparam][i]][(cc[1] + rc[bic][rparam][i + 1])][cc[2] + rc[bic][rparam][i + 2]] = bic;
	}
}