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

enum class HiggsDecayType
{
  Z,
  W,
  PHOTON,
  B,
};

enum class ZDecayType
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

enum class WDecayType
{
  ELECTRON,
  MUON,
  TAU,
  UD,
  US,
  UB,
  CD,
  CS,
  CB,
  TD,
  TS,
  TB
};

#endif