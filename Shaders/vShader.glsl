attribute highp vec2  cameraAttr;
attribute highp vec4 vertexAttr;
attribute highp vec2 textureAttr;
uniform highp mat4 mvMatrix;
uniform highp mat4 projMatrix;
varying highp vec2 textureCoords;

void main()
{  vec4 PositionP;



    float k1;
    float k2;


    vec2 tecV2;
   mat4 m41,m42;

  //  vec2 newV2;




   m41=  mat4(1.0,  0.0,  0.0, -1.0,
         0.0,  1.0,  0.0, -1.0,
         0.0,  0.0,  1.0,  0.0,
         0.0,  0.0,  0.0, 1.0);;












    gl_Position = projMatrix * mvMatrix * vertexAttr*m41;

    textureCoords = textureAttr;

}
