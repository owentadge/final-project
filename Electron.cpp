#include"Electron.h"

// Constructors
// Parameterised
Electron::Electron(double energy, double px, double py, double pz, bool anti_in, vector<double> deposited_energies):
Lepton(energy, px, py, pz, rest_mass, -1, anti_in)
{
  if(is_anti){charge = 1;}
  energy_layers = verify_energies(deposited_energies);
}

Electron::Electron(vector<double> momentum_in, bool anti_in, vector<double> deposited_energies):
Lepton(momentum_in, rest_mass, 1, anti_in)
{
  if(is_anti){charge = 1;}
  energy_layers = verify_energies(deposited_energies);
}
// Copy
Electron::Electron(Electron& electron_in): Lepton(electron_in) {energy_layers = verify_energies(electron_in.energy_layers);}
// Move
Electron::Electron(Electron&& electron_in): Lepton(move(electron_in))
{
  energy_layers = verify_energies(electron_in.energy_layers);
  electron_in.energy_layers = {};
}

// Operator overloads
// Copy assignment
Electron& Electron::operator=(Electron& electron_in)
{
  if(& electron_in == this){return *this;}
  else
  {
    Lepton::operator=(electron_in);
    energy_layers = verify_energies(electron_in.energy_layers);
    return *this;
  }
}
// Move assignment
Electron& Electron::operator=(Electron&& electron_in)
{
  if(& electron_in == this){return *this;}
  else
  {  
    Lepton::operator=(move(electron_in));
    energy_layers = verify_energies(electron_in.energy_layers);
    electron_in.energy_layers = {};
    return *this;
  }
}


// Verify that deposited energies add to total energy
vector<double> Electron::verify_energies(vector<double> energies_in)
{
  double total_energy{};
  vector<double>::iterator energy_it;
  for(energy_it = energies_in.begin(); energy_it < energies_in.end(); ++energy_it)
  {
    total_energy += *energy_it;
  }
  if(total_energy == four_momentum->get_e()){return energies_in;}
  else
  {
    std::cout<<"Deposited energies do not sum to particle energy, assigning values to be equal in all layers"<<std::endl;
    return vector<double>(4,four_momentum->get_e()/4);
  }
}

// Getters
string Electron::get_name()
{
  if(is_anti) return "Anti-electron";
  else return "Electron";
}

// Printer
void Electron::print_data()
{
  Particle::print_data();
  std::cout<<"Deposited energies: "<<endl;
  for(int i{}; i < 4; i++)
  {
    std::cout<<"Layer "<<i+1<<": "<<energy_layers.at(i)<<endl;
  }
  std::cout<<endl;
}

// Setters
void Electron::set_energy_layers(vector<double> energies_in){energy_layers = verify_energies(energies_in);}