#include<iomanip>
#include"FourMomentum.h"
#include"Particle.h"
#include"Fermion.h"
#include"Lepton.h"
#include"Electron.h"
#include"Muon.h"
#include"Tau.h"



int main()
{
  std::cout<<std::boolalpha;
  vector<shared_ptr<Particle>> vec = {std::make_shared<Muon>(Muon(10,1,2,3,false,true)), std::make_shared<Electron>(Electron(10,1,2,3,false,{10,1,1,1}))};
  Tau test(10,1,2,3,true,vec);
  test.print_data(true);
  return 0;
}