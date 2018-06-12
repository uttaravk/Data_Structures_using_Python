#include <iostream>
using namespace std;

int main()
{
  string moves="LUDRR";
  int count1=0;
  int count2=0;
  for(int i=0; i<moves.length(); i++)
  {
    if(moves[i]=='L')
    {
      count1++;
    }
    else if(moves[i]=='R')
    {
      count1--;
    }
    else if(moves[i]=='U')
    {
      count2++;
    }
    else if(moves[i]=='D')
    {
      count2--;
    }
  }
  if(count1==0 && count2==0)
  {
    cout<<"Yes it is a circle"<<endl;
  }
  else
  {
    cout<<"It is not a circle"<<endl;
  }
  return 0;
}
