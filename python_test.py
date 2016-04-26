import init

# create a particle
p = init.Particle()


# set the particle position
p.position = [1, 2, 0]

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

init.timestep(particles)
