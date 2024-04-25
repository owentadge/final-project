#ifndef WBoson_h
#define WBoson_h
#include"GaugeBoson.h"


class WBoson: public GaugeBoson
{
protected:
  vector<std::shared_ptr<Particle>> decay_products;
public:
  // Constructors
  // Default
  WBoson() = default;
  // Parameterised
  WBoson(double energy, double px, double py, double pz, bool anti_in, WDecayType decay_type);
  WBoson(vector<double> momentum_in, bool anti_in, WDecayType decay_type);
  // Copy
  WBoson(WBoson& w_in);
  // Move
  WBoson(WBoson&& w_in);

  // Destructor
  ~WBoson(){}

  // Operator overloads
  // Copy assignment
  WBoson& operator=(WBoson& w_in);
  // Move assignment
  WBoson& operator=(WBoson&& w_in);

  // Getters
  string get_name();
  vector<std::shared_ptr<Particle>> get_decay_products();

  // Setters
  void set_decay_products(WDecayType decay_type);

  // Printer
  void print_data(bool include_products);
};

#endif