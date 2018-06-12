#include<iostream>
#include<string>
#include <vector>
using namespace std;

int main()
{
  int x=1;
  int y=4;
  vector <int>vec1;
      vector <int>vec2;
      int counter=0;
      while(y!=0)
      {
        vec1.insert(vec1.begin(), (y%2));
        y=y/2;
      }
      int s1 = vec1.size();
      while(x!=0)
      {
        vec2.insert(vec2.begin(), (x%2));
        x=x/2;
      }
      int s2 = vec2.size();
      if(s1>s2)
      {
        int s=s1-s2;
        for(int i=0; i<s; i++)
        {
          vec2.insert(vec2.begin(), 0);
        }
      }
      else
      {
        int s=s2-s1;
        for(int i=0; i<s; i++)
        {
          vec1.insert(vec1.begin(), 0);
        }
      }

      for(int i = vec1.size()-1; i>=0; i--)
        {
          if(vec1[i]!=vec2[i])
            {
              counter++;
            }
        }

  cout<<"Hamming Distance: "<<counter<<endl;
  return 0;
}
