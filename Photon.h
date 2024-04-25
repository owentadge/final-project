#ifndef Photon_h
#define Photon_h
#include"GaugeBoson.h"

class Photon: public GaugeBoson
{
public:
 // Constructors
 // Default
 Photon() = default;
 // Parameterised
 Photon(double energy, double px, double py, double pz);
 Photon(vector<double> momentum_in);
 // Copy
 Photon(Photon& photon_in);
 // Move
 Photon(Photon&& photon_in);

 // Operator overloads
 // Copy assignment
 Photon& operator=(Photon& photon_in);
 // Move assignment
 Photon& operator=(Photon&& photon_in);

 // Getters
 string get_name();
};

#endif