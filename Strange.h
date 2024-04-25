#ifndef Strange_h
#define Strange_h
#include"Quark.h"

class Strange: public Quark
{
public:
  // Constructors
  Strange() = default;
  // Parameterised
  Strange(double energy, double px, double py, double pz, bool anti, ColourCharge colour_in);
  Strange(vector<double> momentum_in, bool anti, ColourCharge colour_in);
  // Copy
  Strange(Strange& strange_in);
  // Move
  Strange(Strange&& strange_in);

  ~Strange(){}

  // Operator overloads
  // Copy
  Strange& operator=(Strange& strange_in);
  // Move
  Strange& operator=(Strange&& strange_in);

  // Getters
  string get_name();
};

#endif