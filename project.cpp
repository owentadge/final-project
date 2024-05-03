#include<iomanip>
#include"Catalogue.h"



int main()
{
  std::cout<<std::boolalpha;
  /*
  Catalogue test;
  test.add<Photon>(Photon(444,4,2,6));
  test.add<Photon>(Photon(10,1,2,3));
  Catalogue test2;
  test2.add<Photon>(Photon(856,4,12,22));
  test2.add<Photon>(Photon(69,69,69,69));
  Catalogue test3 = test + test2;
  Tau plop = Tau(100,1,2,3,true, TauDecayType::CD);
  Higgs fool = Higgs(12,3,4,3,HiggsDecayType::Z);
  FourMomentum test999 = test3.total_four_momentum();
  std::cout<<test999.get_e()<<endl;
  std::cout<<test999.get_px()<<endl;
  std::cout<<test999.get_py()<<endl;
  std::cout<<test999.get_pz()<<endl;
  */
  Electron test = Electron(0,2,2,2,false,{1,2,3,4});
  std::cout<<test.get_four_momentum().get_invariant_mass()<<endl;
  test.print_data();
  return 0;
}