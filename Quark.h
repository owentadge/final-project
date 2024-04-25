#ifndef Quark_h
#define Quark_h
#include"Fermion.h"
#include"Enumerations.h"

class Quark: public Fermion
{
protected:
  double baryon_number;
  ColourCharge colour_charge;
public:
  // Constructors
  Quark() = default;
  // Parameterised
  Quark(double energy, double px, double py, double pz, double mass_in, double charge_in, bool anti_in, ColourCharge colour_in);
  Quark(vector<double> momentum_in, double mass_in, double charge_in, bool anti_in, ColourCharge colour_in);
  // Copy
  Quark(Quark& quark_in);
  // Move
  Quark(Quark&& quark_in);

  // Destructor
  ~Quark(){}

  // Operator overloads
  // Copy assignment
  Quark& operator=(Quark& quark_in);
  // Move assignment
  Quark& operator=(Quark&& quark_in);

  // Printer
  void print_data();

  
  // Getters
  double get_baryon_number();
  string get_colour_charge();

  // Setters
  void set_colour_charge(ColourCharge colour_in);
};
#endif