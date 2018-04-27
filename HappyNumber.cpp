// Write an algorithm to determine if a number is "happy".
//
// A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
//
// Example: 19 is a happy number
//
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1


#include<iostream>
#include<string>
#include <exception>
using namespace std;
bool isHappy(int n) {
      static int count=0;
      static bool flag=0;
      count++;
      int res=0;
      int rem=0;
      bool x;
      while(n>0)
      {
        rem=n%10;
        res=((rem)*(rem))+res;
        n=n/10;
      }
      if(res>1 && count<20 && x==0)
      {
          x=isHappy(res);
      }
      else if(res==1)
      {
        flag=1;
        return flag;
      }
      else if(x==0)
      {
        flag=0;
        return flag;
      }
      return flag;
    }

void myfunc(int y)
{
  static int count=1;
  count++;
  int res=0;
  int rem=0;
  while(y>0)
  {
    rem=y%10;
    res=((rem)*(rem))+res;
    y=y/10;
  }
  if(res>1 and count<10)
  {
      myfunc(res);
  }
  else if(res==1)
  {
        cout<<"Happy Number"<<endl;
  }
  else
  {
    cout<<"Not a Happy Number"<<endl;
  }
}
int main()
{
  int x=7;
  bool y;
  cout<<"myfunc: "<<endl;  myfunc(x);
  y=isHappy(x);
  cout<<"isHappy: "<<endl;
  if(y==0)
  {
        cout<<"Not a Happy Number"<<endl;
  }
  else if (y==1)
  {
        cout<<"Happy Number"<<endl;
  }
  return 0;
}
