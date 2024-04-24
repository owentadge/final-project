#ifndef Tau_h
#define Tau_h
#include"Lepton.h"

using std::shared_ptr;

class Tau: public Lepton
{
private:
  vector<shared_ptr<Particle>> verify_products(vector<shared_ptr<Particle>>);
protected:
  vector<shared_ptr<Particle>> decay_products;
  static constexpr double rest_mass = 1776.8;
public:
  // Constructors
  // Default
  Tau() = default;
  // Parameterised
  Tau(double energy, double px, double py, double pz, bool anti_in, vector<shared_ptr<Particle>> decay_in);
  Tau(vector<double> momentum_in, bool anti_in, vector<shared_ptr<Particle>> decay_in);
  // Copy
  Tau(Tau& tau_in);
  // Move
  Tau(Tau&& tau_in);

  // Operator overloads
  // Copy assignment
  Tau& operator=(Tau& tau_in);
  // Move assignment
  Tau& operator=(Tau&& tau_in);
  
  // Getters
  vector<shared_ptr<Particle>> get_decay_products();
  string get_name();
  // Setters

  // Printer
  void print_data(bool include_products);

};


#endif