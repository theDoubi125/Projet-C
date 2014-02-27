#include "vec.h"

Vec add(Vec A, Vec B)
{
    Vec v;
    v.x = A.x+B.x;
    v.y = A.y+B.y;
    return v;
}
