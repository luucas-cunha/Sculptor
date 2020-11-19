#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

Sculptor::Sculptor(int _nx, int _ny, int _nz){
    nx = _nx;
    ny = _ny;
    nz = _nz;

    if(nx <= 0 || ny <= 0 || nz <= 0){
        nx = 0;
        ny = 0;
        nz = 0;
    }

    v = new Voxel**[nz];

    v[0] = new Voxel * [ny * nz];

    v[0][0] = new Voxel[nx * ny * nz];

    for(int i = 1; i < nz; i++){
        v[i] = v[i-1] + ny;
    }

    for(int i = 1; i < (ny * nz); i++){
        v[0][i] = v[0][i-1] + nx;
    }
}

Sculptor::~Sculptor(){
    if(nx == 0 || ny == 0 || nz == 0){
        return;
    }

    delete [] v[0][0];
    delete [] v[0];
    delete [] v;
}

void Sculptor::setColor(float _r, float _g, float _b, float alpha){
    if((_r >= 0.0 && _r <= 1.0) && (_g >= 0.0 && _g <= 1.0) && (_b >= 0.0 && _b <= 1.0) && (alpha >= 0.0 && alpha <= 1.0)){
        r = _r;
        g = _g;
        b = _b;
        a = alpha;
    } else {
        std::cout << "Cores invalidas!" << std::endl;
        exit(1);
    }
}

void Sculptor::putVoxel(int x, int y, int z){
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
        v[x][y][z].isOn = true;
}

void Sculptor::cutVoxel(int x, int y, int z){
        v[x][y][z].isOn = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1){
        for(int i = x0; i < x1; i++){
            for(int j = y0; j < y1; j++){
                for(int k = z0; k < z1; k++){
                    putVoxel(i, j, k);
                }
            }
        }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
        for(int i = x0; i < x1; i++){
            for(int j = y0; j < y1; j++){
                for(int k = z0; k < z1; k++){
                    cutVoxel(i, j, k);
                }
            }
        }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
        // Equacao da esfera: (x - a)^2 + (y - b)^2 + (z - c)^2 = r^2 =>  (x - a)^2 / r^2 + (y - b)^2 / r^2 + (z - c)^2 / r^2 = 1, onde C(a,b,c) eh o centro e r eh o raio da circunferencia

        float aux;

        for(int i = (xcenter - radius); i < (xcenter + radius); i++){
            for(int j = (ycenter - radius); j < (ycenter + radius); j++){
                for(int k = (zcenter - radius); k < (zcenter + radius); k++){
                    aux = ((float) pow((i - xcenter), 2) / ((float) pow(radius, 2))) + (((float) pow((j - ycenter), 2)) / ((float) pow(radius, 2))) + (((float) pow((k-zcenter), 2)) / ((float) pow(radius, 2)));

                    if(aux <= 1.0){
                        putVoxel(i, j, k);
                    }
                }
            }
        }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
        // Equacao da esfera: (x - a)^2 + (y - b)^2 + (z - c)^2 = r^2 =>  (x - a)^2 / r^2 + (y - b)^2 / r^2 + (z - c)^2 / r^2 = 1, onde C(a,b,c) eh o centro e r eh o raio da circunferencia

        float aux;

        for(int i = (xcenter - radius); i < (xcenter + radius); i++){
            for(int j = (ycenter - radius); j < (ycenter + radius); j++){
                for(int k = (zcenter - radius); k < (zcenter + radius); k++){
                    aux = ((float) pow((i - xcenter), 2) / ((float) pow(radius, 2))) + (((float) pow((j - ycenter), 2)) / ((float) pow(radius, 2))) + (((float) pow((k-zcenter), 2)) / ((float) pow(radius, 2)));

                    if(aux <= 1.0){
                        cutVoxel(i, j, k);
                    }
                }
            }
        }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
        //Equacao da elipsoide: [(x - i) / a]^2 + [(y - j) / b]^2 + [(z - k) / c]^2 = 1, onde C(i,j,k) eh o centro e a, b e c tres parametros que definem os eixos maior e menor

        float aux;

        for(int i = (xcenter - rx); i < (xcenter + rx); i++){
            for(int j = (ycenter - ry); j < (ycenter + ry); j++){
                for(int k = (zcenter - rz); k < (zcenter + rz); k++){
                    aux = ((float) pow((i - xcenter), 2) / ((float) pow(rx, 2))) + ((float) pow((j - ycenter), 2) / ((float) pow(ry, 2))) + ((float) pow((k - zcenter), 2) / ((float) pow(rz, 2)));

                    if(aux <= 1.0){
                        putVoxel(i, j, k);
                    }
                }
            }
        }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
        //Equacao da elipsoide: [(x - i) / a]^2 + [(y - j) / b]^2 + [(z - k) / c]^2 = 1, onde C(i,j,k) eh o centro e a, b e c tres parametros que definem os eixos maior e menor

        float aux;

        for(int i = (xcenter - rx); i < (xcenter + rx); i++){
            for(int j = (ycenter - ry); j < (ycenter + ry); j++){
                for(int k = (zcenter - rz); k < (zcenter + rz); k++){
                    aux = ((float) pow((i - xcenter), 2) / ((float) pow(rx, 2))) + ((float) pow((j - ycenter), 2) / ((float) pow(ry, 2))) + ((float) pow((k - zcenter), 2) / ((float) pow(rz, 2)));

                    if(aux <= 1.0){
                        cutVoxel(i, j, k);
                    }
                }
            }
        }
}

