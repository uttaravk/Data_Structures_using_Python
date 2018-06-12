#include <iostream>
using namespace std;
int main()
{
  int x=-121;
  string y=to_string(x);
  cout<<y<<endl;
  int flag=0;
  for(int i=0; i<y.length(); i++)
  {
    if(y[i]!=y[(y.length()-(i+1))])
    {
      flag=1;
      break;
    }
  }
  if(flag==1)
  {
    cout<<"Not"<<endl;
  }
  else
  {
    cout<<"Yes"<<endl;
  }
}
