#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector <int> nums;
  nums={0};
  int res=0;
  int myres=0;
    for(int i=0; i<nums.size(); i++)
    {
      if(nums[i]==1)
      {
        myres++;
      }
      else
      {
        myres=0;
      }
      if(res<myres)
      {
        res=myres;
      }
    }
  cout<<"res: "<<res<<endl;
  return 0;
}
