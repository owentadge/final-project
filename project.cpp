#include<iomanip>
#include"FourMomentum.h"
#include"Higgs.h"
#include"ZBoson.h"



int main()
{
  std::cout<<std::boolalpha;
  ZBoson test({10,1,2,3}, DOWN);
  test.print_data(true);
  ZBoson test2 = move(test);
  return 0;
}