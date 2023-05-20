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



    //casa
    Sculptor teste1(24,10,14);
    teste1.setColor(0.5,0.5,0.7,1.0); //cor
    teste1.putBox(0,23,0,9,0,13); //define todos ativos
    teste1.cutBox(4,19,1,8,3,10); // tira a parte interna
    teste1.cutBox(0,2,0,9,0,13); //tira primeiras 2 linhas
    teste1.cutBox(21,23,0,9,0,13); //tira ultimas 2 linhas
    teste1.cutBox(0,23,7,9,0,13); //tira as 2 linhas de cima
    teste1.cutBox(0,23,0,9,0,1); //tira as 2 linhas da frente
    teste1.cutBox(0,23,0,9,12,13); //tira as 2 linhas da frente
    teste1.setColor(0.1,0.9,0.1,1.0);
    teste1.putBox(0,0,6,6,0,13); //telhadoy1 esquerdo
    teste1.putBox(23,23,6,6,0,13); //telhadoy1 direito
    teste1.putBox(1,22,7,7,1,12); //telhadoy2
    teste1.putBox(2,21,8,8,2,11); //telhadoy3
    teste1.putBox(3,20,9,9,3,10); //telhadoy4
    teste1.putBox(0,23,6,6,0,0); //telhado z frente
    teste1.putBox(0,23,6,6,13,13); //telhado z trás
    //teste1.putBox(0,0,10,10,0,13);
    teste1.writeOFF("casa.off");
*/
    //testando ellipsoid:
    Sculptor elipse(30,20,20);
    elipse.setColor(0.4, 0.4, 0.7, 0.8);
    elipse.putEllipsoid(15,10,10,13,5,5);
    elipse.writeOFF("elipse.off");

    return 0;
}









