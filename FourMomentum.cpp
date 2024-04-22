/*
TODO:
verify the physicality of four-vector - invariant mass = particle rest mass
*/

#include"FourMomentum.h"

// Constructors
// Default
FourMomentum::FourMomentum()
{
  std::cout<<"No arguments given for four-momentum - setting default values of [3,1,1,1]"<<std::endl;
  four_momentum = {3, 1, 1, 1};
}

// Paramtereised
FourMomentum::FourMomentum(double e_in, double px_in, double py_in, double pz_in){four_momentum = {e_in, px_in, py_in, pz_in};}

FourMomentum::FourMomentum(vector<double>& four_momentum_in){four_momentum = four_momentum_in;}

// Copy
FourMomentum::FourMomentum(FourMomentum& fm_object_in){four_momentum = fm_object_in.four_momentum;}

// Move
FourMomentum::FourMomentum(FourMomentum&& fm_object_in)
{
  four_momentum = fm_object_in.four_momentum;
  fm_object_in.four_momentum = {};
}

// Operator overloads
// Copy assignment
FourMomentum& FourMomentum::operator=(FourMomentum& fm_object_in)
{
  if (&fm_object_in == this){return *this;}
  else
  {
    four_momentum = fm_object_in.four_momentum;
    return *this;
  }
}
// Move assignment
FourMomentum& FourMomentum::operator=(FourMomentum&& fm_object_in)
{
  if (&fm_object_in == this){return *this;}
  else
  {
    four_momentum = move(fm_object_in.four_momentum);
    return *this;
  }  
}
// Addition
FourMomentum FourMomentum::operator+(FourMomentum& fm_object_in)
{
  vector<double> temp;
  for(int i{}; i < 4; i++)
  {
    temp.push_back(four_momentum.at(i) + fm_object_in.four_momentum.at(i));
  }
  return FourMomentum(temp);
}
// Subtraction
FourMomentum FourMomentum::operator-(FourMomentum& fm_object_in)
{
  vector<double> temp;
  for(int i{}; i < 4; i++)
  {
    temp.push_back(four_momentum.at(i) - fm_object_in.four_momentum.at(i));
  }
  return FourMomentum(temp);
}
// Multiplication / dot product
double FourMomentum::operator*(FourMomentum& fm_object_in)
{
  double result;
  for(int i{}; i < 4; i++)
  {
    result += four_momentum.at(i) * fm_object_in.four_momentum.at(i);
  }
  return result;
}

// Getters
// Energy
double FourMomentum::get_e(){return four_momentum.at(0);}
// P_x
double FourMomentum::get_px(){return four_momentum.at(1);}
// P_y
double FourMomentum::get_py(){return four_momentum.at(2);}
// P_z
double FourMomentum::get_pz(){return four_momentum.at(3);}
// Full four-momentum
vector<double> FourMomentum::get_momentum(){return four_momentum;}
// Invariant mass
double FourMomentum::get_invariant_mass()
{
  double momentum_sum{};
  for(vector<double>::iterator i = four_momentum.begin() + 1; i < four_momentum.end(); i++)
  {
    momentum_sum += pow((*i), 2);
  }
  return sqrt(pow(four_momentum.at(0), 2) - momentum_sum);
}

// Setters
// Momentum
void FourMomentum::set_momentum(vector<double>& momentum_in){four_momentum = momentum_in;}

