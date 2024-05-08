#ifndef GaugeBoson_h
#define GaugeBoson_h
#include"Particle.h"
#include"ColourCharge.h"
#include"Electron.h"
#include"Muon.h"
#include"Tau.h"
#include"ElectronNeutrino.h"
#include"MuonNeutrino.h"
#include"TauNeutrino.h"
#include"Up.h"
#include"Down.h"
#include"Bottom.h"
#include"Top.h"
#include"Strange.h"
#include"Charm.h"

class GaugeBoson: public Particle
{
public:
  // Constructors
  // Default
  GaugeBoson() = default;
  // Parameterised
  GaugeBoson(double energy, double px, double py, double pz, double charge_in, double mass_in, bool anti_in);
  GaugeBoson(vector<double> momentum_in, double mass_in, double charge_in, bool anti_in);
  // Copy
  GaugeBoson(GaugeBoson& boson_in);
  // Move
  GaugeBoson(GaugeBoson&& boson_in);

  // Destructor
  ~GaugeBoson(){}

  // Operator overloads
  // Copy assignment
  GaugeBoson& operator=(GaugeBoson& boson_in);
  // Move assignment
  GaugeBoson& operator=(GaugeBoson&& boson_in);


};
#endif