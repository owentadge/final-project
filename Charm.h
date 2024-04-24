#ifndef Charm_h
#define Charm_h
#include"Quark.h"

class Charm: public Quark
{
public:
  // Constructors
  Charm() = default;
  // Parameterised
  Charm(double energy, double px, double py, double pz, bool anti, ColourCharge colour_in);
  Charm(vector<double> momentum_in, bool anti, ColourCharge colour_in);
  // Copy
  Charm(Charm& charm_in);
  // Move
  Charm(Charm&& charm_in);

  // Operator overloads
  // Copy
  Charm& operator=(Charm& charm_in);
  // Move
  Charm& operator=(Charm&& charm_in);

  // Getters
  string get_name();
};

#endif