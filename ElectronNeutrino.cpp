#include"ElectronNeutrino.h"

// Constructors
// Paramterised
ElectronNeutrino::ElectronNeutrino(double energy, double px, double py, double pz, bool anti, bool interacted):
Neutrino(energy, px, py, pz, anti, interacted){}

ElectronNeutrino::ElectronNeutrino(vector<double> momentum_in, bool anti, bool interacted):
Neutrino(momentum_in, anti, interacted){}
// Copy
ElectronNeutrino::ElectronNeutrino(ElectronNeutrino& neutrino_in):
Neutrino(neutrino_in){}
// Move
ElectronNeutrino::ElectronNeutrino(ElectronNeutrino&& neutrino_in):
Neutrino(move(neutrino_in)){}

// Operator overloads
// Copy
ElectronNeutrino& ElectronNeutrino::operator=(ElectronNeutrino& neutrino_in)
{
  if(&neutrino_in == this){return *this;}
  else
  {
    Neutrino::operator=(neutrino_in);
    return *this;
  }
}
// Move
ElectronNeutrino& ElectronNeutrino::operator=(ElectronNeutrino&& neutrino_in)
{
  if(&neutrino_in == this){return *this;}
  else
  {
    Neutrino::operator=(move(neutrino_in));
    return *this;
  }
}



// Getters
string ElectronNeutrino::get_name()
{
  if(is_anti){return "Electron Anti-neutrino";}
  else{return "Electron Neutrino";}
}