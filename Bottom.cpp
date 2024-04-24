#include"Bottom.h"


// Constructors
// Parameterised
Bottom::Bottom(double energy, double px, double py, double pz, bool anti, ColourCharge colour_in):
Quark(energy, px, py, pz, 4180, -1.0 / 3.0, anti, colour_in){}

Bottom::Bottom(vector<double> momentum_in, bool anti, ColourCharge colour_in):
Quark(momentum_in, 4180, -1.0 / 3.0, anti, colour_in){}
// Copy
Bottom::Bottom(Bottom& bottom_in): Quark(bottom_in){}
// Move
Bottom::Bottom(Bottom&& bottom_in): Quark(move(bottom_in)){}

// Operator overloads
// Copy
Bottom& Bottom::operator=(Bottom& bottom_in)
{
  if(&bottom_in == this){return *this;}
  else
  {
    Quark::operator=(bottom_in);
    return *this;
  }
}
// Move
Bottom& Bottom::operator=(Bottom&& bottom_in)
{
  if(&bottom_in == this){return *this;}
  else
  {
    Quark::operator=(move(bottom_in));
    return *this;
  }
}

// Getters
string Bottom::get_name()
{
  if(is_anti){return "Anti-bottom";}
  else{return "Bottom";}
}