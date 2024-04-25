#include<iomanip>
#include"FourMomentum.h"
#include"Higgs.h"
#include"Gluon.h"



int main()
{
  std::cout<<std::boolalpha;
  Gluon test(vector<double>{10,1,2,3}, std::make_pair(ANTIRED, ANTIBLUE));
  test.print_data();
  return 0;
}