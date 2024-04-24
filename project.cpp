#include<iomanip>
#include"FourMomentum.h"
#include"Particle.h"
#include"Fermion.h"
#include"Lepton.h"
#include"Electron.h"
#include"Muon.h"



int main()
{
  std::cout<<std::boolalpha;
  Muon test(10,1,2,3,true,false);
  Muon test2 = move(test);
  test2.print_data();
  return 0;
}