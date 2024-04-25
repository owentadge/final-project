#include<iomanip>
#include"FourMomentum.h"
#include"Higgs.h"
#include"ZBoson.h"
#include"Photon.h"
#include"WBoson.h"



int main()
{
  std::cout<<std::boolalpha;
  WBoson test(vector<double>{10,1,2,3},true,WDecayType::TS);
  test.print_data(true);
  return 0;
}