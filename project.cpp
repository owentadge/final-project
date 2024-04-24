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
#include"MuonNeutrino.h"
#include"TauNeutrino.h"



int main()
{
  std::cout<<std::boolalpha;
  TauNeutrino test(10,1,2,3,false,true);
  TauNeutrino test2 = test;
  TauNeutrino test3 = move(test);
  TauNeutrino test4;
  test4 = test2;
  TauNeutrino test5;
  test5 = move(test3);
  test5.print_data();
  return 0;
}