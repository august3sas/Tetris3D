#version 330

//Uniform variables
uniform mat4 P;
uniform mat4 V;
uniform mat4 M;
uniform mat4 I;

vec4 lp=vec4(0,22,0,1);
//vec4 lps2=vec4(10,4,10,1);
vec4 lps2=vec4(8,22,8,1);
//Attributes
in vec4 vertex; //Vertex coordinates in model space
in vec4 normal; //Vrtex normal in model space
in vec2 texCoord;

//Varying variables
out vec4 l;
out vec4 l2;
out vec4 n;
out vec4 v;
out vec2 iTexCoord;

void main(void) {
    
    l = normalize(V * I * lp - V * M * vertex); //vector towards the light in eye space
    l2= normalize(V * I * lps2 - V * M * vertex);
    v = normalize(vec4(0, 0, 0, 1) - V * M * vertex); //vector towards the viewer in eye space
    n = normalize(V * M * normal); //normal vector in eye space

    iTexCoord = texCoord;

    gl_Position = P * V * M * vertex;
}