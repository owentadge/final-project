#ifndef ZBoson_h
#define ZBoson_h
#include"GaugeBoson.h"


class ZBoson: public GaugeBoson
{
protected:
  vector<std::shared_ptr<Particle>> decay_products;
public:
  // Constructors
  // Default
  ZBoson() = default;
  // Parameterised
  ZBoson(double energy, double px, double py, double pz, ZDecayType decay_type);
  ZBoson(vector<double> momentum_in, ZDecayType decay_type);
  // Copy
  ZBoson(ZBoson& z_in);
  // Move
  ZBoson(ZBoson&& z_in);

  // Destructor
  ~ZBoson(){}

  // Operator overloads
  // Copy assignment
  ZBoson& operator=(ZBoson& z_in);
  // Move assignment
  ZBoson& operator=(ZBoson&& z_in);

  // Getters
  string get_name();
  vector<std::shared_ptr<Particle>> get_decay_products();

  // Setters
  void set_decay_products(ZDecayType decay_type);

  // Printer
  void print_data(bool include_products);
};

#endif