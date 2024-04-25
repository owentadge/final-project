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
  vector<double> dummy_four_momentum{10,1,2,3};
  switch(decay_type)
  {
    case ELECTRON:
      decay_products = {std::make_shared<Electron>(Electron(dummy_four_momentum,false,{10,1,2,3})),
                        std::make_shared<Electron>(Electron(dummy_four_momentum,true,{10,1,2,3}))};
      break;
    case MUON:
      decay_products = {std::make_shared<Muon>(Muon(dummy_four_momentum,false,false)),
                        std::make_shared<Muon>(Muon(dummy_four_momentum,true,false))};
      break;
    case TAU:
      decay_products = {std::make_shared<Tau>(Tau(dummy_four_momentum,false,{})),
                        std::make_shared<Tau>(Tau(dummy_four_momentum,true,{}))};
      break;
    case ELECTRONNEUTRINO:
      decay_products = {std::make_shared<ElectronNeutrino>(ElectronNeutrino(dummy_four_momentum,false,false)),
                        std::make_shared<ElectronNeutrino>(ElectronNeutrino(dummy_four_momentum,true,false))};
      break;
    case MUONNEUTRINO:
      decay_products = {std::make_shared<ElectronNeutrino>(ElectronNeutrino(dummy_four_momentum,false,false)),
                        std::make_shared<ElectronNeutrino>(ElectronNeutrino(dummy_four_momentum,true,false))};
      break;
    case TAUNEUTRINO:
      decay_products = {std::make_shared<TauNeutrino>(TauNeutrino(dummy_four_momentum,false,false)),
                        std::make_shared<TauNeutrino>(TauNeutrino(dummy_four_momentum,true,false))};
      break;                    
    case UP:
      decay_products = {std::make_shared<Up>(Up(dummy_four_momentum, false, RED)),
                        std::make_shared<Up>(Up(dummy_four_momentum, true, ANTIRED))};
      break;
    case DOWN:
      decay_products = {std::make_shared<Down>(Down(dummy_four_momentum, false, RED)),
                        std::make_shared<Down>(Down(dummy_four_momentum, true, ANTIRED))};
      break;
    case TOP:
      decay_products = {std::make_shared<Top>(Top(dummy_four_momentum, false, RED)),
                        std::make_shared<Top>(Top(dummy_four_momentum, true, RED))};
      break;
    case BOTTOM:
      decay_products = {std::make_shared<Bottom>(Bottom(dummy_four_momentum, false, RED)),
                        std::make_shared<Bottom>(Bottom(dummy_four_momentum, true, RED))};
      break;
    case STRANGE:
      decay_products = {std::make_shared<Strange>(Strange(dummy_four_momentum, false, RED)),
                        std::make_shared<Strange>(Strange(dummy_four_momentum, true, RED))};
      break;
    case CHARM:
      decay_products = {std::make_shared<Charm>(Charm(dummy_four_momentum, false, RED)),
                        std::make_shared<Charm>(Charm(dummy_four_momentum, true, RED))};
      break;
  }
}

// Printer
void ZBoson::print_data(bool include_products)
{
  Particle::print_data();
  if(include_products)
  {
    std::cout<<"Decays into:\n{\n"<<endl;
    vector<shared_ptr<Particle>>::iterator i{};
    for(i = decay_products.begin(); i < decay_products.end(); i++)
    {
      (*i)->print_data();
    }
    std::cout<<"}"<<endl;
  }
}