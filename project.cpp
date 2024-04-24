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
#include"Quark.h"



int main()
{
  std::cout<<std::boolalpha;
  Quark test(10,1,2,3,1,2/3,false,RED);
  test.print_data();
  test.set_colour_charge(ANTIGREEN);
  test.print_data();
  return 0;
}