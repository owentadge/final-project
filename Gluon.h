#ifndef Gluon_h
#define Gluon_h
#include"GaugeBoson.h"

using std::pair;

class Gluon: public GaugeBoson
{
protected:
  pair<ColourCharge, ColourCharge> colour_charges;
public:
  // Constructors
  // Default
  Gluon() = default;
  
};


#endif