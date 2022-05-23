#include "square.h"
#include "rectangle.h"

Square::Square(short width,  double rotation) : Rectangle(width,width,rotation,0,0,0)
{
    width = 0;
    rotation = 0;
}
