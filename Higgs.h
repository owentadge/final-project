#ifndef HiggsBoson_h
#define HiggsBoson_h
#include"Particle.h"
#include"Enumerations.h"

class HiggsBoson: public Particle
{
protected:

  vector<std::shared_ptr<Particle>> decay_products;
public:
  // Constructors
  // Default
  HiggsBoson() = default;
  // Parameterised
  HiggsBoson(double energy, double px, double py, double pz);
  HiggsBoson(vector<double> momentum_in);
  // Copy
  HiggsBoson(HiggsBoson& higgs_in);
  // Move
  HiggsBoson(HiggsBoson&& higgs_in);

  // Operator overloads
  // Copy assignment
  HiggsBoson& operator=(HiggsBoson& higgs_in);
  // Move assignment
  HiggsBoson& operator=(HiggsBoson&& higgs_in);

  // Getters
  string get_name();
  vector<std::shared_ptr<Particle>> get_decay_products();

  // Setters
  void set_decay_products(vector<std::shared_ptr<Particle>>);

  // Printer
  void print_data(bool include_products);
};

#endif