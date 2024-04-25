#include"Particle.h"

// Constructors
// Parameterised
Particle::Particle(double energy, double px, double py, double pz, double spin_in, double mass_in, double charge_in, bool anti_in)
{
  rest_mass = mass_in;
  four_momentum = std::make_unique<FourMomentum>(FourMomentum(energy, px, py, pz));
  if(four_momentum->get_invariant_mass() > rest_mass)
  {
    std::cout<<"Invariant mass of four-momentum is greater than particle rest mass!! Assigning default values for given energy..."<<endl;
    double default_momentum = sqrt((pow(energy, 2) - pow(rest_mass, 2)) / 3);
    four_momentum = std::make_unique<FourMomentum>(FourMomentum(energy, default_momentum, default_momentum, default_momentum));
  }
  else if(four_momentum->get_invariant_mass() < rest_mass)
  {
    std::cout<<"Invariant mass is less than particle rest mass!! Assigning default values for energy = mass + 1 MeV..."<<endl;
    double default_momentum = sqrt((pow(rest_mass+1, 2) - pow(rest_mass, 2)) / 3);
    four_momentum = std::make_unique<FourMomentum>(FourMomentum(rest_mass+1, default_momentum, default_momentum, default_momentum));
  }
  charge = charge_in;
  is_anti = anti_in;
  spin = spin_in;
}

Particle::Particle(vector<double> momentum_in, double spin_in, double mass_in, double charge_in, bool anti_in)
{
  rest_mass = mass_in;
  four_momentum = std::make_unique<FourMomentum>(FourMomentum(momentum_in));
  if(four_momentum->get_invariant_mass() > rest_mass)
  {
    std::cout<<"Invariant mass of four-momentum is greater than particle rest mass!! Assigning default values for given energy..."<<endl;
    double default_momentum = sqrt((pow(momentum_in.at(0), 2) - pow(rest_mass, 2)) / 3);
    four_momentum = std::make_unique<FourMomentum>(FourMomentum(momentum_in.at(0), default_momentum, default_momentum, default_momentum));
  }
  else if(four_momentum->get_invariant_mass() < rest_mass)
  {
    std::cout<<"Invariant mass is less than particle rest mass!! Assigning default values for energy = mass + 1 MeV..."<<endl;
    double default_momentum = sqrt((pow(rest_mass+1, 2) - pow(rest_mass, 2)) / 3);
    four_momentum = std::make_unique<FourMomentum>(FourMomentum(rest_mass+1, default_momentum, default_momentum, default_momentum));
  }
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
double Particle::get_rest_mass(){return rest_mass;}
bool Particle::get_anti(){return is_anti;}
double Particle::get_charge(){return charge;}
double Particle::get_spin(){return spin;}
FourMomentum Particle::get_four_momentum(){return *four_momentum;}

// Setters
void Particle::set_four_momentum(FourMomentum four_momentum_in){four_momentum = std::make_unique<FourMomentum>(four_momentum_in);}
void Particle::set_anti(bool anti_in){is_anti = anti_in;}

// Printer
void Particle::print_data()
{
  std::cout<<"Name: "<<get_name()<<endl<<"Mass: "<<rest_mass<<" MeV"<<endl<<"Charge: "<<charge<< " e"<<endl
  <<"Spin: "<<spin<<endl<<"Four-momentum: [";
  for(int i{}; i < 4; i++)
  {
    std::cout<<four_momentum->get_momentum().at(i);
    if(i < 3) std::cout<<" MeV, ";
    else std::cout<<"MeV]"<<endl;
  }  
}