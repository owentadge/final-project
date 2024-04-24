#include"MuonNeutrino.h"

// Constructors
// Paramterised
MuonNeutrino::MuonNeutrino(double energy, double px, double py, double pz, bool anti, bool interacted):
Neutrino(energy, px, py, pz, anti, interacted){}

MuonNeutrino::MuonNeutrino(vector<double> momentum_in, bool anti, bool interacted):
Neutrino(momentum_in, anti, interacted){}
// Copy
MuonNeutrino::MuonNeutrino(MuonNeutrino& neutrino_in):
Neutrino(neutrino_in){}
// Move
MuonNeutrino::MuonNeutrino(MuonNeutrino&& neutrino_in):
Neutrino(move(neutrino_in)){}

// Operator overloads
// Copy
MuonNeutrino& MuonNeutrino::operator=(MuonNeutrino& neutrino_in)
{
  if(&neutrino_in == this){return *this;}
  else
  {
    Neutrino::operator=(neutrino_in);
    return *this;
  }
}
// Move
MuonNeutrino& MuonNeutrino::operator=(MuonNeutrino&& neutrino_in)
{
  if(&neutrino_in == this){return *this;}
  else
  {
    Neutrino::operator=(move(neutrino_in));
    return *this;
  }
}



// Getters
string MuonNeutrino::get_name()
{
  if(is_anti){return "Muon Anti-neutrino";}
  else{return "Muon Neutrino";}
}