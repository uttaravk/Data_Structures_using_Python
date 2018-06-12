#include <iostream>
#include<set>
using namespace std;

int numJewelsInStones(string J, string S)
{
  set<char>myset;
  int jsize=J.length();
  int ssize=S.length();
  // string temp;
  int count=0;
  for (int i=0; i<jsize; i++)
  {
    myset.insert(J[i]);
  }
  for(int i=0; i<ssize; i++)
  {
    // if(i<ssize-jsize)
    // {
    //   temp=S.substr(i,jsize);
    //   if(temp==J)
    //   {
    //     count=count+1;
    //   }
    // }
    if(myset.find(S[i]) != myset.end())
    {
      count=count+1;
      // myset.erase(S[i]);
    }
  }
  return count;
}
int main()
{
  int y;
  y=numJewelsInStones("aA","aAAbbbb");
  cout<<y<<endl;
  return 0;
}
