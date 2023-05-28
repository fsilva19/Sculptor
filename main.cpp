//#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include "sculptor.h"


using namespace std;

int main()
{
  
    Sculptor sculptor(20, 20, 20);

    // Definição das cores
    sculptor.setColor(1.0, 0.0, 0.0, 1.0); // Vermelho opaco

    // Desenho do cubo
    sculptor.putBox(0, 4, 0, 4, 0, 4);

    // Removendo parte interna do cubo
    sculptor.cutBox(1,3,1,3,1,3);

    // Definição das cores
    sculptor.setColor(0.0, 1.0, 0.0, 1.0); // Verde opaco

    // Desenho da esfera
    sculptor.putSphere(10, 5, 5, 3);

    // Removendo parte interna da esfera
    sculptor.cutSphere(10, 5, 5, 2);

    // Definição das cores
    sculptor.setColor(0.0, 0.0, 1.0, 1.0); // Azul opaco

    // Desenho do elipsoide
    sculptor.putEllipsoid(3, 9, 5, 3, 2, 2);

    // Gravação do Sculptor em formato OFF
    sculptor.writeOFF("exemplo.off");

    return 0;
}









