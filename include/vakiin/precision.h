#include <float.h>
#include <math.h>

namespace vakiin{

    // Defines a real number precision. By default, a single precision floating point number is used.
    typedef float real;

    // Defines the precision of the square root function. By default, the single precision square root function is used.
    #define real_sqrt sqrtf

    // Define the percision of the power operator.
    #define real_pow powf

    // Defines the precision of the absolute value function. By default, the single precision absolute value function is used.
    #define REAL_MAX FLT_MAX
}