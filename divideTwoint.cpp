#include <iostream>
using namespace std;

int divide(int dividend, int divisor)
{
  int count=0;
  if(dividend==divisor)
  {
    return 1;
  }
  else if(divisor==1)
  {
    return dividend;
  }
  else if(divisor==-1)
  {
    if(dividend>0)
    {
      dividend=dividend-(dividend+dividend);
      return dividend;
    }
    else if(dividend<0)
    {
      dividend=(dividend+dividend)-dividend;
      return dividend;
    }
  }
  else
  {
        while(dividend>=divisor && dividend>0 && divisor>0)
        {
          dividend=dividend-divisor;
          count++;
        }
  }

  return count;
}
int main()
{
  int divi=-1;
  int dsi=1;
  int x=divide(divi,dsi);
  cout<<x<<endl;
}
