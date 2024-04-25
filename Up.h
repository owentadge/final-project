#ifndef Up_h
#define Up_h
#include"Quark.h"

class Up: public Quark
{
public:
  // Constructors
  Up() = default;
  // Parameterised
  Up(double energy, double px, double py, double pz, bool anti, ColourCharge colour_in);
  Up(vector<double> momentum_in, bool anti, ColourCharge colour_in);
  // Copy
  Up(Up& up_in);
  // Move
  Up(Up&& up_in);

  // Destructor
  ~Up(){}

  // Operator overloads
  // Copy
  Up& operator=(Up& up_in);
  // Move
  Up& operator=(Up&& up_in);

  // Getters
  string get_name();
};

#endif