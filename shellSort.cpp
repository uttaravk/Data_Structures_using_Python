#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector <int> vec;
  vec={12,4,54,2,3};
  cout<<"Before: "<<endl;
  for(int i=0; i<vec.size(); i++)
  {
    cout<<vec[i]<<" ";
  }
  cout<<endl;
  int temp;
  int j=0;
  int n=vec.size()/2;
  while(n!=0)
  {
    for(int i=0; i<vec.size(); i++)
    {
      for(int j=0; j<=(vec.size()/2); j++)
      {
        if(vec[j]>vec[j+n])
        {
          temp=vec[j];
          vec[j]=vec[j+n];
          vec[j+n]=temp;
        }
      }
    }
    n=n/2;
  }
  cout<<"After: "<<endl;
  for(int i=0; i<vec.size(); i++)
  {
    cout<<vec[i]<<" ";
  }
  cout<<endl;
  return 0;
}
