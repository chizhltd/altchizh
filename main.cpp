#include <QtGui>
#include "widget.h"

#include "mainwindow.h"
#include <QDebug>
#include <QEvent>

#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QPoint>
class MyApp : public QApplication
{
public:

     Widget *w1;
     Widget *w2;

   MyApp(int & argc, char ** argv) : QApplication(argc, argv) {}

   virtual bool notify(QObject * receiver, QEvent * e)
   {
      if (e->type() == QEvent::Wheel)
      {
  int d=dynamic_cast<QWheelEvent*>(e)->angleDelta().y();
        w1->wheelEventSalf(d);
        w2->wheelEventSalf(d);


      }


      if (e->type() == QEvent::MouseButtonPress)
      {

       QPoint   d=dynamic_cast<QMouseEvent*>(e)->pos();
        w1->mousePressEventSalf(d);
        w2->mousePressEventSalf(d);


      }

      if (e->type() == QEvent::MouseMove)
      {
  QPoint d=dynamic_cast<QMouseEvent*>(e)->pos();
        w1->mouseMoveEventSalf(d);
        w2->mouseMoveEventSalf(d);


      }
      return QApplication::notify(receiver, e);
   }
};









int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
   MyApp a(argc, *&argv);



   Widget w1;
    Widget w2;
a.w1=&w1;
a.w2=&w2;



    //w.show();

    MainWindow *window = new MainWindow;
       QPushButton *button1 = new QPushButton("One");
       QPushButton *button2 = new QPushButton("Two");


       QGridLayout *layout = new QGridLayout;
       layout->addWidget(button1, 0, 0);
       layout->addWidget(button2, 0, 1);
       layout->addWidget(&w1, 1, 0);
       layout->addWidget(&w2, 1, 1);



       window->setLayout(layout);
       window->resize(500,300 );
       window->show();



    return a.exec();
}
