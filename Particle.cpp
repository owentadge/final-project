#include"Particle.h"

// Constructors
// Parameterised
Particle::Particle(double energy, double px, double py, double pz, float spin_in, int mass_in, int charge_in, bool anti_in)
{
  four_momentum = std::make_unique<FourMomentum>(FourMomentum(energy, px, py, pz));
  rest_mass = mass_in;
  charge = charge_in;
  is_anti = anti_in;
  spin = spin_in;
}

Particle::Particle(vector<double> momentum_in, float spin_in, int mass_in, int charge_in, bool anti_in)
{
  four_momentum = std::make_unique<FourMomentum>(FourMomentum(momentum_in));
  rest_mass = mass_in;
  charge = charge_in;
  is_anti = anti_in;
  spin = spin_in;
}
// Copy
Particle::Particle(Particle& particle_in)
{
  four_momentum = std::make_unique<FourMomentum>(FourMomentum(*particle_in.four_momentum));
  rest_mass = particle_in.rest_mass;
  charge = particle_in.charge;
  is_anti = particle_in.is_anti;
  spin = particle_in.spin;
}
// Move
Particle::Particle(Particle&& particle_in)
{
  four_momentum = move(particle_in.four_momentum);
  rest_mass = particle_in.rest_mass;
  particle_in.rest_mass = 0;
  charge = particle_in.charge;
  particle_in.charge = 0;
  spin = particle_in.spin;
  particle_in.spin = 0;
  is_anti = particle_in.is_anti;
}

// Operator overloads
// Copy assignment
Particle& Particle::operator=(Particle& particle_in)
{
  if(&particle_in == this){return *this;}
  else
  {
    four_momentum = std::make_unique<FourMomentum>(FourMomentum(*particle_in.four_momentum));
    rest_mass = particle_in.rest_mass;
    charge = particle_in.charge;
    is_anti = particle_in.is_anti;
    spin = particle_in.spin;
    return *this;
  }
}
// Move assignment
Particle& Particle::operator=(Particle&& particle_in)
{
  if(&particle_in == this){return *this;}
  else
  {
    four_momentum = move(particle_in.four_momentum);
    rest_mass = particle_in.rest_mass;
    particle_in.rest_mass = 0;
    charge = particle_in.charge;
    particle_in.charge = 0;
    spin = particle_in.spin;
    particle_in.spin = 0;
    is_anti = particle_in.is_anti;
    return *this;
  }
}

// Getters
int Particle::get_rest_mass(){return rest_mass;}
bool Particle::get_anti(){return is_anti;}
int Particle::get_charge(){return charge;}