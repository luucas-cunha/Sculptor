#ifndef VOXEL_H
#define VOXEL_H

/**
 * @brief A estrutura Voxel comporta as propriedades necessárias
 * para exibir cubos com cor e transparência.
 */
struct Voxel {
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
    /**
     * @brief isOn define se o voxel deverá ser incluído ou não
     * no modelo digital que representará a escultura
     */
    bool isOn;
};

#endif // VOXEL_H
