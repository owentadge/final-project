#ifndef Higgs_h
#define Higgs_h
#include"Particle.h"
#include"Enumerations.h"
#include"ZBoson.h"
#include"WBoson.h"
#include"Photon.h"
#include"Bottom.h"

class Higgs: public Particle
{
protected:

  vector<std::shared_ptr<Particle>> decay_products;
public:
  // Constructors
  // Default
  Higgs() = default;
  // Parameterised
  Higgs(double energy, double px, double py, double pz, HiggsDecayType decay_type);
  Higgs(vector<double> momentum_in, HiggsDecayType decay_type);
  // Copy
  Higgs(Higgs& higgs_in);
  // Move
  Higgs(Higgs&& higgs_in);

  // Destructor
  ~Higgs(){}

  // Operator overloads
  // Copy assignment
  Higgs& operator=(Higgs& higgs_in);
  // Move assignment
  Higgs& operator=(Higgs&& higgs_in);

  // Getters
  string get_name();
  vector<std::shared_ptr<Particle>> get_decay_products();

  // Setters
  void set_decay_products(HiggsDecayType decay_type);

  // Printer
  void print_data(bool include_products);
};

#endif