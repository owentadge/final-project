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
      decay_products = {std::shared_ptr<Electron>(new Electron()), std::shared_ptr<Electron>(new Electron())};
      break;
    case ZDecayType::MUON:
      decay_products = {std::shared_ptr<Muon>(new Muon()), std::shared_ptr<Muon>(new Muon())};
      break;
    case ZDecayType::TAU:
      decay_products = {std::shared_ptr<Tau>(new Tau()), std::shared_ptr<Tau>(new Tau())};
      break;
    case ZDecayType::ELECTRONNEUTRINO:
      decay_products = {std::shared_ptr<ElectronNeutrino>(new ElectronNeutrino()), std::shared_ptr<ElectronNeutrino>(new ElectronNeutrino())};
      break;
    case ZDecayType::MUONNEUTRINO:
      decay_products = {std::shared_ptr<ElectronNeutrino>(new ElectronNeutrino()), std::shared_ptr<ElectronNeutrino>(new ElectronNeutrino())};
      break;
    case ZDecayType::TAUNEUTRINO:
      decay_products = {std::shared_ptr<TauNeutrino>(new TauNeutrino()), std::shared_ptr<TauNeutrino>(new TauNeutrino())};
      break;                    
    case ZDecayType::UP:
      decay_products = {std::shared_ptr<Up>(new Up()), std::shared_ptr<Up>(new Up())};
      break;
    case ZDecayType::DOWN:
      decay_products = {std::shared_ptr<Down>(new Down()), std::shared_ptr<Down>(new Down())};
      break;
    case ZDecayType::TOP:
      decay_products = {std::shared_ptr<Top>(new Top()), std::shared_ptr<Top>(new Top())};
      break;
    case ZDecayType::BOTTOM:
      decay_products = {std::shared_ptr<Bottom>(new Bottom()), std::shared_ptr<Bottom>(new Bottom())};
      break;
    case ZDecayType::STRANGE:
      decay_products = {std::shared_ptr<Strange>(new Strange()), std::shared_ptr<Strange>(new Strange())};
      break;
    case ZDecayType::CHARM:
      decay_products = {std::shared_ptr<Charm>(new Charm()), std::shared_ptr<Charm>(new Charm())};
      break;
    default:
      std::cout<<"No decay type given, defaulting to Bottom"<<endl;
      decay_products = {std::shared_ptr<Bottom>(new Bottom()), std::shared_ptr<Bottom>(new Bottom())};
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