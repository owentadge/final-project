#include"Higgs.h"

// Constructors
// Parameterised
Higgs::Higgs(double energy, double px, double py, double pz, HiggsDecayType decay_type):
Particle(energy, px, py, pz, 0, 125110, 0, false)
{
  switch(decay_type)
  {
    case Z:
      break;
  }
}

Higgs::Higgs(vector<double> momentum_in, HiggsDecayType decay_type):
Particle(momentum_in, 0, 125110, 0, false){}
// Copy
Higgs::Higgs(Higgs& higgs_in): Particle(higgs_in){}
// Move
Higgs::Higgs(Higgs&& higgs_in): Particle(move(higgs_in)){}

// Operator overloads
// Copy assignment
Higgs& Higgs::operator=(Higgs& higgs_in)
{
  if(&higgs_in == this){return *this;}
  else
  {
    Particle::operator=(higgs_in);
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
    return *this;
  }
}

// Getters
string Higgs::get_name(){return "Higgs Boson";}
vector<std::shared_ptr<Particle>> Higgs::get_decay_products(){return decay_products;}

// Setters
void Higgs::set_decay_products(vector<std::shared_ptr<Particle>> products){decay_products = products;}

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
      (*i)->print_data();
    }
    std::cout<<"}"<<endl;
  }
}