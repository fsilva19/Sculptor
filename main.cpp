//#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include "sculptor.h"
using namespace std;

int main()
{
/*
    Sculptor trono(50, 10, 10);
    trono.setColor(0.3, 0.8, 1.0, 0.0);
    trono.putBox(0,49,0,9,0,9);
    trono.cutBox(4,4,0,9,0,9);
    trono.cutBox(1,3,7,8,0,9);
    trono.cutBox(1,3,0,5,0,9);
    trono.writeOFF("trono.off");

    //testando box
    Sculptor trono(10,10,10);
    trono.setColor(0.3, 0.8, 1.0, 0.9);
    trono.putBox(0,9,0,9,0,9);
    trono.cutBox(1,8,1,9,1,9);
    trono.writeOFF("trono.off");
    return 0;
*/
    //testando sphere:
    Sculptor esfera(11,11,11);
    esfera.setColor(0.3, 0.8, 1.0, 0.0);
    esfera.putSphere(5, 5, 5, 3);
    esfera.writeOFF("esfera.off");
}
/*
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Sculptor trono(10, 10, 10);
    trono.setColor(0, 0, 1.0, 1.0);
    trono.putBox(0,9,0,9,0,9);
    /*trono.cutBox(1,8,1,9,1,9);
trono.writeOFF("trono.off");

return a.exec();
}
*/
