#version 330


out vec4 pixelColor; //Output variable. Almost final pixel color.

uniform sampler2D t;

//Varying variables
in vec4 n;
in vec4 l;
in vec4 v;
in vec4 l2;
in vec2 iTexCoord;
in vec2 iTexCoord2;
uniform int material;

void main(void) {
    float ambientStrength=0.2;
    vec3 lightColor=vec3(1,1,1);
    vec3 ambient=ambientStrength*lightColor;
    //Normalized, interpolated vectors
    vec4 ml = normalize(l);
    vec4 ml2 = normalize(l2);
    vec4 mn = normalize(n);
    vec4 mv = normalize(v);

    vec4 mr = reflect(-ml, mn);
    vec4 mr2 = reflect(-ml2, mn);

    //Surface parameters
    vec4 kd1=texture(t, iTexCoord);
    vec4 kd = texture(t, iTexCoord)*0.5;
    vec4 ks = vec4(1,1,1,1);
    if(material==1){
        pixelColor=vec4(kd1);
    }else{
    //Lighting model computation
    float nl = clamp(dot(mn, ml), 0, 1);
    float nl2=clamp(dot(mn,ml2),0,1);
    float rv=pow(clamp(dot(mr,mv),0,1),400)*0.5;
    float rv2 = pow(clamp(dot(mr2,mv),0,1),400)*0.5;
    if(material==2||material==5) pixelColor = clamp(vec4(ambient*kd.rgb,kd.a)+vec4(kd.rgb * nl, kd.a) + vec4(kd.rgb * nl2, kd.a)+vec4(kd1.rgb*rv,0)+vec4(kd1.rgb*rv2,0),0,1);
    else pixelColor = clamp(vec4(ambient*kd.rgb,kd.a)+vec4(kd.rgb * nl, kd.a) + vec4(kd.rgb * nl2, kd.a)+vec4(rv,rv,rv,0)+vec4(rv2,rv2,rv2,0),0,1);
    }
}