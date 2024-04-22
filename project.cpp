#include"FourMomentum.h"

using std::move;

int main()
{
  FourMomentum zooboo = FourMomentum(1,2,3,4);
  FourMomentum durrPlant = zooboo;
  FourMomentum zingo = move(durrPlant);
  return 0;
}