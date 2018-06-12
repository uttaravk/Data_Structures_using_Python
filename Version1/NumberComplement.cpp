// Given a positive integer, output its complement number. The complement
//strategy is to flip the bits of its binary representation.
//
// Note:
// The given integer is guaranteed to fit within the range of a 32-bit signed integer.
// You could assume no leading zero bit in the integer’s binary representation.
// Example 1:
// Input: 5
// Output: 2
//
// Explanation: The binary representation of 5 is 101 (no leading zero bits),
//and its complement is 010. So you need to output 2.
// Example 2:
// Input: 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits),
//and its complement is 0. So you need to output 0.


#include <iostream>
#include <vector>
#include<math.h>
using namespace std;

int main()
{
    //Method 1:
  cout<<"Method 1"<<endl;
  int x=9;
  cout<<"Input: "<<x<<endl;

  vector <int> vec;
  while(x!=0)
  {
    if(x%2==0)
    {
          vec.insert(vec.begin(),1);
    }
    else if(x%2==1)
    {
          vec.insert(vec.begin(),0);
    }
    x=x/2;
  }
  int y=vec.size()-1;
  int res=0;
  for(int i=0; i<vec.size(); i++)
  {
    res=res+(vec[i]*(pow(2,y)));
    y=y-1;
  }
  cout<<"Result: "<<res<<endl;
  cout<<endl;

    //Method 2:
  cout<<"Method 2"<<endl;

  int num=9;
  cout<<"Input: "<<num<<endl;
  int y1=0;
  int count = 1, num2 = num;
  if (num == 1)
  {
    cout<<y1<<endl;
  }
  while (num!=0)
  {
    num = num/2;
    count = count*2; //generating power
  }
        y1=num2^(count - 1); //binary exor and converted into decimal
cout<<"Result: "<<y1<<endl;

  return 0;
}
