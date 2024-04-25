#include<iomanip>
#include"FourMomentum.h"
#include"Higgs.h"



int main()
{
  std::cout<<std::boolalpha;
  ZBoson test(vector<double>{10,1,2,3}, ZDecayType::UP);
  test.print_data(true);
  return 0;
}