#include"Tau.h"

// Constructors
// Parameterised
Tau::Tau(double energy, double px, double py, double pz, bool anti_in, TauDecayType decay_type):
Lepton(energy, px, py, pz, rest_mass, -1, anti_in)
{
  if(is_anti){charge = 1;}
  set_decay_products(decay_type);
}
Tau::Tau(vector<double> momentum_in, bool anti_in, TauDecayType decay_type):
Lepton(momentum_in, rest_mass, -1, anti_in)
{
  if(is_anti){charge = 1;}
  set_decay_products(decay_type);
}
// Copy
Tau::Tau(Tau& tau_in): Lepton(tau_in){decay_products = tau_in.decay_products;}
// Move
Tau::Tau(Tau&& tau_in): Lepton(move(tau_in)){decay_products = move(tau_in.decay_products);}

// Operator overloads
// Copy assignment
Tau& Tau::operator=(Tau& tau_in)
{
  if(& tau_in == this){return *this;}
  else
  {
    Lepton::operator=(tau_in);
    decay_products = tau_in.decay_products;
    return *this;
  }
}
// Move assignment
Tau& Tau::operator=(Tau&& tau_in)
{
  if(& tau_in == this){return *this;}
  else
  {
    Lepton::operator=(move(tau_in));
    decay_products = move(tau_in.decay_products);
    return *this;
  }
}

// Getters
vector<shared_ptr<Particle>> Tau::get_decay_products(){return decay_products;}

string Tau::get_name()
{
  if(is_anti) return "Anti-tau";
  else return "Tau";
}

// Setters
void Tau::set_decay_products(TauDecayType decay_type)
{
  bool leptonic;
  switch(decay_type)
  {
    case TauDecayType::ELECTRON:
      decay_products = vector<std::shared_ptr<Particle>>{std::make_shared<Electron>(Electron()), 
                                                         std::make_shared<ElectronNeutrino>(ElectronNeutrino()),
                                                         std::make_shared<TauNeutrino>(TauNeutrino())};
      leptonic = true;        
      break;
    case TauDecayType::MUON:
      decay_products = vector<std::shared_ptr<Particle>>{std::make_shared<Muon>(Muon()), 
                                                         std::make_shared<MuonNeutrino>(MuonNeutrino()),
                                                         std::make_shared<TauNeutrino>(TauNeutrino())};
      leptonic = true;        
      break;  
    case TauDecayType::US:
      decay_products = vector<std::shared_ptr<Particle>>{std::make_shared<Up>(Up()), 
                                                         std::make_shared<Strange>(Strange()),
                                                         std::make_shared<TauNeutrino>(TauNeutrino())};
      leptonic = false;        
      break;  
    case TauDecayType::UD:
      decay_products = vector<std::shared_ptr<Particle>>{std::make_shared<Up>(Up()), 
                                                         std::make_shared<Down>(Down()),
                                                         std::make_shared<TauNeutrino>(TauNeutrino())};
      leptonic = false;       
      break;   
    case TauDecayType::CS:
      decay_products = vector<std::shared_ptr<Particle>>{std::make_shared<Charm>(Charm()), 
                                                         std::make_shared<Strange>(Strange()),
                                                         std::make_shared<TauNeutrino>(TauNeutrino())};
      leptonic = false;        
      break;  
    case TauDecayType::CD:
      decay_products = vector<std::shared_ptr<Particle>>{std::make_shared<Charm>(Charm()), 
                                                         std::make_shared<Down>(Down()),
                                                         std::make_shared<TauNeutrino>(TauNeutrino())};
      leptonic = false;        
      break;                                  
  }
  if(leptonic)
  {
    decay_products.at(0)->set_anti(is_anti);
    decay_products.at(1)->set_anti(!is_anti);
    decay_products.at(2)->set_anti(!is_anti);
  }
  else
  {
    decay_products.at(0)->set_anti(!is_anti);
    decay_products.at(1)->set_anti(is_anti);
    decay_products.at(2)->set_anti(!is_anti);
  }
}

// Printer
void Tau::print_data(bool include_products)
{
  Particle::print_data();
  if(include_products)
  {
    std::cout<<"Decays into:\n{\n"<<endl;
    vector<std::shared_ptr<Particle>>::iterator i{};
    for(i = decay_products.begin(); i < decay_products.end(); i++)
    {
      std::cout<<(*i)->get_name()<<endl;
    }
    std::cout<<endl<<"}"<<endl;
  }
}
