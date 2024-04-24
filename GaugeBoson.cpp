#include"GaugeBoson.h"
// Constructors
// Parameterised
GaugeBoson::GaugeBoson(double energy, double px, double py, double pz, double charge_in, double mass_in, bool anti_in):
Particle(energy, px, py, pz, 1, mass_in, charge_in, anti_in){}

GaugeBoson::GaugeBoson(vector<double> momentum_in, double charge_in, double mass_in, bool anti_in):
Particle(momentum_in, 1, mass_in, charge_in, anti_in){}
// Copy
GaugeBoson::GaugeBoson(GaugeBoson& boson_in): Particle(boson_in){}
// Move
GaugeBoson::GaugeBoson(GaugeBoson&& boson_in): Particle(move(boson_in)){}

// Operator overloads
// Copy assignment
GaugeBoson& GaugeBoson::operator=(GaugeBoson& boson_in)
{
  if(&boson_in == this){return *this;}
  else
  {
    Particle::operator=(boson_in);
    return *this;
  }
}
// Move assignment
GaugeBoson& GaugeBoson::operator=(GaugeBoson&& boson_in)
{
  if(&boson_in == this){return *this;}
  else
  {
    Particle::operator=(boson_in);
    return *this;
  }
}


