#include "widget.h"

#include <iostream>
#include <QDebug>
#include <QPoint>
#include <QMatrix4x4>

Widget::Widget(QWidget *parent)
    : QGLWidget(parent),
      m_xRot( 0.0f ),
      m_zRot( 0.0f ),
      m_scale( 1.0f )

{
   // resize(1000,500);
}

void Widget::initializeGL()
{
   qglClearColor(Qt::white);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_FLAT);
   glEnable(GL_CULL_FACE);
   glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);


   //инициализация всей хрени.

   QOpenGLShader vShader( QOpenGLShader::Vertex );
   vShader.compileSourceFile( ":/Shaders/vShader.glsl" );
   vShader.sourceCode();
   QByteArray qb;

   qb=vShader.sourceCode();

   QOpenGLShader fShader( QOpenGLShader::Fragment );
   fShader.compileSourceFile( ":/Shaders/fShader.glsl" );

   m_program.addShader( &vShader );
   m_program.addShader( &fShader );
   if ( !m_program.link() )
   {
       ;
       qDebug() << "Error: unable to link a shader program..";

       return;
   }


   m_cameraAttr  = m_program.attributeLocation("cameraAttr");
   m_vertexAttrLoc = m_program.attributeLocation( "vertexAttr" );
   m_textureAttrLoc = m_program.attributeLocation( "textureAttr" );
   m_textureUniformLoc = m_program.uniformLocation( "textureUniform" );
   m_mvMatrixLoc = m_program.uniformLocation( "mvMatrix" );
   m_projMatrixLoc = m_program.uniformLocation( "projMatrix" );


   if ( !m_program.bind() )
   {
       qDebug() << "Error: unable to bind a shader program.";
       return;
   }


   m_program.release();


      image = QImage( ":/Textures/Skies0204_4_S.jpg"  );
   if ( image.isNull() )
   {
        qDebug() << "Error: the incorrect path the left image: \"";
       return ;
   }

    image = QGLWidget::convertToGLFormat(image);


        glGenTextures(1, textureID);
        glBindTexture(GL_TEXTURE_2D, textureID[0]);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, (GLsizei)image.width(), (GLsizei)image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE,  image.bits());
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glEnable(GL_TEXTURE_2D);




   m_camera.setToIdentity();
   m_camera.translate( 0.0f, 0.0f, -5.0f );

   glEnable( GL_DEPTH_TEST );




 float x1=0;
 float y1=0;

 float x2=0;
 float y2=0;


 float x3=0;
 float y3=0;


 float kx=0;
 float ky=0;

for(int j=0;j<10;j++){

        for(int i=0; i<10;i++){

            kx=i*0.1;
            ky=j*0.1;

         x1=kx;
         y1=ky;

         x2=(kx+0.1);
         y2=(ky);


         x3=(kx+0.1);
         y3=(ky+0.1);


                  verticesForFront.push_back((float)x1  );   cameraAttr.push_back(1);
                  verticesForFront.push_back((float)y1 );
                  verticesForFront.push_back(01.0f  );

                        textureCoordsForFront.push_back( x1  );
                        textureCoordsForFront.push_back( y1 );




                   verticesForFront.push_back((float)x2 );  cameraAttr.push_back(1);
                   verticesForFront.push_back((float)y2 );
                    verticesForFront.push_back(01.0f  );





                    textureCoordsForFront.push_back(  x1 );
                     textureCoordsForFront.push_back( y1);








                    verticesForFront.push_back((float)x3);  cameraAttr.push_back(1);
                    verticesForFront.push_back((float)y3);
                   verticesForFront.push_back(01.0f );



                     textureCoordsForFront.push_back( x3 );
                     textureCoordsForFront.push_back( y3 );



           }

   }



}







void Widget::resizeGL(int nWidth, int nHeight)
{

    glViewport(0, 0, nWidth, nHeight);
    m_proj.setToIdentity();
    m_proj.perspective( 45.0f, float( nWidth ) / float( nHeight ), 0.01f, 500.0f );
}



void Widget::paintGL() // рисование
{





    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    if ( !m_program.bind() )
        return;

    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );

    m_world.setToIdentity();
    m_world.scale( m_scale );

//трансформация
    //QMatrix4x4 mt(1.0f,  0.0f,   0.0f,  0.0f,
    //              0.0f,  1.0f,   0.0f,  0.0f,
     //             0.0f,  0.0f,   0.0f, 100.0f,
     //             0.0f,   0.0f ,  0.0f,  1.0f);
//
   // m_world=m_world;

    m_program.setUniformValue( m_mvMatrixLoc, m_camera * m_world );
    m_program.setUniformValue( m_projMatrixLoc, m_proj );
    m_program.setAttributeArray( m_cameraAttr, cameraAttr.data(),1);
    m_program.setAttributeArray( m_vertexAttrLoc, verticesForFront.data(), 3 );
    m_program.setAttributeArray( m_textureAttrLoc, textureCoordsForFront.data(), 2 );
    m_program.setUniformValue( m_textureUniformLoc, 0 );
    m_program.enableAttributeArray( m_vertexAttrLoc );
    m_program.enableAttributeArray( m_textureAttrLoc );



    glDrawArrays( GL_TRIANGLES, 0, verticesForFront.size() / 3);

          m_program.disableAttributeArray( m_vertexAttrLoc );
          m_program.disableAttributeArray( m_normalAttrLoc );
          m_program.disableAttributeArray( m_textureAttrLoc );


    m_program.release();


}



void Widget::wheelEventSalf(int d )
{
    if ( d > 0 )
        scalePlus();
    else if ( d < 0 )
        scaleMinus();

    update();
}

void Widget::scalePlus()
{
    m_scale *= 1.1f;
}

void Widget::scaleMinus()
{
    m_scale /= 1.1f;
}




void Widget::mousePressEventSalf( QPoint p )
{

    m_mousePosition = p;
}

void Widget::mouseMoveEventSalf( QPoint p )
{
  //  m_xRot += 180.0f * ( float ) ( p.y() - m_mousePosition.y() ) / height();
   // m_zRot += 180.0f * ( float ) ( p.x() - m_mousePosition.x() ) / width();



 //    eyeX +=(p.x() - m_mousePosition.x() ) / width()   ;
//    float eyeY ;
//    float eyeZ ;
//    float centerX;
//    float centerY;
//    float centerZ;
//    float upX ;
//    float upY ;
//    float upZ;




    m_mousePosition = p;

    update();
    m_mousePosition = p;

    update();
}


