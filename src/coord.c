#include "../include/coord.h"

// Initialiser une nouvelle variable de type coord
coord
new_coord(double a, double b, double c)
{
    coord inst;
    inst.x = a;
    inst.y = b;
    inst.z = c;
    return inst;
}