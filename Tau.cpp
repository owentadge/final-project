#include"Tau.h"

// Constructors
// Parameterised
Tau::Tau(double energy, double px, double py, double pz, bool anti_in, vector<shared_ptr<Particle>> decay_in):
Lepton(energy, px, py, pz, rest_mass, -1, anti_in)
{
  if(is_anti){charge = 1;}
  decay_products = decay_in;
}
Tau::Tau(vector<double> momentum_in, bool anti_in, vector<shared_ptr<Particle>> decay_in):
Lepton(momentum_in, rest_mass, -1, anti_in)
{
  if(is_anti){charge = 1;}
  decay_products = decay_in;
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