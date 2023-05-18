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


    //testando sphere:
    Sculptor esfera(11,11,11);
    esfera.setColor(0.3, 0.8, 1.0, 0.0);
    esfera.putSphere(5, 5, 5, 3);
    esfera.writeOFF("esfera.off");



    Sculptor esfera(20,20,20);
    esfera.setColor(0.3, 0.8, 1.0, 0.0);
    esfera.putSphere(9,9,9,6);
    esfera.cutSphere(9,9,9,3);
    esfera.writeOFF("esfera.off");
*/
    //testando ellipsoid:
    Sculptor elipse(30,20,20);
    elipse.setColor(0.6, 0.4, 1.0, 0.0);
    elipse.putEllipsoid(15,10,10,13,5,5);
    elipse.writeOFF("elipse.off");

    return 0;
}
