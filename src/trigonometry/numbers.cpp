#include "../moo.hpp"
#include "../export.h"

double moo::pi() {
    return 3.14159265358979323846;
}

extern "C" {
MOOLIB_API double pi() {
    return moo::pi();
}
}