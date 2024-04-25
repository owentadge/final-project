#ifndef Lepton_h
#define Lepton_h
#include"Fermion.h"

class Lepton: public Fermion
{
protected:
  int lepton_number;
public:
  // Constructors
  // Default
  Lepton() = default;
  // Parameterised
  Lepton(double energy, double px, double py, double pz, double mass_in, double charge_in, bool anti_in);
  Lepton(vector<double> energy_in, double mass_in, double charge_in, bool anti_in);
  // Copy
  Lepton(Lepton& lepton_in);
  // Move
  Lepton(Lepton&& lepton_in);

  // Destructor
  ~Lepton(){}

  // Operator overloads
  // Copy assignment
  Lepton& operator=(Lepton& lepton_in);
  // Move assignment
  Lepton& operator=(Lepton&& lepton_in);
  // Getters
  int get_lepton_number();
};


#endif