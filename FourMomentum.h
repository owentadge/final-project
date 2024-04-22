#ifndef FourMomentum_h
#define FourMomentum_h

#include<iostream>
#include<vector>

using std::vector;

class FourMomentum
{
private:
  vector<double> verify_momentum(vector<double>& vector_in);
protected:
  vector<double> four_momentum;
public:
  // Constructors
  // Default
  FourMomentum();
  // Parameterised
  FourMomentum(double e_in, double px_in, double py_in, double pz_in);
  FourMomentum(vector<double>& four_momentum_in);
  // Copy
  FourMomentum(FourMomentum& four_momentum_in);
  // Move
  FourMomentum(FourMomentum&& four_momentum_in);
  // Getters
  vector<double> get_momentum();
  double get_e();
  double get_px();
  double get_py();
  double get_pz();
  double get_invariant_mass();
  // Momentum setter
  void set_momentum(vector<double>& vector_in);
};


#endif