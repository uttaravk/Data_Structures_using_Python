#include <iostream>
#include <vector>
using namespace std;

char * findNumber(int arr_size, int *arr, int k)
{
  for(unsigned int i=0; i<arr_size; i++)
  {
    if(arr[i]==k)
    {
      return "yes";
    }
  }
  return "no";
}

int main()
{
  char* x;
  int arr[] = {2,3,4,5};
  x=findNumber(5,arr,3);
  cout<<x<<endl;
  return 0;
}
