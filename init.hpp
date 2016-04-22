#include "Aboria.h"
using namespace Aboria;

ABORIA_VARIABLE(scalar, double, "an example scalar")
typedef Particles<scalar> particles_type;
void timestep(particles_type &particles);
