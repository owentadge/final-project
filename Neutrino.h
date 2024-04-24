#ifndef Neutrino_h
#define Neutrino_h
#include"Lepton.h"

class Neutrino: public Lepton
{
protected:
  bool has_interacted;
public:
  // Constructors
  Neutrino() = default;
  // Parameterised
  Neutrino(double energy, double px, double py, double pz, bool anti, bool interacted);
  Neutrino(vector<double> momentum_in, bool anti, bool interacted);
  // Copy
  Neutrino(Neutrino& neutrino_in);
  // Move
  Neutrino(Neutrino&& neutrino_in);

  // Destructor
  ~Neutrino(){}

  // Operator overloads
  // Move
  Neutrino& operator=(Neutrino& neutrino_in);
  // Copy
  Neutrino& operator=(Neutrino&& neutrino_in);

  // Getters
  bool get_interacted();

  // Setters
  void set_interacted(bool interaction);
};
#endif