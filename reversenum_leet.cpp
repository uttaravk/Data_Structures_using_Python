#include<iostream>
using namespace std;
#include<cstdlib>
#include<cstring>
#include<stdio.h>


int main()
{
long x=-12;
string y=to_string(x);
cout<<"Before: "<<y<<endl;
int flag=0;
if(y[0]=='-')
{
  y.erase(0,1);
  flag=1;
}

//Logic 1:
int itr=0;
        int count=y.length();
        if(count==2)
        {
            itr=1;
        }
        else
        {
          itr=count/2;
        }
        for(int i=0; i<itr; i++)
        {
          long temp;
          temp=y[i];
          y[i]=y[(count-1)-i];
          y[(count-1)-i]=temp;
        }

//Logic 2:

//reverse(y.begin(), y.end());
try
{
  signed int new1=stoi(y);
  if(flag==1)
  {
    y="-"+y;
    new1=(0-new1);
  }

  cout<<"AFTER: "<<new1<<endl;

}
catch(const std::exception& e)
{
  cout<<"return 0"<<endl;
}

}
