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
  for(int i=1; i<vec.size(); i++)
  {
    j=0;
    while(j<=i)
    {
      if(vec[i]<vec[j])
      {
        temp=vec[i];
        vec[i]=vec[j];
        vec[j]=temp;
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
