// Calculate ASCII value of a characters
#include <iostream>
using namespace std;

int main()
{

char c='a';
char d='A';
cout<<"a: "<<int(c)<<endl;
cout<<"A: "<<int(d)<<endl;
char e='p';
char f='P';
cout<<"p: "<<int(e)<<endl;
cout<<"P: "<<int(f)<<endl;
if((int(e)==int(f)+32) or (int(e)+32==int(f)))
{
  cout<<"Yes"<<endl;
}
else
{
  cout<<"No"<<endl;
}
return 0;
}
