#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
        // Method 1:
        // int x=nums.size();
        // for(int i=0; i<x; i++)
        // {
        //     if(nums[i]==val)
        //     {
        //         x--;
        //         nums.erase(nums.begin()+i);
        //         i--;
        //     }
        // }
        // return x;

        // Method 2:

        int sz = nums.size();
        if( sz == 0 ) return 0;
          cout<<"sz (bf): "<<sz<<endl;
        while( nums[sz-1] == val && sz >0 ) sz--;
        for( int i=0; i<sz; ++i){
          cout<<"i: "<<i<<endl;
            if( nums[i] == val ) {
                nums[i] = nums[sz-1];
                cout<<"sz (af 1): "<<sz<<endl;
                sz--;
  cout<<"sz (af 2): "<<sz<<endl;
                while( nums[sz-1] == val ) sz--;
            }
            for(int i=0; i<nums.size(); i++)
            {
              cout<<nums[i];
            }
            cout<<endl;
        }
        nums.resize(sz);
        return sz;


    }

int main()
{
  vector<int> vec={3,3,4,2,1,3,4};
  for(int i=0; i<vec.size(); i++)
  {
    cout<<vec[i];
  }
  cout<<endl;
  int y=removeElement(vec, 3);
  for(int i=0; i<y; i++)
  {
    cout<<vec[i]<<endl;
  }
}
