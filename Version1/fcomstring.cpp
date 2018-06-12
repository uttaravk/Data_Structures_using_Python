//Write a function to find the longest common prefix string amongst an array of strings.
#include<iostream>
#include <vector>
#include<string>
#include<cstring>
using namespace std;

int main()
{
vector <string> vec = {"strctp","sttcpy", "strlen"};
string longstr;
int min=vec[0].length();
string stemp=vec[0];

for (int i=1; i<vec.size(); i++)
{
  int temp=vec[i].length();
  if(min>temp)
  {
    min=temp;
    stemp.resize(min);
    stemp=vec[i];
  }
}
      int flag = 0; int j=0;
      for (int i=0; i<stemp.length(); i++)
      {
        for(int j=0; j<vec.size(); j++)
        {
          if(vec[j][i]==stemp[i])
          {
            flag=1;
          }
          else
          {
              flag=0;
              break;
          }

        }
        if(flag==1)
        {
          longstr.resize(longstr.length()+1);
          longstr[i]=stemp[i];
        }
      }

cout<<"LongString: "<<longstr<<endl;
}
