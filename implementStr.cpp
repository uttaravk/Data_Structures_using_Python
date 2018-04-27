#include <iostream>
#include <vector>
#include <string>
using namespace std;

int strStr(string haystack, string needle)
{
  int nelLen=needle.length();
  int hayLen=haystack.length();
        if(nelLen==0)
        {
            return 0;
        }
        //method 1
  // string temp;
  // // temp.resize(nelLen);
  // for(int i=0; i<haystack.length(); i++)
  // {
  //   // for(int j=0; j<nelLen; j++)
  //   // {
  //   //   temp[j]=haystack[i+j];
  //   // }
  //   string temp;
  //   temp=haystack.substr(i, nelLen);
  //   cout<<"temp: "<<temp<<endl;
  //   if(needle==temp)
  //   {
  //     return i;
  //   }
  //}
//method2
for(int i = 0, j = 0; i<=(hayLen-nelLen); i++, j=0)
{
  while(haystack[i+j] == needle[j])
  {
    j++;
    if(j==nelLen)
    {
      return i;
    }
  }
}
return -1;
}

int main()
{
 string haystack ="hello";
 string needle = "ll";
 int y=strStr(haystack, needle);
 cout<<"y: "<<y<<endl;
}
