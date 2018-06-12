#include <iostream>
using namespace std;
int main()
{
  string s="b";
  int mycount=0; int mylen=0;
      for(int i=s.length()-1; i>=0; i--)
      {
        if(s[i]!=' ')
        {
            mycount++;
        }
        else if(mycount!=0)
        {
             mylen=mycount;
             mycount=0;
             break;
        }
      }
      if(mycount!=0)
      {
        mylen=mycount;
      }
  cout<<"Last Length: "<<mylen<<endl;
  return 0;
}
