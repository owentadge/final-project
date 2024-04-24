#include<iomanip>
#include"FourMomentum.h"
#include"Particle.h"
#include"Fermion.h"
#include"Lepton.h"
#include"Electron.h"
#include"Muon.h"
#include"Tau.h"
#include"Neutrino.h"
#include"ElectronNeutrino.h"



int main()
{
  std::cout<<std::boolalpha;
  ElectronNeutrino test(10,1,2,3,false,true);
  ElectronNeutrino test2 = test;
  ElectronNeutrino test3 = move(test);
  ElectronNeutrino test4;
  test4 = test2;
  ElectronNeutrino test5;
  test5 = move(test3);
  test5.print_data();
  return 0;
}