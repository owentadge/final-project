#ifndef Enumerations_h
#define Enumerations_h
enum ColourCharge
{
  NONE,
  RED = 1,
  ANTIRED = 2,
  BLUE = 3,
  ANTIBLUE = 4,
  GREEN = 5,
  ANTIGREEN = 6 
};
enum HiggsDecayType
{
  Z,
  W,
  PHOTON,
  B,
};
enum ZDecayType
{
  ELECTRON,
  MUON,
  TAU,
  ELECTRONNEUTRINO,
  MUONNEUTRINO,  
  TAUNEUTRINO,
  UP,
  DOWN,
  CHARM,
  STRANGE,
  TOP,
  BOTTOM,
};
#endif