#include"Higgs.h"

// Constructors
// Parameterised
Higgs::Higgs(double energy, double px, double py, double pz, HiggsDecayType decay_type):
Particle(energy, px, py, pz, 0, 125110, 0, false){set_decay_products(decay_type);}

Higgs::Higgs(vector<double> momentum_in, HiggsDecayType decay_type):
Particle(momentum_in, 0, 125110, 0, false){set_decay_products(decay_type);}
// Copy
Higgs::Higgs(Higgs& higgs_in): Particle(higgs_in){decay_products = higgs_in.decay_products;}
// Move
Higgs::Higgs(Higgs&& higgs_in): Particle(move(higgs_in))
{
  decay_products = higgs_in.decay_products;
  higgs_in.decay_products = {};
}

// Operator overloads
// Copy assignment
Higgs& Higgs::operator=(Higgs& higgs_in)
{
  if(&higgs_in == this){return *this;}
  else
  {
    Particle::operator=(higgs_in);
    decay_products = higgs_in.decay_products;
    return *this;
  }
}
// Move assignment
Higgs& Higgs::operator=(Higgs&& higgs_in)
{
  if(&higgs_in == this){return *this;}
  else
  {
    Particle::operator=(move(higgs_in));
    decay_products = higgs_in.decay_products;
    higgs_in.decay_products = {};  
    return *this;
  }
}

// Getters
string Higgs::get_name(){return "Higgs Boson";}
vector<std::shared_ptr<Particle>> Higgs::get_decay_products(){return decay_products;}

// Setters
void Higgs::set_decay_products(HiggsDecayType decay_type)
{
  switch(decay_type)
  {
    case HiggsDecayType::Z:
      decay_products = {std::make_shared<ZBoson>(ZBoson()), std::make_shared<ZBoson>(ZBoson())};
      break;
    case HiggsDecayType::W:
      decay_products = {std::make_shared<WBoson>(WBoson()), std::make_shared<WBoson>(WBoson())};
      break;
    case HiggsDecayType::PHOTON:
      decay_products = {std::make_shared<Photon>(Photon()), std::make_shared<Photon>(Photon())};
      break;
    case HiggsDecayType::B:
      decay_products = {std::make_shared<Bottom>(Bottom()), std::make_shared<Bottom>(Bottom())};
      break;
  }
}

// Printer
void Higgs::print_data(bool include_products)
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