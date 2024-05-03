#ifndef FourMomentum_h
#define FourMomentum_h

#include<iostream>
#include<vector>
#include<cmath>
#include<memory>

#include"Particle.h"

using std::vector;

class Particle;

class FourMomentum
{
private:
  vector<double> verify_momentum(vector<double> vector_in, Particle* particle_in = nullptr);
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
  // Destructor
  ~FourMomentum(){}

  // Operator overloads
  // Copy assignment
  FourMomentum& operator=(FourMomentum& fm_object_in);
  // Move assignment
  FourMomentum& operator=(FourMomentum&& fm_object_in);
  // Addition
  FourMomentum operator+(FourMomentum fm_object_in);
  // Subtraction
  FourMomentum operator-(FourMomentum fm_object_in);
  // Multiplication / dot product
  double operator*(FourMomentum fm_object_in);

  // Getters
  vector<double> get_momentum();
  double get_e();
  double get_px();
  double get_py();
  double get_pz();
  double get_invariant_mass();
  // Momentum setter
  void set_momentum(vector<double> vector_in);

};


#endif