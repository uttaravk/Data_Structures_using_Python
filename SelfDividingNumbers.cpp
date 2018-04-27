// A self-dividing number is a number that is divisible by every digit it contains.
//
// For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
//
// Also, a self-dividing number is not allowed to contain the digit zero.
//
// Given a lower and upper number bound, output a list of every possible self dividing number,
// including the bounds if possible.
//
// Example 1:
// Input:
// left = 1, right = 22
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
// Note:
//
// The boundaries of each input argument are 1 <= left <= right <= 10000.

#include <iostream>
#include  <vector>
using namespace std;

int main()
{
  vector <int> vec;
  int left=1;
  int right=22;
  int x=0;
  int rem=0;
  for(int i=left; i<=right; i++)
  {
    x=i;
    rem=0;
    while(x!=0)
    {
      rem=x%10;
      if(rem!=0)
      {
        if((i%rem)!=0)
        {
          rem=1;
          break;
        }
        rem=0;
        x=x/10;
      }
      else
      {
        rem=1;
        break;
      }
    }
    if(rem==0)
    {
      vec.push_back(i);
    }
  }
  for(int i=0; i<vec.size(); i++)
  {
    cout<<vec[i]<<" ";
  }
  cout<<endl;
  return 0;
}
