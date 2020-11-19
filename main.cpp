#include "sculptor.h"

int main(){
    Sculptor s(100, 100, 100);

    s.setColor(0.8, 0.0, 0.0, 1.0);
    s.putVoxel(0, 0, 0);
    s.putVoxel(2, 2, 2);
    s.cutVoxel(2, 2, 2);

    s.setColor(0.8, 0.5, 0.3, 1.0);
    s.putBox(20, 30, 20, 30, 20, 30);
    s.cutBox(25, 30, 25, 30, 25, 30);

    s.setColor(0.4, 0.2, 0.8, 1.0);
    s.putSphere(10, 10, 10, 10);
    s.cutSphere(15, 15, 15, 10);

    s.setColor(0.2, 0.8, 0.3, 1.0);
    s.putEllipsoid(40, 40, 40, 15, 10, 5);
    s.cutEllipsoid(45, 45, 45, 10, 8, 5);

    s.writeOFF("C:/Users/Lucas/Documents/Projetos/Sculptor/arquivo.off");

    return 0;
}
