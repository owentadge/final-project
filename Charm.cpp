#include"Charm.h"


// Constructors
// Parameterised
Charm::Charm(double energy, double px, double py, double pz, bool anti, ColourCharge colour_in):
Quark(energy, px, py, pz, 1280, 2.0 / 3.0, anti, colour_in){}

Charm::Charm(vector<double> momentum_in, bool anti, ColourCharge colour_in):
Quark(momentum_in, 1280, 2.0 / 3.0, anti, colour_in){}
// Copy
Charm::Charm(Charm& charm_in): Quark(charm_in){}
// Move
Charm::Charm(Charm&& charm_in): Quark(move(charm_in)){}

// Operator overloads
// Copy
Charm& Charm::operator=(Charm& charm_in)
{
  if(&charm_in == this){return *this;}
  else
  {
    Quark::operator=(charm_in);
    return *this;
  }
}
// Move
Charm& Charm::operator=(Charm&& charm_in)
{
  if(&charm_in == this){return *this;}
  else
  {
    Quark::operator=(move(charm_in));
    return *this;
  }
}

// Getters
string Charm::get_name()
{
  if(is_anti){return "Anti-charm";}
  else{return "Charm";}
}