#include"Neutrino.h"

// Constructors
// Paramterised
Neutrino::Neutrino(double energy, double px, double py, double pz, bool anti, bool interacted):
Lepton(energy, px, py, pz, 0, 0, anti)
{
  has_interacted = interacted;
  if(is_anti){lepton_number = -1;}
  else{lepton_number = 1;}
}

Neutrino::Neutrino(vector<double> momentum_in, bool anti, bool interacted):
Lepton(momentum_in, 0, 0, anti)
{
  has_interacted = interacted;
  if(is_anti){lepton_number = -1;}
  else{lepton_number = 1;}
}
// Copy
Neutrino::Neutrino(Neutrino& neutrino_in):
Lepton(neutrino_in){has_interacted = neutrino_in.has_interacted;}
// Move
Neutrino::Neutrino(Neutrino&& neutrino_in):
Lepton(move(neutrino_in)){has_interacted = neutrino_in.has_interacted;}

// Operator overloads
// Copy
Neutrino& Neutrino::operator=(Neutrino& neutrino_in)
{
  if(&neutrino_in == this){return *this;}
  else
  {
    Lepton::operator=(neutrino_in);
    has_interacted = neutrino_in.has_interacted;
    return *this;
  }
}
// Move
Neutrino& Neutrino::operator=(Neutrino&& neutrino_in)
{
  if(&neutrino_in == this){return *this;}
  else
  {
    Lepton::operator=(move(neutrino_in));
    has_interacted = neutrino_in.has_interacted;
    return *this;
  }
}

// Printer
void Neutrino::print_data()
{
  Lepton::print_data();
  std::cout<<"Interaction status: ";
  if(has_interacted){std::cout<<"Has interacted";}
  else{std::cout<<"Has not interacted";}
  std::cout<<endl<<endl;
}

// Getters
bool Neutrino::get_interacted(){return has_interacted;}

// Setters
void Neutrino::set_interacted(bool interaction){has_interacted = interaction;}