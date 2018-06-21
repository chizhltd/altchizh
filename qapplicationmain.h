#ifndef QAPPLICATIONMAIN_H
#define QAPPLICATIONMAIN_H
#include <QApplication>

class QApplicationMain:public QApplication
{   Q_OBJECT
public:

    QApplicationMain(int & argc, char ** argv);

    virtual bool notify(QObject * receiver, QEvent * e);





};

#endif // QAPPLICATIONMAIN_H
