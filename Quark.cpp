#include"Quark.h"

// Constructors
// Parameterised
Quark::Quark(double energy, double px, double py, double pz, double mass_in, double charge_in, bool anti_in, ColourCharge colour_in):
Fermion(energy, px, py, pz, mass_in, charge_in, anti_in)
{
  if(is_anti)
  {
    baryon_number = -1.0/3.0;
    charge = -charge_in;
    if(colour_in % 2 == 0){colour_charge = colour_in;}
    else
    {
      std::cout<<"Anti-quarks must have anti- colour charge - defaulting to anti-red"<<endl;
      colour_charge = ANTIRED;
    }
  }
  else
  {
    baryon_number = 1.0/3.0;
    if(colour_in % 2 != 0){colour_charge = colour_in;}
    else
    {
      std::cout<<"Quarks cannot have anti- colour charge - defaulting to red"<<endl;
      colour_charge = RED;
    }
  }
}

Quark::Quark(vector<double> momentum_in, double mass_in, double charge_in, bool anti_in, ColourCharge colour_in):
Fermion(momentum_in, mass_in, charge_in, anti_in)
{
  if(is_anti)
  {
    baryon_number = -1.0/3.0;
    charge = -charge_in;
    if(colour_in % 2 == 0){colour_charge = colour_in;}
    else
    {
      std::cout<<"Anti-quarks must have anti- colour charge - defaulting to anti-red"<<endl;
      colour_charge = ANTIRED;
    }
  }
  else
  {
    baryon_number = 1.0/3.0;
    if(colour_in % 2 != 0){colour_charge = colour_in;}
    else
    {
      std::cout<<"Quarks cannot have anti- colour charge - defaulting to red"<<endl;
      colour_charge = RED;
    }
  }
}
// Copy
Quark::Quark(Quark& quark_in): Fermion(quark_in)
{
  baryon_number = quark_in.baryon_number;
  colour_charge = quark_in.colour_charge;
}
// Move
Quark::Quark(Quark&& quark_in): Fermion(move(quark_in))
{
  baryon_number = quark_in.baryon_number;
  colour_charge = quark_in.colour_charge;
  quark_in.baryon_number = 0;
  quark_in.colour_charge = NONE;
}

// Operator overloads
// Copy assignment
Quark& Quark::operator=(Quark& quark_in)
{
  if(&quark_in == this){return *this;}
  else
  {
    Fermion::operator=(quark_in);
    baryon_number = quark_in.baryon_number;
    colour_charge = quark_in.colour_charge;
    return *this;
  }
}
// Move assignment
Quark& Quark::operator=(Quark&& quark_in)
{
  if(&quark_in == this){return *this;}
  else
  {
    Fermion::operator=(move(quark_in));
    baryon_number = quark_in.baryon_number;
    quark_in.baryon_number = 0;
    colour_charge = quark_in.colour_charge;
    quark_in.colour_charge = NONE;
    return *this;
  }
}

// Printer
void Quark::print_data()
{
  Particle::print_data();
  std::cout<<"Baryon number: "<<baryon_number<<endl<<"Colour charge: "<<get_colour_charge()<<endl<<endl;
}

// Getters
double Quark::get_baryon_number(){return baryon_number;}
string Quark::get_colour_charge()
{
  switch(colour_charge)
  {
    case 1:
      return "Red";
      break;
    case 2:
      return "Anti-red";
      break;
    case 3:
      return "Blue";
      break;
    case 4:
      return "Anti-blue";
      break;
    case 5:
      return "Green";
      break;
    case 6:
      return "Anti-green";
      break;
    default:
      return "error";
  }
}

// Setters
void Quark::set_colour_charge(ColourCharge colour_in)
{
  if(is_anti)
  {
    if(colour_in % 2 == 0){colour_charge = colour_in;}
    else
    {
      std::cout<<"Anti-quarks must have anti- colour charge - defaulting to anti-red"<<endl;
      colour_charge = ANTIRED;
    }
  }
  else
  {
    if(colour_in % 2 != 0){colour_charge = colour_in;}
    else
    {
      std::cout<<"Quarks cannot have anti- colour charge - defaulting to red"<<endl;
      colour_charge = RED;
    }
  }
}