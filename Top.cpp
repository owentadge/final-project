#include"Top.h"


// Constructors
// Parameterised
Top::Top(double energy, double px, double py, double pz, bool anti, ColourCharge colour_in):
Quark(energy, px, py, pz, 173100, 2.0 / 3.0, anti, colour_in){}

Top::Top(vector<double> momentum_in, bool anti, ColourCharge colour_in):
Quark(momentum_in, 173100, 2.0 / 3.0, anti, colour_in){}
// Copy
Top::Top(Top& top_in): Quark(top_in){}
// Move
Top::Top(Top&& top_in): Quark(move(top_in)){}

// Operator overloads
// Copy
Top& Top::operator=(Top& top_in)
{
  if(&top_in == this){return *this;}
  else
  {
    Quark::operator=(top_in);
    return *this;
  }
}
// Move
Top& Top::operator=(Top&& top_in)
{
  if(&top_in == this){return *this;}
  else
  {
    Quark::operator=(move(top_in));
    return *this;
  }
}

// Getters
string Top::get_name()
{
  if(is_anti){return "Anti-top";}
  else{return "Top";}
}