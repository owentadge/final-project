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
#include"Down.h"
#include"Top.h"
#include"Up.h"
#include"Bottom.h"
#include"Strange.h"
#include"Charm.h"
#include"HiggsBoson.h"



int main()
{
  std::cout<<std::boolalpha;
  HiggsBoson test(10,2,2,2);
  test.print_data(true);
  return 0;
}