#ifndef Tau_h
#define Tau_h
#include"Lepton.h"
#include"Enumerations.h"
#include"Electron.h"
#include"Muon.h"
#include"ElectronNeutrino.h"
#include"MuonNeutrino.h"
#include"TauNeutrino.h"
#include"Up.h"
#include"Down.h"
#include"Charm.h"
#include"Strange.h"

using std::shared_ptr;

class Tau: public Lepton
{
protected:
  vector<shared_ptr<Particle>> decay_products;
  static constexpr double rest_mass = 1776.8;
public:
  // Constructors
  // Default
  Tau() = default;
  // Parameterised
  Tau(double energy, double px, double py, double pz, bool anti_in, TauDecayType decay_type);
  Tau(vector<double> momentum_in, bool anti_in, TauDecayType decay_type);
  // Copy
  Tau(Tau& tau_in);
  // Move
  Tau(Tau&& tau_in);

  // Destructor
  ~Tau(){}

  // Operator overloads
  // Copy assignment
  Tau& operator=(Tau& tau_in);
  // Move assignment
  Tau& operator=(Tau&& tau_in);
  
  // Getters
  vector<shared_ptr<Particle>> get_decay_products();
  string get_name();
  // Setters
  void set_decay_products(TauDecayType decay_type);

  // Printer
  void print_data();

};


#endif