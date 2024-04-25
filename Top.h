#ifndef Top_h
#define Top_h
#include"Quark.h"

class Top: public Quark
{
public:
  // Constructors
  Top() = default;
  // Parameterised
  Top(double energy, double px, double py, double pz, bool anti, ColourCharge colour_in);
  Top(vector<double> momentum_in, bool anti, ColourCharge colour_in);
  // Copy
  Top(Top& top_in);
  // Move
  Top(Top&& top_in);

  // Destructor
  ~Top(){}

  // Operator overloads
  // Copy
  Top& operator=(Top& top_in);
  // Move
  Top& operator=(Top&& top_in);

  // Getters
  string get_name();
};

#endif