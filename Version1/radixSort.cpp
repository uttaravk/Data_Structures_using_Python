#include <iostream>
#include <vector>
using namespace std;

void myradix(vector <int> &vec, int y)
{
  int x;
  vector <int> res;
  res.resize(vec.size());
  int c[10]={0};
  for(int i=0; i<vec.size(); i++)
  {
    x=(vec[i]/y)%10;
    c[x]++;
  }
  for(int i=1; i<10; i++)
  {
    c[i]=c[i]+c[i-1];
  }
  for(int i=(vec.size()-1); i>=0; i--)
  {
    x=(vec[i]/y)%10;
    res[c[x]-1]=vec[i];
    c[x]=c[x]-1;
  }
  for(int i=0; i<vec.size(); i++)
  {
    vec[i]=res[i];
  }
}

int main()
{
  vector <int> vec;
  vec={9,179,139,38,10,5,36};
  int n=1;
  int maxval=0;
  int numdigit=0;

  cout<<"Input: "<<endl;
  for(int i=0; i<vec.size(); i++)
  {
    cout<<vec[i]<<" ";
  }
  cout<<endl;
  for(int i=0; i<vec.size(); i++)
  {
    if(vec[i]>maxval)
    {
      maxval=vec[i];
    }
  }
  while(maxval!=0)
  {
    numdigit++;
    maxval=maxval/10;
  }
  for(int i=0; i<=numdigit; i++)
  {
    myradix(vec, n);
    n=n*10;
  }
  cout<<"Output: "<<endl;
  for(int i=0; i<vec.size(); i++)
  {
    cout<<vec[i]<<" ";
  }
    cout<<endl;
    return 0;
}
