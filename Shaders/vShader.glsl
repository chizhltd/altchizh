attribute highp vec2  cameraAttr;

attribute highp vec4 vertexAttr;
attribute highp vec2 textureAttr;

uniform highp mat4 mvMatrix;
uniform highp mat4 projMatrix;

varying highp vec2 textureCoords;

void main()
{  vec4 PositionP;
    float x;
    float y;
    float xn;
    float yn;

    float k1;
    float k2;

    float l;
    vec2 tecV2;
   mat4 m41,m42;



k1=0.001;
k2=0.8;


   m41=  mat4(1.0,  0.0,  0.0, -1.0,
         0.0,  1.0,  0.0, -1.0,
         0.0,  0.0,  1.0,  0.0,
         0.0,  0.0,  0.0, 1.0);;
   PositionP =normalize( projMatrix * mvMatrix * vertexAttr*m41);
   x=PositionP.x;
   y=PositionP.y;

   l=sqrt(x*x+y*y);
   xn =x/(1+k1*l*l+k2*l*l*l*l);
   yn =y/(1+k1*l*l+k2*l*l*l*l);



   PositionP.x= xn
          ;
   PositionP.y= yn;



gl_Position =PositionP;


    textureCoords = textureAttr;

}
