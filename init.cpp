
//#include <random>
//typedef std::mt19937 generator_type;
//generator_type generator;

#include "Aboria.h"
using namespace Aboria;

#include <iostream>
#include "init.hpp"


void timestep(particles_type &particles) {

    /*
     * create symbolic objects
     */
    Symbol<position> p;
    Symbol<id> id_;
    Symbol<alive> alive_;

    Dx dx;
    Accumulate<std::plus<Vect3d> > sum;
    VectorSymbolic<double> vector;
    Normal N;

    const double D = 1.0;
    const double dt = 0.1;
    const double r_a = 1.0;
    const double r_b = 1.0;
    
    Label<0,particles_type> a(particles);
    Label<0,particles_type> b(particles);
        
    p[a] += std::sqrt(2*D*dt)*vector(N,N,N);

    p[a] = sum(b, (id_[a]!=id_[b]) && (norm(dx)<(r_a+r_b)),
                    ((r_a+r_b)/norm(dx)-1)*dx);
    
}

