#include"FourMomentum.h"
#include"Particle.h"

using std::move;

int main()
{
  Particle test(10,1,2,3,1,1,-1,false);
  Particle test2(30,1,2,3,1,1,-1,false);
  test2 = move(test);
  return 0;
}