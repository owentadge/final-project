#ifndef Down_h
#define Down_h
#include"Quark.h"

class Down: public Quark
{
public:
  // Constructors
  Down() = default;
  // Parameterised
  Down(double energy, double px, double py, double pz, bool anti, ColourCharge colour_in);
  Down(vector<double> momentum_in, bool anti, ColourCharge colour_in);
  // Copy
  Down(Down& down_in);
  // Move
  Down(Down&& down_in);

  // Destructor
  ~Down(){}

  // Operator overloads
  // Copy
  Down& operator=(Down& down_in);
  // Move
  Down& operator=(Down&& down_in);

  // Getters
  string get_name();
};

#endif