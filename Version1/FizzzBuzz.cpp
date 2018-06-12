#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int n=15;
  vector <string> vec;
  for(int i=1; i<=n; i++)
  {
    if(i%3==0)
    {
      if(i%5==0)
      {
        vec.push_back("FizzBuzz");
      }
      else
      {
        vec.push_back("Fizz");
      }
    }
    else if(i%5==0)
    {
      vec.push_back("Buzz");
    }
    else
    {
      vec.push_back(to_string(i));
    }
  }
for(int i=0; i<vec.size(); i++)
{
  cout<<vec[i]<<endl;
}
  return 0;
}
