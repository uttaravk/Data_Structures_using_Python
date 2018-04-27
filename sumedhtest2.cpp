#include <iostream>
#include <vector>
using namespace std;

int oddNumbers(int l, int r, int result_size)
{
  result_size=0;
  int arr[r-l];

  int j=0;
  for(int i=l; i<=r; i++)
  {
    if(i%2!=0 && i!=0)
    {
      result_size++;
      arr[j]=i;
      j++;
    }
  }
return arr;
}

int main()
{
  int l=3;
  int r=9;
  int arr1[r-l];
int *res;
res=oddNumbers(l,r,4);

  cout<<*(res++)<<endl;

  return 0;
}
