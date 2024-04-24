#include"Up.h"


// Constructors
// Parameterised
Up::Up(double energy, double px, double py, double pz, bool anti, ColourCharge colour_in):
Quark(energy, px, py, pz, 2.2, 2.0 / 3.0, anti, colour_in){}

Up::Up(vector<double> momentum_in, bool anti, ColourCharge colour_in):
Quark(momentum_in, 2.2, 2.0 / 3.0, anti, colour_in){}
// Copy
Up::Up(Up& up_in): Quark(up_in){}
// Move
Up::Up(Up&& up_in): Quark(move(up_in)){}

// Operator overloads
// Copy
Up& Up::operator=(Up& up_in)
{
  if(&up_in == this){return *this;}
  else
  {
    Quark::operator=(up_in);
    return *this;
  }
}
// Move
Up& Up::operator=(Up&& up_in)
{
  if(&up_in == this){return *this;}
  else
  {
    Quark::operator=(move(up_in));
    return *this;
  }
}

// Getters
string Up::get_name()
{
  if(is_anti){return "Anti-up";}
  else{return "Up";}
}