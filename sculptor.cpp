#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    //define as dimensões da matriz 3D
    nx = _nx;
    ny = _ny;
    nz = _nz;

    //aloca a matriz 3D;
    v = new Voxel**[nx]; //aloca um ponteiro pra ponteiro pra ponteiro pra Voxel
    for(int i=0; i<nx; i++){
        v[i] = new Voxel*[nx*ny]; //aloca um ponteiro pra ponteiro pra Voxel
        for(int j=0; j<ny; j++){
            v[i][j] = new Voxel[nx*ny*nz]; //aloca um ponteiro pra Voxel
        }
    }


}
Sculptor::~Sculptor(){
    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            delete []v[i][j]; //deleta a memória de 3 dimensões
        }
        delete []v[i]; //deleta a memória de 2 dimensões
    }
    delete []v; //deleta a memória de uma dimensão
}
void Sculptor::setColor(float red, float green, float blue, float alpha){
    //Altera os respectivos valores de r, g, b e a na classe Sculptor
    r = red;
    g = green;
    b = blue;
    a = alpha;
}
void Sculptor::putVoxel(int x, int y, int z){
    // A função putVoxel da classe Sculptor é responsável por ativar (ou "colocar") um voxel
    // na posição especificada da matriz 3D. Ela marca o voxel como visível (atributo show definido como true) e define
            // as propriedades de cor (atributos r, g, b) e transparência (atributo a) desse voxel.
    if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        // condição de verificação dos limites da matriz tridimensional v antes de acessar um elemento específico.
                // Ele garante que os índices x, y e z estejam dentro dos limites válidos da matriz antes de realizar qualquer operação.

        v[x][y][z].show = true;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
    }
}
void Sculptor::cutVoxel(int x, int y, int z){
    v[x][y][z].show = false;
}
void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
    // A função putBox é responsável por criar uma caixa de voxels visíveis dentro da escultura.
            // Ela recebe as coordenadas dos vértices opostos da caixa (x0, x1, y0, y1, z0, z1)
            // e ativa os voxels correspondentes nessa região, ou seja, os voxels que estão dentro ou na superfície da caixa.
    for (int x = x0; x <= x1; x++) {
        for (int y = y0; y <= y1; y++) {
            for (int z = z0; z <= z1; z++) {
                putVoxel(x, y, z);
            }
        }
    }
}
void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    // A função putBox é responsável por criar uma caixa de voxels visíveis dentro da escultura.
    // Ela recebe as coordenadas dos vértices opostos da caixa (x0, x1, y0, y1, z0, z1)
    // e ativa os voxels correspondentes nessa região, ou seja, os voxels que estão dentro ou na superfície da caixa.
    for (int x = x0; x <= x1; x++) {
        for (int y = y0; y <= y1; y++) {
            for (int z = z0; z <= z1; z++) {
                cutVoxel(x, y, z);
            }
        }
    }
}
void Sculptor::writeOFF(const char* filename){
    std::ofstream file;
    file.open(filename);

    // Conta o número total de voxels visíveis

    int totalVertices = 0;
    int totalFaces = 0;

    // Conta o número total de vértices e faces
    // Dentro dos loops for, ele verifica se o voxel na posição (x, y, z) está marcado como visível (v[x][y][z].show). Se estiver visível, incrementa o contador
            // totalVertices em 8 (cada voxel contribui com 8 vértices em um cubo) e incrementa o contador totalFaces em 6 (cada voxel contribui com 6 faces em um cubo).
    for (int x = 0; x < nx; x++) {
        for (int y = 0; y < ny; y++) {
            for (int z = 0; z < nz; z++) {
                if (v[x][y][z].show) {
                    totalVertices += 8;
                    totalFaces += 6;
                }
            }
        }
    }
    file << "OFF" << std::endl;
    file << totalVertices <<" "<< totalFaces <<" 0" << std::endl;

    /*Os laços abaixo percorrem a matriz tridimensional v e escreve as coordenadas dos vértices correspondentes aos voxels visíveis no arquivo OFF.

            Dentro dos loops for, ele verifica se o voxel na posição (x, y, z) está marcado como visível (v[x][y][z].show). Se estiver visível, as coordenadas dos vértices de um cubo são calculadas com base nas coordenadas do voxel.

            As coordenadas dos vértices são escritas no arquivo OFF da seguinte maneira:

            O vértice inferior esquerdo do cubo: (x0, y0, z0)
            O vértice inferior direito do cubo: (x1, y0, z0)
            O vértice superior direito do cubo: (x1, y1, z0)
            O vértice superior esquerdo do cubo: (x0, y1, z0)
            O vértice inferior esquerdo do cubo deslocado no eixo Z: (x0, y0, z1)
            O vértice inferior direito do cubo deslocado no eixo Z: (x1, y0, z1)
            O vértice superior direito do cubo deslocado no eixo Z: (x1, y1, z1)
            O vértice superior esquerdo do cubo deslocado no eixo Z: (x0, y1, z1)*/

            for (int x = 0; x < nx; x++) {
                for (int y = 0; y < ny; y++) {
                    for (int z = 0; z < nz; z++) {
                        if (v[x][y][z].show) {
                            float x0 = x - 0.5;
                            float y0 = y - 0.5;
                            float z0 = z - 0.5;
                            float x1 = x + 0.5;
                            float y1 = y + 0.5;
                            float z1 = z + 0.5;

                            file << x0 << " " << y0 << " " << z0 << std::endl;
                            file << x1 << " " << y0 << " " << z0 << std::endl;
                            file << x1 << " " << y1 << " " << z0 << std::endl;
                            file << x0 << " " << y1 << " " << z0 << std::endl;
                            file << x0 << " " << y0 << " " << z1 << std::endl;
                            file << x1 << " " << y0 << " " << z1 << std::endl;
                            file << x1 << " " << y1 << " " << z1 << std::endl;
                            file << x0 << " " << y1 << " " << z1 << std::endl;
                        }
                    }
                }
            }
            // Escreve as coordenadas dos voxels visíveis
            for (int i = 0; i < nx; i++) {
                for (int j = 0; j < ny; j++) {
                    for (int k = 0; k < nz; k++) {
                        if (v[i][j][k].show) {
                            file << "4 " << i << " " << j << " " << k << " " << fixed << setprecision(1) << r << " " << g << " " << b << " " << a << std::endl;
                        }
                    }
                }
            }
            file.close();
}



















