



uniform sampler2D textureUniform;

varying highp vec3 vertex;

varying highp vec2 textureCoords;

void main()
{

    highp vec3 col = texture2D( textureUniform, textureCoords ).xyz;
    gl_FragColor = vec4( col, 1.0 );

  // gl_FragColor = vec4(0.9, 0.5, 0.5, 0.5);;
}
