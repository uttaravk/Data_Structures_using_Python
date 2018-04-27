#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arrayPairSum(vector<int>& nums) {
  int result=0;
     sort(nums.begin(), nums.end());
     int x=nums.size();
     for(int i=0; i<x-1; i++)
     {
         result=result+nums[i];
         i++;
     }
     return result;
   }
int main()
{
vector <int> nums;
nums={1,4,3,2};
int ans=arrayPairSum(nums);
cout<<ans<<endl;
}
