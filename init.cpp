/*
 * dem_symbolic.cpp
 *
 *  Created on: 30 Jan 2014
 *      Author: mrobins
 */

#include <random>
typedef std::mt19937 generator_type;
generator_type generator;

#include "Aboria.h"
using namespace Aboria;

#include <iostream>


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
    
    Label<0,dem_type> a(dem[speciesA]);
        
    p[a] += std::sqrt(2*D[speciesA]*dt)*vector(N,N,N);

    v[a] += sum(b, (id_[a]!=id_[b]) && (norm(dx)<(r_a+r_b)),
                    ((r_a+r_b)/norm(dx)-1)*dx);

    p[a] += v[a];
    
}

