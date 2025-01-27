#include"Fermion.h"

// Constructors
// Parameterised
Fermion::Fermion(double energy, double px, double py, double pz, double mass_in, double charge_in, bool anti_in):
Particle(energy, px, py, pz, 0.5, mass_in, charge_in, anti_in){}

Fermion::Fermion(vector<double> energy_in, double mass_in, double charge_in, bool anti_in):
Particle(energy_in, 0.5, mass_in, charge_in, anti_in){}
// Copy
Fermion::Fermion(Fermion& fermion_in): Particle(fermion_in){}
// Move
Fermion::Fermion(Fermion&& fermion_in): Particle(move(fermion_in)){}

// Operator overloads
// Copy assignment
Fermion& Fermion::operator=(Fermion& fermion_in)
{
  if (&fermion_in == this){return *this;}
  else
  {
    Particle::operator=(fermion_in);
    return *this;
  }
}
// Move assignment
Fermion& Fermion::operator=(Fermion&& fermion_in)
{
  if (&fermion_in == this){return *this;}
  else
  {
    Particle::operator=(move(fermion_in));
    return *this;
  }
}