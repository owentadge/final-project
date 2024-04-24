#include"HiggsBoson.h"

// Constructors
// Parameterised
HiggsBoson::HiggsBoson(double energy, double px, double py, double pz):
Particle(energy, px, py, pz, 0, 125110, 0, false){}

HiggsBoson::HiggsBoson(vector<double> momentum_in):
Particle(momentum_in, 0, 125110, 0, false){}
// Copy
HiggsBoson::HiggsBoson(HiggsBoson& higgs_in): Particle(higgs_in){}
// Move
HiggsBoson::HiggsBoson(HiggsBoson&& higgs_in): Particle(move(higgs_in)){}

// Operator overloads
// Copy assignment
HiggsBoson& HiggsBoson::operator=(HiggsBoson& higgs_in)
{
  if(&higgs_in == this){return *this;}
  else
  {
    Particle::operator=(higgs_in);
    return *this;
  }
}
// Move assignment
HiggsBoson& HiggsBoson::operator=(HiggsBoson&& higgs_in)
{
  if(&higgs_in == this){return *this;}
  else
  {
    Particle::operator=(move(higgs_in));
    return *this;
  }
}

// Getters
string HiggsBoson::get_name(){return "Higgs Boson";}
vector<std::shared_ptr<Particle>> HiggsBoson::get_decay_products(){return decay_products;}

// Setters
void HiggsBoson::set_decay_products(vector<std::shared_ptr<Particle>> products){decay_products = products;}

// Printer
void HiggsBoson::print_data(bool include_products)
{
  Particle::print_data();
  if(include_products)
  {
    std::cout<<"Decays into:\n{\n"<<endl;
    vector<std::shared_ptr<Particle>>::iterator i{};
    for(i = decay_products.begin(); i < decay_products.end(); i++)
    {
      (*i)->print_data();
    }
    std::cout<<"}"<<endl;
  }
}