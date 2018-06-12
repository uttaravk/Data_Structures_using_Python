#include <iostream>
#include <map>
using namespace std;

int main()
{
  std::map<char,int> mymap;
  std::map<char,int>::iterator itr;
  int x=0;
  mymap['M']=1000;
  mymap['D']=500;
  mymap['C']=100;
  mymap['L']=50;
  mymap['X']=10;
  mymap['V']=5;
  mymap['I']=1;

  string s="MCMXCVI";
  int sum=0; int y=0;
  for(int i=0; i<s.length(); i++)
  {
    x=0, y=0;
    itr=mymap.find(s[i]);
    if(itr!=mymap.end())
    {
        x=mymap[s[i]];
    }
    itr=mymap.find(s[i+1]);
    if(itr!=mymap.end())
    {
        y=mymap[s[i+1]];
    }
    if(x>=y)
    {
      sum=sum+x;
    }
    else if(x<y)
    {
      sum=sum+(y-x);
      ++i;
    }
  }
  cout<<sum<<endl;

  return 0;
}
