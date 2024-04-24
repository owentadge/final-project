#ifndef TauNeutrino_h
#define TauNeutrino_h
#include"Neutrino.h"

class TauNeutrino: public Neutrino
{
public:
  // Constructors
  TauNeutrino() = default;
  // Parameterised
  TauNeutrino(double energy, double px, double py, double pz, bool anti, bool interacted);
  TauNeutrino(vector<double> momentum_in, bool anti, bool interacted);
  // Copy
  TauNeutrino(TauNeutrino& neutrino_in);
  // Move
  TauNeutrino(TauNeutrino&& neutrino_in);

  // Destructor
  ~TauNeutrino(){}

  // Operator overloads
  // Move
  TauNeutrino& operator=(TauNeutrino& neutrino_in);
  // Copy
  TauNeutrino& operator=(TauNeutrino&& neutrino_in);

  // Printer
  //void print_data();

  // Getters
  string get_name();
};
#endif