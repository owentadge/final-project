#ifndef Gluon_h
#define Gluon_h
#include"GaugeBoson.h"

using std::pair;

class Gluon: public GaugeBoson
{
protected:
  std::shared_ptr<pair<ColourCharge, ColourCharge>> colour_charges;
public:
  // Constructors
  // Default
  Gluon() = default;
  // Parameterised
  Gluon(double energy, double px, double py, double pz, pair<ColourCharge, ColourCharge> charges_in);
  Gluon(vector<double> momentum_in, pair<ColourCharge, ColourCharge> charges_in);
  // Copy
  Gluon(Gluon& gluon_in);
  // Move
  Gluon(Gluon&& gluon_in);

  // Operator overloads
  // Copy assignment
  Gluon& operator=(Gluon& gluon_in);
  Gluon& operator=(Gluon&& gluon_in);
  
  // Setters
  void set_colour_charges(pair<ColourCharge, ColourCharge>);

  // Getters
  pair<string, string> get_colour_charges();
  string get_name();

  // Printer
  void print_data();
};


#endif