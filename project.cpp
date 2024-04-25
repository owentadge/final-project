#include<iomanip>
#include"FourMomentum.h"
#include"Higgs.h"
#include"Gluon.h"



int main()
{
  std::cout<<std::boolalpha;
  Tau test(vector<double>{10,1,2,3}, false, TauDecayType::MUON);
  std::cout<<test.get_four_momentum().get_invariant_mass()<<endl<<endl;
  test.print_data(true);
  return 0;
}