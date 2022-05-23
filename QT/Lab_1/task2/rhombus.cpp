#include "rhombus.h"
#include "square.h"

Rhombus::Rhombus(short width, double rotation) : Square (width, rotation) {
    width = 0;
    rotation = 45;
}
