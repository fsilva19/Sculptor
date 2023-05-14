#include "sculptor.h"
#include <iostream>
#include <fstream>
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

    for(int i=0; i<nx; i++){
        for(int j=0; j<ny; j++){
            delete []v[i][j]; //deleta a memória de 3 dimensões
        }
        delete []v[i]; //deleta a memória de 2 dimensões
    }
    delete []v; //deleta a memória de uma dimensão
}
void Sculptor::setColor(float r, float g, float b, float a){
    //Altera os respectivos valores de r, g, b e a na classe Sculptor
    r = r;
    g = g;
    b = b;
    a = a;
}
void putVoxel(int x, int y, int z){
    // A função putVoxel da classe Sculptor é responsável por ativar (ou "colocar") um voxel
    // na posição especificada da matriz 3D. Ela marca o voxel como visível (atributo show definido como true) e define
            // as propriedades de cor (atributos r, g, b) e transparência (atributo a) desse voxel.
    if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
        v[x][y][z].show = true;
    }
}
void putBox(int x0, int x1, int y0, int y1, int z0, int z1){
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
void writeOFF(const char* filename){
    ofstream file;
    file.open(filename);

    // Conta o número total de voxels visíveis

    int totalVertices = 0;
    int totalFaces = 0;

    // Conta o número total de vértices e faces
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
    file << "OFF" << endl;
    file << totalVertices <<" "<< totalFaces <<" 0" << endl;
    cout << "nx: " << nx << " ny: " << ny << " nz: " << nz << endl;

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

                    file << x0 << " " << y0 << " " << z0 << endl;
                    file << x1 << " " << y0 << " " << z0 << endl;
                    file << x1 << " " << y1 << " " << z0 << endl;
                    file << x0 << " " << y1 << " " << z0 << endl;
                    file << x0 << " " << y0 << " " << z1 << endl;
                    file << x1 << " " << y0 << " " << z1 << endl;
                    file << x1 << " " << y1 << " " << z1 << endl;
                    file << x0 << " " << y1 << " " << z1 << endl;
                }
            }
        }
    }
    cout << r << " " << g << " " << b << endl;
    // Escreve as coordenadas dos voxels visíveis
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                if (v[i][j][k].show) {
                    file << i << " " << j << " " << k << " " << r << " " << g << " " << b << endl;
                }
            }
        }

    }

    file.close();
}



















