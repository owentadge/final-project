#ifndef Electron_h
#define Electron_h
#include"Lepton.h"

class Electron: public Lepton
{
private:
  vector<double> verify_energies(vector<double>);
protected:
  vector<double> energy_layers;
  static constexpr float rest_mass = 0.511;
public:
  // Constructors
  // Default
  Electron() = default;
  // Parameterised
  Electron(double energy, double px, double py, double pz, bool anti_in, vector<double> deposited_energies);
  Electron(vector<double> momentum_in, bool anti_in, vector<double> deposited_energies);
  // Copy
  Electron(Electron& electron_in);
  // Move
  Electron(Electron&& electron_in);

  // Operator overloads
  // Copy assignment
  Electron& operator=(Electron& electron_in);
  // Move assignment
  Electron& operator=(Electron&& electron_in);
  
  // Getters
  vector<double> get_energy_layers();
  string get_name();
  // Setters
  void set_energy_layers(vector<double> energies_in);
  // Printer
  void print_data();

};


#endif