# aboria_init
example of Aboria wrapped to Python

creates an Aboria particle container (particle_type), and wraps this so it can be used from python.

First compile the library using CMake:

```bash
$ cd path/to/repo/
$ mkdir build
$ cd build
$ cmake ..
$ make 
```

Then you can import the module into python and start using it

```python
import init
# create a particle
p = init.Particle()
# get help on the particle class
help(p)
# set the particle position
p.position = [1, 2, 3]
# create a set of particles
particles = init.Particles()
# add your particle to the set of particles
particles.append(p)
# setup neighbourhood searching
minbox = [0.0, 0.0 ,0.0]
maxbox = [4.0, 4.0 ,0.0]
L = 1.0
periodic = [True, True, False]
particles.init_neighbour_search(minbox,maxbox,L,periodic)
```

I've wrapped a function `timestep` which takes a single arguement which is the particles container, so in python you would use it like

```python
init.timestep(particles)
```

The c++ code for this function is in `init.cpp`. You can modify this to change what timestep does. See the help at <http://martinjrobins.github.io/Aboria/> for more details on using Aboria from C++
