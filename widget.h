#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QGLWidget>

class Widget : public QGLWidget
{   Q_OBJECT

public:
    Widget(QWidget *parent = 0);



    QOpenGLShaderProgram m_program;
    int m_vertexAttrLoc;
    int m_textureAttrLoc;
    int m_textureUniformLoc;
    int m_normalAttrLoc;

    int m_lightPosLoc;

    int m_mvMatrixLoc;
    int m_projMatrixLoc;
    int m_normalMatrixLoc;

    //Cube *m_cube;

    QPoint m_mousePosition;
    float m_xRot;
    float m_zRot;
    float m_scale;




    float eyeX ;
    float eyeY ;
    float eyeZ ;
    float centerX;
    float centerY;
    float centerZ;
    float upX ;
    float upY ;
    float upZ;








    QMatrix4x4 m_world;
    QMatrix4x4 m_camera;
    QMatrix4x4 m_proj;

     GLuint textureID[];

      QImage image;


    // QImage image;



     int m_colorx;
     int m_colory;

    QOpenGLTexture *m_textureOfFront;

    std::vector<float> verticesForFront;
    std::vector<float> textureCoordsForFront;
    std::vector<float> normalsForFront;


      std::vector<float> cameraAttr;
       int m_cameraAttr;



            void wheelEventSalf( int d  );
            void mousePressEventSalf( QPoint p );
            void mouseMoveEventSalf( QPoint p );

            protected:
            void initializeGL();
            void resizeGL(int nWidth, int nHeight);
            void paintGL();






   void scalePlus();
   void scaleMinus();





};

#endif // WIDGET_H
