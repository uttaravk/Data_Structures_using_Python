#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool checkPossibility(vector<int>& nums) {
  int count=0;
  int minval=nums[0];
  // if(nums[0]>nums[1])
  //423
    for(int i=1; i<nums.size(); i++)
    {
      if(count<2)
      {
        if(nums[i-1]>nums[i])
        {
          count++;
        }
        else if(count==1 && minval>nums[i-1])
        {
          minval=nums[i-1];
          // count++;
        }
      }
      else
      {
        break;
      }
    }
    if(count>1)
    {
      return false;
    }
    else
    {
      return true;
    }
   }

int main()
{
  vector <int> nums;
  nums={4,2,3};
  bool x;
  x=checkPossibility(nums);
  cout<<"x: "<<x<<endl;
  if(x==true)
  {
    cout<<"Yes"<<endl;
  }
  else
  {
    cout<<"No"<<endl;
  }
  return 0;
}
