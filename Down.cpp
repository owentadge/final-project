#include"Down.h"


// Constructors
// Parameterised
Down::Down(double energy, double px, double py, double pz, bool anti, ColourCharge colour_in):
Quark(energy, px, py, pz, 4.7, -1.0 / 3.0, anti, colour_in){}

Down::Down(vector<double> momentum_in, bool anti, ColourCharge colour_in):
Quark(momentum_in, 4.7, -1.0 / 3.0, anti, colour_in){}
// Copy
Down::Down(Down& down_in): Quark(down_in){}
// Move
Down::Down(Down&& down_in): Quark(move(down_in)){}

// Operator overloads
// Copy
Down& Down::operator=(Down& down_in)
{
  if(&down_in == this){return *this;}
  else
  {
    Quark::operator=(down_in);
    return *this;
  }
}
// Move
Down& Down::operator=(Down&& down_in)
{
  if(&down_in == this){return *this;}
  else
  {
    Quark::operator=(move(down_in));
    return *this;
  }
}

// Getters
string Down::get_name()
{
  if(is_anti){return "Anti-down";}
  else{return "Down";}
}