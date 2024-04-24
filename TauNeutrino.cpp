#include"TauNeutrino.h"

// Constructors
// Paramterised
TauNeutrino::TauNeutrino(double energy, double px, double py, double pz, bool anti, bool interacted):
Neutrino(energy, px, py, pz, anti, interacted){}

TauNeutrino::TauNeutrino(vector<double> momentum_in, bool anti, bool interacted):
Neutrino(momentum_in, anti, interacted){}
// Copy
TauNeutrino::TauNeutrino(TauNeutrino& neutrino_in):
Neutrino(neutrino_in){}
// Move
TauNeutrino::TauNeutrino(TauNeutrino&& neutrino_in):
Neutrino(move(neutrino_in)){}

// Operator overloads
// Copy
TauNeutrino& TauNeutrino::operator=(TauNeutrino& neutrino_in)
{
  if(&neutrino_in == this){return *this;}
  else
  {
    Neutrino::operator=(neutrino_in);
    return *this;
  }
}
// Move
TauNeutrino& TauNeutrino::operator=(TauNeutrino&& neutrino_in)
{
  if(&neutrino_in == this){return *this;}
  else
  {
    Neutrino::operator=(move(neutrino_in));
    return *this;
  }
}



// Getters
string TauNeutrino::get_name()
{
  if(is_anti){return "Tau Anti-neutrino";}
  else{return "Tau Neutrino";}
}