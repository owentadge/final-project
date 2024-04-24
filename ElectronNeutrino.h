#ifndef ElectronNeutrino_h
#define ElectronNeutrino_h
#include"Neutrino.h"

class ElectronNeutrino: public Neutrino
{
public:
  // Constructors
  ElectronNeutrino() = default;
  // Parameterised
  ElectronNeutrino(double energy, double px, double py, double pz, bool anti, bool interacted);
  ElectronNeutrino(vector<double> momentum_in, bool anti, bool interacted);
  // Copy
  ElectronNeutrino(ElectronNeutrino& neutrino_in);
  // Move
  ElectronNeutrino(ElectronNeutrino&& neutrino_in);

  // Destructor
  ~ElectronNeutrino(){}

  // Operator overloads
  // Move
  ElectronNeutrino& operator=(ElectronNeutrino& neutrino_in);
  // Copy
  ElectronNeutrino& operator=(ElectronNeutrino&& neutrino_in);

  // Printer
  //void print_data();

  // Getters
  string get_name();
};
#endif