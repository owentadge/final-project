#ifndef Muon_h
#define Muon_h
#include"Lepton.h"
class Muon: public Lepton
{
protected:
  bool is_isolated;

public:
  // Constructors
  Muon() = default;
  // Paramterised
  Muon(double energy, double px, double py, double pz, bool anti, bool isolated);
  Muon(vector<double> momentum_in, bool anti, bool isolated);
  // Copy
  Muon(Muon& muon_in);
  // Move
  Muon(Muon&& muon_in);

  // Destructor
  ~Muon(){}

  // Operator overloads
  // Copy
  Muon& operator=(Muon& muon_in);
  // Move
  Muon& operator=(Muon&& muon_in);

  // Print function
  void print_data();

  // Getters
  // Name
  string get_name();
  // Isolation status
  bool get_isolation();

  // Setter
  void set_isolated(bool isolation);
};
#endif