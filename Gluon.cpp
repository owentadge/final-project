#include"Gluon.h"
// Constructors
// Parameterised
Gluon::Gluon(double energy, double px, double py, double pz, pair<ColourCharge, ColourCharge> charges_in):
GaugeBoson(energy, px, py, pz, 0, 0, false) {set_colour_charges(charges_in);}
Gluon::Gluon(vector<double> momentum_in, pair<ColourCharge, ColourCharge> charges_in):
GaugeBoson(momentum_in, 0, 0, false) {set_colour_charges(charges_in);}
// Copy
Gluon::Gluon(Gluon& gluon_in): GaugeBoson(gluon_in)
{
  colour_charges = std::make_unique<pair<ColourCharge, ColourCharge>>(*(gluon_in.colour_charges));
}
// Move
Gluon::Gluon(Gluon&& gluon_in): GaugeBoson(move(gluon_in)) {colour_charges = move(gluon_in.colour_charges);}

// Operator overloads
// Copy assignment
Gluon& Gluon::operator=(Gluon& gluon_in)
{
  if(&gluon_in == this){return *this;}
  else
  {
    GaugeBoson::operator=(gluon_in);
    colour_charges = std::make_unique<pair<ColourCharge, ColourCharge>>(*(gluon_in.colour_charges));
    return *this;
  }
}
Gluon& Gluon::operator=(Gluon&& gluon_in)
{
  if(&gluon_in == this){return *this;}
  else
  {
    GaugeBoson::operator=(gluon_in);
    colour_charges = move(gluon_in.colour_charges);
    return *this;
  }
}

// Setters
void Gluon::set_colour_charges(pair<ColourCharge, ColourCharge> charges_in)
{
  if((charges_in.first % 2 !=0) && (charges_in.second % 2 ==0))
  {
    colour_charges = std::make_unique<pair<ColourCharge,ColourCharge>>(charges_in);
  }
  else
  {
    std::cout<<"First colour charge must be standard and second must be anti-. Defaulting to Red-Antired."<<endl;
    colour_charges = std::make_unique<pair<ColourCharge, ColourCharge>>(std::make_pair(RED,ANTIRED));
  }
}

// Getters
pair<string, string> Gluon::get_colour_charges()
{
  pair<string, string> temp;
  switch((*colour_charges).first)
  {
    case RED:
      temp.first = "Red";
      break;
    case BLUE:
      temp.first = "Blue";
    case GREEN:
      temp.first = "Green";
      break;
  }
  switch((*colour_charges).second)
  {
    case ANTIRED:
      temp.second = "Antired";
      break;
    case ANTIBLUE:
      temp.second = "Antiblue";
    case ANTIGREEN:
      temp.second = "Antigreen";
      break;
  }
  return temp;
}

string Gluon::get_name(){return "Gluon";};

// Printer
void Gluon::print_data()
{
  Particle::print_data();
  std::cout<<"Colour charges: "<<get_colour_charges().first<<" and "<<get_colour_charges().second<<endl<<endl;
}