#include"Photon.h"
// Constructors
// Parameterised
Photon::Photon(double energy, double px, double py, double pz): GaugeBoson(energy, px, py, pz, 0, 0, false){}
Photon::Photon(vector<double> momentum_in): GaugeBoson(momentum_in, 0, 0, false){}
// Copy
Photon::Photon(Photon& photon_in):GaugeBoson(photon_in){}
// Move
Photon::Photon(Photon&& photon_in):GaugeBoson(move(photon_in)){}

// Operator overloads
// Copy assignment
Photon& Photon::operator=(Photon& photon_in)
{
  if(&photon_in == this){return *this;}
  else
  {
    GaugeBoson::operator=(photon_in);
    return *this;
  }
}
// Move assignment
Photon& Photon::operator=(Photon&& photon_in)
{
  if(&photon_in == this){return *this;}
  else
  {
    GaugeBoson::operator=(photon_in);
    return *this;
  }
}

// Getters
string Photon::get_name(){return "Photon";}