#version 330

//Uniform variables
uniform mat4 P;
uniform mat4 V;
uniform mat4 M;

//light coordinates in world space
vec4 lps1=vec4(10,4,20,1);
vec4 lps2=vec4(4,-2,20,1);
out vec4 i_c;
out vec4 l;
out vec4 n;
out vec4 v;
//Attributes
in vec4 vertex; //Vertex coordinates in model space
in vec4 color;
in vec4 normal;

void main(void) {
    //vec4 lp=vec4(0,0,-6,1);//world
    //converting from eye space to world space
    vec4 l1=normalize(V*lps1-V*M*vertex);
    vec4 l2=normalize(V*lps2-V*M*vertex);
    l=normalize(l1+l2);
    n=normalize(V*M*normal);
    v=normalize(vec4(0,0,0,1)-V*M*vertex);
    i_c=color;
    gl_Position=P*V*M*vertex;
}