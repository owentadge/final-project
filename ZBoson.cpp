#include"ZBoson.h"

// Constructors
// Parameterised
ZBoson::ZBoson(double energy, double px, double py, double pz, ZDecayType decay_type):
GaugeBoson(energy, px, py, pz, 0, 91190, false){set_decay_products(decay_type);}

ZBoson::ZBoson(vector<double> momentum_in, ZDecayType decay_type):
GaugeBoson(momentum_in, 0, 91190, false){set_decay_products(decay_type);}
// Copy
ZBoson::ZBoson(ZBoson& z_in): GaugeBoson(z_in){decay_products = z_in.decay_products;}
// Move
ZBoson::ZBoson(ZBoson&& z_in): GaugeBoson(move(z_in)){decay_products = move(z_in.decay_products);}

// Operator overloads
// Copy assignment
ZBoson& ZBoson::operator=(ZBoson& z_in)
{
  if(&z_in == this){return *this;}
  else
  {
    Particle::operator=(z_in);
    decay_products = z_in.decay_products;
    return *this;
  }
}
// Move assignment
ZBoson& ZBoson::operator=(ZBoson&& z_in)
{
  if(&z_in == this){return *this;}
  else
  {
    Particle::operator=(z_in);
    decay_products = z_in.decay_products;
    return *this;
  }
}

// Getters
string ZBoson::get_name(){return "Z Boson";}
vector<std::shared_ptr<Particle>> ZBoson::get_decay_products(){return decay_products;}

// Setters
void ZBoson::set_decay_products(ZDecayType decay_type)
{
  switch(decay_type)
  {
    case ZDecayType::ELECTRON:
      decay_products = {std::make_shared<Electron>(Electron()), std::make_shared<Electron>(Electron())};
      break;
    case ZDecayType::MUON:
      decay_products = {std::make_shared<Muon>(Muon()), std::make_shared<Muon>(Muon())};
      break;
    case ZDecayType::TAU:
      decay_products = {std::make_shared<Tau>(Tau()), std::make_shared<Tau>(Tau())};
      break;
    case ZDecayType::ELECTRONNEUTRINO:
      decay_products = {std::make_shared<ElectronNeutrino>(ElectronNeutrino()), std::make_shared<ElectronNeutrino>(ElectronNeutrino())};
      break;
    case ZDecayType::MUONNEUTRINO:
      decay_products = {std::make_shared<ElectronNeutrino>(ElectronNeutrino()), std::make_shared<ElectronNeutrino>(ElectronNeutrino())};
      break;
    case ZDecayType::TAUNEUTRINO:
      decay_products = {std::make_shared<TauNeutrino>(TauNeutrino()), std::make_shared<TauNeutrino>(TauNeutrino())};
      break;                    
    case ZDecayType::UP:
      decay_products = {std::make_shared<Up>(Up()), std::make_shared<Up>(Up())};
      break;
    case ZDecayType::DOWN:
      decay_products = {std::make_shared<Down>(Down()), std::make_shared<Down>(Down())};
      break;
    case ZDecayType::TOP:
      decay_products = {std::make_shared<Top>(Top()), std::make_shared<Top>(Top())};
      break;
    case ZDecayType::BOTTOM:
      decay_products = {std::make_shared<Bottom>(Bottom()), std::make_shared<Bottom>(Bottom())};
      break;
    case ZDecayType::STRANGE:
      decay_products = {std::make_shared<Strange>(Strange()), std::make_shared<Strange>(Strange())};
      break;
    case ZDecayType::CHARM:
      decay_products = {std::make_shared<Charm>(Charm()), std::make_shared<Charm>(Charm())};
      break;
  }
  decay_products.at(0)->set_anti(false);
  decay_products.at(1)->set_anti(true);
}

// Printer
void ZBoson::print_data(bool include_products)
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