#include<iomanip>
#include"FourMomentum.h"
#include"Higgs.h"
#include"ZBoson.h"
#include"Photon.h"



int main()
{
  std::cout<<std::boolalpha;
  Photon test(vector<double>{10,1,2,3});
  test.print_data();
  Photon test2 = move(test);
  return 0;
}