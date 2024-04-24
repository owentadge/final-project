#include"Strange.h"


// Constructors
// Parameterised
Strange::Strange(double energy, double px, double py, double pz, bool anti, ColourCharge colour_in):
Quark(energy, px, py, pz, 96, -1.0 / 3.0, anti, colour_in){}

Strange::Strange(vector<double> momentum_in, bool anti, ColourCharge colour_in):
Quark(momentum_in, 96, -1.0 / 3.0, anti, colour_in){}
// Copy
Strange::Strange(Strange& strange_in): Quark(strange_in){}
// Move
Strange::Strange(Strange&& strange_in): Quark(move(strange_in)){}

// Operator overloads
// Copy
Strange& Strange::operator=(Strange& strange_in)
{
  if(&strange_in == this){return *this;}
  else
  {
    Quark::operator=(strange_in);
    return *this;
  }
}
// Move
Strange& Strange::operator=(Strange&& strange_in)
{
  if(&strange_in == this){return *this;}
  else
  {
    Quark::operator=(move(strange_in));
    return *this;
  }
}

// Getters
string Strange::get_name()
{
  if(is_anti){return "Anti-strange";}
  else{return "Strange";}
}