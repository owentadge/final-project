#ifndef Particle_h
#define Particle_h

#include<memory>
#include<utility>
#include"FourMomentum.h"

using std::string;
using std::move;
using std::endl;

class Particle
{
protected:
  std::unique_ptr<FourMomentum> four_momentum;
  double rest_mass;
  double charge;
  bool is_anti;
  double spin;
public:
  // Constructors
  // Default
  Particle() = default;
  // Parameterised
  Particle(double energy, double px, double py, double pz,double spin_in, double mass_in, double charge_in, bool anti_in);
  Particle(vector<double> momentum_in, double spin_in, double mass_in, double charge_in, bool anti_in);
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
  double get_rest_mass();
  bool get_anti();
  double get_charge();
  double get_spin();
  FourMomentum get_four_momentum();
  virtual string get_name() = 0;
  // Setters
  void set_four_momentum(FourMomentum four_momentum_in);
  void set_anti(bool anti_in);
  // Printer function
  virtual void print_data();
};


#endif