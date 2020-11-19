#ifndef SCULPTOR_H
#define SCULPTOR_H

#include "voxel.h"

/**
 * @brief A classe Sculptor serve para gerar esculturas
 * tridimensionais através do uso de voxels.
 */
class Sculptor {
protected:
    /**
     * @brief v é a matriz tridimensional de voxels
     */
    Voxel ***v;
    /**
     * @brief nx é a dimensão da matriz no eixo X
     */
    int nx;
    /**
     * @brief ny é a dimensão da matriz no eixo Y
     */
    int ny;
    /**
     * @brief nz é a dimensão da matriz no eixo Z
     */
    int nz;
    /**
     * @brief r é a dosagem de cor vermelha presente no voxel
     */
    float r;
    /**
     * @brief g é a dosagem de cor verde presente no voxel
     */
    float g;
    /**
     * @brief b é a dosagem de cor azul presente no voxel
     */
    float b;
    /**
     * @brief a é a transparência presente no voxel
     */
    float a;
public:
    /**
     * @brief Sculptor é o construtor da classe.
     * @param _nx é a dimensão no eixo X
     * @param _ny é a dimensão no eixo Y
     * @param _nz é a dimensão no eixo Z
     */
    Sculptor(int _nx, int _ny, int _nz);
    /**
     * @brief ~Sculptor é o destrutor da classe.
     */
    ~Sculptor();
    /**
     * @brief setColor define a cor atual de desenho (r, g, b, a).
     * @param _r é a dosagem de cor vermelha
     * @param _g é a dosagem de cor verde
     * @param _b é a dosagem de cor azul
     * @param alpha é a transparência
     */
    void setColor(float _r, float _g, float _b, float alpha);
    /**
     * @brief putVoxel ativa o voxel na posição (x, y, z) (fazendo isOn = true)
     * e atribui ao mesmo a cor atual de desenho (r, g, b, a).
     * @param x é a posição do voxel no eixo X
     * @param y é a posição do voxel no eixo Y
     * @param z é a posição do voxel no eixo Z
     */
    void putVoxel(int x, int y, int z);
    /**
     * @brief cutVoxel desativa o voxel na posição (x, y, z) (fazendo isOn = false).
     * @param x é a posição do voxel no eixo X
     * @param y é a posição do voxel no eixo Y
     * @param z é a posição do voxel no eixo Z
     */
    void cutVoxel(int x, int y, int z);
    /**
     * @brief putBox ativa todos os voxels no intervalo x∈ [x0, x1], y∈ [y0, y1], z∈ [z0, z1]
     * e atribui aos mesmos a cor atual de desenho.
     * @param x0 é o início da dimensão da caixa de voxels no eixo X
     * @param x1 é o fim da dimensão da caixa de voxels no eixo X
     * @param y0 é o início da dimensão da caixa de voxels no eixo Y
     * @param y1 é o fim da dimensão da caixa de voxels no eixo Y
     * @param z0 é o início da dimensão da caixa de voxels no eixo Z
     * @param z1 é o fim da dimensão da caixa de voxels no eixo Z
     */
    void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * @brief cutBox desativa todos os voxels no intervalo x∈ [x0, x1], y∈ [y0, y1], z∈ [z0, z1].
     * @param x0 é o início da dimensão da caixa de voxels no eixo X
     * @param x1 é o fim da dimensão da caixa de voxels no eixo X
     * @param y0 é o início da dimensão da caixa de voxels no eixo Y
     * @param y1 é o fim da dimensão da caixa de voxels no eixo Y
     * @param z0 é o início da dimensão da caixa de voxels no eixo Z
     * @param z1 é o fim da dimensão da caixa de voxels no eixo Z
     */
    void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
    /**
     * @brief putSphere ativa todos os voxels que satisfazem à equação da esfera
     * e atribui aos mesmos a cor atual de desenho (r, g, b, a).
     * @param xcenter é a posição do centro da esfera de voxels no eixo X
     * @param ycenter é a posição do centro da esfera de voxels no eixo Y
     * @param zcenter é a posição do centro da esfera de voxels no eixo Z
     * @param radius é o raio da esfera de voxels
     */
    void putSphere(int xcenter, int ycenter, int zcenter, int radius);
    /**
     * @brief cutSphere desativa todos os voxels que satisfazem à equação da esfera.
     * @param xcenter é a posição do centro da esfera de voxels no eixo X
     * @param ycenter é a posição do centro da esfera de voxels no eixo Y
     * @param zcenter é a posição do centro da esfera de voxels no eixo Z
     * @param radius é o raio da esfera de voxels
     */
    void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
    /**
     * @brief putEllipsoid ativa todos os voxels que satisfazem à equação da elipsóide
     * e atribui aos mesmos a cor atual de desenho (r, g, b, a).
     * @param xcenter é a posição do centro da elipsóide de voxels no eixo X
     * @param ycenter é a posição do centro da elipsóide de voxels no eixo Y
     * @param zcenter é a posição do centro da elipsóide de voxels no eixo Z
     * @param rx é o raio da elipsóide de voxels no eixo X
     * @param ry é o raio da elipsóide de voxels no eixo Y
     * @param rz é o raio da elipsóide de voxels no eixo Z
     */
    void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief cutEllipsoid desativa todos os voxels que satisfazem à equação da elipsóide.
     * @param xcenter é a posição do centro da elipsóide de voxels no eixo X
     * @param ycenter é a posição do centro da elipsóide de voxels no eixo Y
     * @param zcenter é a posição do centro da elipsóide de voxels no eixo Z
     * @param rx é o raio da elipsóide de voxels no eixo X
     * @param ry é o raio da elipsóide de voxels no eixo Y
     * @param rz é o raio da elipsóide de voxels no eixo Z
     */
    void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
    /**
     * @brief writeOFF grava a escultura em um arquivo no formato .off.
     * @param filename é o nome do arquivo .off que será criado
     */
    void writeOFF(char* filename);
};

#endif // SCULPTOR_H
