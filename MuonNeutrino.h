#ifndef MuonNeutrino_h
#define MuonNeutrino_h
#include"Neutrino.h"

class MuonNeutrino: public Neutrino
{
public:
  // Constructors
  MuonNeutrino() = default;
  // Parameterised
  MuonNeutrino(double energy, double px, double py, double pz, bool anti, bool interacted);
  MuonNeutrino(vector<double> momentum_in, bool anti, bool interacted);
  // Copy
  MuonNeutrino(MuonNeutrino& neutrino_in);
  // Move
  MuonNeutrino(MuonNeutrino&& neutrino_in);

  // Destructor
  ~MuonNeutrino(){}

  // Operator overloads
  // Move
  MuonNeutrino& operator=(MuonNeutrino& neutrino_in);
  // Copy
  MuonNeutrino& operator=(MuonNeutrino&& neutrino_in);

  // Printer
  //void print_data();

  // Getters
  string get_name();
};
#endif