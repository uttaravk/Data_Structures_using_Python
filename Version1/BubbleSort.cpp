#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector <int> vec;
  vec={2,5,3,8,10,0};
  cout<<"Before: "<<endl;
  for(int i=0; i<vec.size(); i++)
  {
    cout<<vec[i]<<" ";
  }
  cout<<endl;
  int temp;
  int j=0;
  for(int i=0; i<vec.size(); i++)
  {
    j=0;
    while(j<vec.size()-1)
    {
      if(vec[j]>vec[j+1])
      {
        temp=vec[j];
        vec[j]=vec[j+1];
        vec[j+1]=temp;
      }
      j++;
    }
  }
  cout<<"After: "<<endl;
  for(int i=0; i<vec.size(); i++)
  {
    cout<<vec[i]<<" ";
  }
  cout<<endl;
  return 0;
}
