#include"FourMomentum.h"
#include"Particle.h"
#include"Fermion.h"
#include"Lepton.h"
#include"Electron.h"



int main()
{
  Electron test(10,1,2,3,1,false,{1,2,3,4});
  Electron test2;
  test2 = test;
  test2.print_data();
  return 0;
}