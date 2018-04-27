#include<iostream>
#include <string>
using namespace std;

bool rotateString(string A, string B) {
  // cout<<"A: "<<A<<endl;
    // cout<<"B: "<<B<<endl;
    int asize=A.length();
    int bsize=B.length();
    int pos=0;
    if(asize!=bsize)
    {
      return 0;
    }
    for(int i=0; i<asize;i++)
    {
      if(A[i]==B[0])
      {
        pos=i;


    string temp1=A.substr(0,pos);
    // cout<<temp1<<endl;
    string temp2=A.substr(pos+1, asize);
    // cout<<temp2<<endl;
    string res=B[0]+temp2+temp1;
    // cout<<res<<endl;
    if(res==B)
    {
      return 1;
    }
  }
  }
    return 0;
  }

int main()
{
  bool y;
  y=rotateString("abcde","cdeab");
  cout<<"y: "<<y<<endl;
}
