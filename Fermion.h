#ifndef Fermion_h
#define Fermion_h

#include"Particle.h"

class Fermion: public Particle
{
protected:
  static constexpr float spin = 0.5;
public:
  // Constructors
  // Default
  Fermion() = default;
  // Parameterised
  Fermion(double energy, double px, double py, double pz, int mass_in, int charge_in, bool anti_in);
  Fermion(vector<double> energy_in,int mass_in, int charge_in, bool anti_in);
  // Copy
  Fermion(Fermion& fermion_in);
  // Move
  Fermion(Fermion&& fermion_in);
  // Destructor
  ~Fermion(){}
  // Operator overloads
  // Copy assignment
  Fermion& operator=(Fermion& fermion_in);
  // Move assignment
  Fermion& operator=(Fermion&& fermion_in);

  string get_name(){return "f";}
  void print_data(){int i =5;}
};

#endif