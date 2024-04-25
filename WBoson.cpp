#include"WBoson.h"

// Constructors
// Parameterised
WBoson::WBoson(double energy, double px, double py, double pw, bool anti_in, WDecayType decay_type):
GaugeBoson(energy, px, py, pw, 1, 80360, anti_in)
{
  set_decay_products(decay_type);
  if(is_anti){charge = -1;}
}

WBoson::WBoson(vector<double> momentum_in, bool anti_in, WDecayType decay_type):
GaugeBoson(momentum_in, 1, 80360, anti_in)
{
  set_decay_products(decay_type);
  if(is_anti){charge = -1;}
}
// Copy
WBoson::WBoson(WBoson& w_in): GaugeBoson(w_in){decay_products = w_in.decay_products;}
// Move
WBoson::WBoson(WBoson&& w_in): GaugeBoson(move(w_in)){decay_products = move(w_in.decay_products);}

// Operator overloads
// Copy assignment
WBoson& WBoson::operator=(WBoson& w_in)
{
  if(&w_in == this){return *this;}
  else
  {
    Particle::operator=(w_in);
    decay_products = w_in.decay_products;
    return *this;
  }
}
// Move assignment
WBoson& WBoson::operator=(WBoson&& w_in)
{
  if(&w_in == this){return *this;}
  else
  {
    Particle::operator=(w_in);
    decay_products = w_in.decay_products;
    return *this;
  }
}

// Getters
string WBoson::get_name()
{
  if(is_anti){return "W Anti-boson";}
  else{return "W Boson";}
}
vector<std::shared_ptr<Particle>> WBoson::get_decay_products(){return decay_products;}

// Setters
void WBoson::set_decay_products(WDecayType decay_type)
{
  switch(decay_type)
  {
    case WDecayType::ELECTRON:
      decay_products = {std::make_shared<Electron>(Electron()), std::make_shared<ElectronNeutrino>(ElectronNeutrino())};
      break;
    case WDecayType::MUON:
      decay_products = {std::make_shared<Muon>(Muon()), std::make_shared<MuonNeutrino>(MuonNeutrino())};
      break;
    case WDecayType::TAU:
      decay_products = {std::make_shared<Tau>(Tau()), std::make_shared<TauNeutrino>(TauNeutrino())};
      break;
    case WDecayType::UD:
      decay_products = {std::make_shared<Up>(Up()), std::make_shared<Down>(Down())};
      break;
    case WDecayType::US:
      decay_products = {std::make_shared<Up>(Up()), std::make_shared<Strange>(Strange())};
      break;
    case WDecayType::UB:
      decay_products = {std::make_shared<Up>(Up()), std::make_shared<Bottom>(Bottom())};
      break;
    case WDecayType::CD:
      decay_products = {std::make_shared<Charm>(Charm()), std::make_shared<Down>(Down())};
      break;
    case WDecayType::CS:
      decay_products = {std::make_shared<Charm>(Charm()), std::make_shared<Strange>(Strange())};
      break;
    case WDecayType::CB:
      decay_products = {std::make_shared<Charm>(Charm()), std::make_shared<Bottom>(Bottom())};
      break;
    case WDecayType::TD:
      decay_products = {std::make_shared<Top>(Top()), std::make_shared<Down>(Down())};
      break;
    case WDecayType::TS:
      decay_products = {std::make_shared<Top>(Top()), std::make_shared<Strange>(Strange())};
      break;
    case WDecayType::TB:
      decay_products = {std::make_shared<Top>(Top()), std::make_shared<Bottom>(Bottom())};
      break;
  }
  decay_products.at(0)->set_anti(is_anti);
  decay_products.at(1)->set_anti(!is_anti);
}


// Printer
void WBoson::print_data(bool include_products)
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