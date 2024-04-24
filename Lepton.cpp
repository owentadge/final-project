#include"Lepton.h"

// Constructors
// Parameterised
Lepton::Lepton(double energy, double px, double py, double pz, float mass_in, float charge_in, bool anti_in): 
Fermion(energy, px, py, pz, mass_in, charge_in, anti_in)
{
  if(is_anti){lepton_number = -1;}
  else lepton_number = 1;
}
Lepton::Lepton(vector<double> momentum_in, float mass_in, float charge_in, bool anti_in):
Fermion(momentum_in, mass_in, charge_in, anti_in)
{
  if(is_anti){lepton_number = -1;}
  else lepton_number = 1;
}
// Copy
Lepton::Lepton(Lepton& lepton_in): Fermion(lepton_in) {lepton_number = lepton_in.lepton_number;}
// Move
Lepton::Lepton(Lepton&& lepton_in): Fermion(move(lepton_in))
{
  lepton_number = lepton_in.lepton_number;
  lepton_in.lepton_number = 0;
}

// Operator overloads
// Copy assignment
Lepton& Lepton::operator=(Lepton& lepton_in)
{
  if(&lepton_in == this){return *this;}
  else
  {
    Fermion::operator=(lepton_in);
    lepton_number = lepton_in.lepton_number;
    return *this;
  }
}
// Move assignment
Lepton& Lepton::operator=(Lepton&& lepton_in)
{
  if(&lepton_in == this){return *this;}
  else
  {
    Fermion::operator=(move(lepton_in));
    lepton_number = lepton_in.lepton_number;
    lepton_in.lepton_number = 0;
    return *this;
  }
}

// Getters
int Lepton::get_lepton_number(){return lepton_number;}