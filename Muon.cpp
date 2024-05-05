#include"Muon.h"

// Constructors
// Paramterised
Muon::Muon(double energy, double px, double py, double pz, bool anti, bool isolated):
Lepton(energy, px, py, pz, 105.66, -1, anti)
{
  if(is_anti){charge = 1;}
  is_isolated = isolated;
}
Muon::Muon(vector<double> momentum_in, bool anti, bool isolated):
Lepton(momentum_in, 105.66, -1, anti)
{
  if(is_anti){charge = 1;}
  is_isolated = isolated;
}
// Copy
Muon::Muon(Muon& muon_in): Lepton(muon_in){is_isolated = muon_in.is_isolated;}
// Move
Muon::Muon(Muon&& muon_in): Lepton(move(muon_in)){is_isolated = muon_in.is_isolated;}

// Operator overloads
// Copy
Muon& Muon::operator=(Muon& muon_in)
{
  if(& muon_in == this){return *this;}
  else
  {
    Lepton::operator=(muon_in);
    is_isolated = muon_in.is_isolated;
    return *this;
  }
}
// Move
Muon& Muon::operator=(Muon&& muon_in)
{
  if(& muon_in == this){return *this;}
  else
  {
    Lepton::operator=(move(muon_in));
    is_isolated = muon_in.is_isolated;
    return *this;
  }
}

// Printer
void Muon::print_data()
{
  Lepton::print_data();
  std::cout<<"Isolation status: ";
  if(is_isolated){std::cout<<"Isolated"<<endl<<endl;}
  else{std::cout<<"Not isolated"<<endl<<endl;}
}

// Getters
bool Muon::get_isolation(){return is_isolated;}
string Muon::get_name()
{
  if(is_anti) return "Anti-muon";
  else return "Muon";
}

// Setters
void Muon::set_isolated(bool isolation){is_isolated = isolation;}