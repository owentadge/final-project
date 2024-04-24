#ifndef Bottom_h
#define Bottom_h
#include"Quark.h"

class Bottom: public Quark
{
public:
  // Constructors
  Bottom() = default;
  // Parameterised
  Bottom(double energy, double px, double py, double pz, bool anti, ColourCharge colour_in);
  Bottom(vector<double> momentum_in, bool anti, ColourCharge colour_in);
  // Copy
  Bottom(Bottom& bottom_in);
  // Move
  Bottom(Bottom&& bottom_in);

  // Operator overloads
  // Copy
  Bottom& operator=(Bottom& bottom_in);
  // Move
  Bottom& operator=(Bottom&& bottom_in);

  // Getters
  string get_name();
};

#endif