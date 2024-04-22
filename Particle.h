#ifndef Particle_h
#define Particle_h

#include<memory>
#include"FourMomentum.h"

using std::string;
using std::move;

class Particle
{
protected:
  std::unique_ptr<FourMomentum> four_momentum;
  int rest_mass;
  int charge;
  bool is_anti;
  float spin;
public:
  // Constructors
  // Default
  Particle() = default;
  // Parameterised
  Particle(double energy, double px, double py, double pz,float spin_in, int mass_in, int charge_in, bool anti_in);
  Particle(vector<double> momentum_in, float spin_in, int mass_in, int charge_in, bool anti_in);
  // Copy
  Particle(Particle& particle_in);
  // Move
  Particle(Particle&& particle_in);
  // Destructor
  ~Particle(){}
  // Operator overloads
  // Copy assignment
  Particle& operator=(Particle& particle_in);
  // Move assignment
  Particle& operator=(Particle&& particle_in);
  // Getters
  int get_rest_mass();
  bool get_anti();
  int get_charge();
  float get_spin();
  FourMomentum get_four_momentum();
  virtual string get_name() = 0;
  // Setters
  void set_four_momentum(FourMomentum four_momentum_in);
  // Printer function
  virtual void print_data() = 0;
};


#endif