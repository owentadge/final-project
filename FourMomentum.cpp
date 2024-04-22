#include"FourMomentum.h"

// Constructors
// Default
FourMomentum::FourMomentum()
{
  std::cout<<"No arguments given for four-momentum - setting default values of [3,1,1,1]"<<std::endl;
  four_momentum = {3, 1, 1, 1};
}

// Paramtereised
FourMomentum::FourMomentum(double e_in, double px_in, double py_in, double pz_in)
{
  four_momentum = {e_in, px_in, py_in, pz_in};
}

FourMomentum::FourMomentum(vector<double>& four_momentum_in)
{
  four_momentum = four_momentum_in;
}

// Copy
FourMomentum::FourMomentum(FourMomentum& fm_object_in)
{
  four_momentum = fm_object_in.four_momentum;
}

// Move
FourMomentum::FourMomentum(FourMomentum&& fm_object_in)
{
  four_momentum = fm_object_in.four_momentum;
  fm_object_in.four_momentum = {};
}
