#include<iomanip>
#include"Catalogue.h"



int main()
{
  std::cout<<std::boolalpha;
  Catalogue test;
  test.add<Photon>(Photon(444,4,2,6));
  test.add<Photon>(Photon(10,1,2,3));
  Catalogue test2;
  test2.add<Photon>(Photon(856,4,12,22));
  test2.add<Photon>(Photon(69,69,69,69));
  Catalogue test3 = test + test2;
  Tau plop = Tau(100,1,2,3,true, TauDecayType::CD);
  Higgs fool = Higgs(12,3,4,3,HiggsDecayType::Z);
  FourMomentum poop = test3.total_four_momentum();
  std::cout<<poop.get_e()<<endl;
  std::cout<<poop.get_px()<<endl;
  std::cout<<poop.get_py()<<endl;
  std::cout<<poop.get_pz()<<endl;
  return 0;
}