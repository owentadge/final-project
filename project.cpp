#include"FourMomentum.h"
#include"Particle.h"
#include"Fermion.h"



int main()
{
  Fermion test(1,2,3,4,5,2,false);
  Fermion test2;
  test2 = move(test);
  std::cout<<test2.get_spin();
  return 0;
}