void Sculptor::writeOFF(char* filename){
    int Nvoxels = 0;
    int aux = 0;

    std::ofstream fout;

    fout.open(filename);

    if(!fout.is_open()){
        exit(1);
    }

    //Primeira linha do arquivo OFF
    fout << "OFF" << std::endl;

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    Nvoxels++;
                }
            }
        }
    }

    //Segunda linha do arquivo OFF
    fout << 8*Nvoxels << " " << 6*Nvoxels << " " << 0 << std::endl;

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                        fout << i-0.5 << " " << j+0.5 << " " << k-0.5 << std::endl;
                        fout << i-0.5 << " " << j-0.5 << " " << k-0.5 << std::endl;
                        fout << i+0.5 << " " << j-0.5 << " " << k-0.5 << std::endl;
                        fout << i+0.5 << " " << j+0.5 << " " << k-0.5 << std::endl;
                        fout << i-0.5 << " " << j+0.5 << " " << k+0.5 << std::endl;
                        fout << i-0.5 << " " << j-0.5 << " " << k+0.5 << std::endl;
                        fout << i+0.5 << " " << j-0.5 << " " << k+0.5 << std::endl;
                        fout << i+0.5 << " " << j+0.5 << " " << k+0.5 << std::endl;
                }
            }
        }
    }

    for(int i = 0; i < nx; i++){
        for(int j = 0; j < ny; j++){
            for(int k = 0; k < nz; k++){
                if(v[i][j][k].isOn){
                    fout << 4 << " " << aux+0 << " " << aux+3 << " " << aux+2 << " " << aux+1 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << 4 << " " << aux+4 << " " << aux+5 << " " << aux+6 << " " << aux+7 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << 4 << " " << aux+0 << " " << aux+1 << " " << aux+5 << " " << aux+4 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << 4 << " " << aux+0 << " " << aux+4 << " " << aux+7 << " " << aux+3 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << 4 << " " << aux+3 << " " << aux+7 << " " << aux+6 << " " << aux+2 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;
                    fout << 4 << " " << aux+1 << " " << aux+2 << " " << aux+6 << " " << aux+5 << " " << v[i][j][k].r << " " << v[i][j][k].g << " " << v[i][j][k].b << " " << v[i][j][k].a << std::endl;

                    aux = aux + 8;
                }
            }
        }
    }

    if(fout.is_open()){
        std::cout << "Arquivo OFF criado com sucesso!" << std::endl;
    }

    fout.close();
}
