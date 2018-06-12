#include <iostream>
#include <list>
using namespace std;


list<vector<int>> drawCircle(int n)
{
  list<vector<int>> mylist;
  if (n <= 0)
  {
      return mylist;
  }
  int r = n * n;
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i * i + j * j <= r)
      {
        if (i == 0 && j == 0)
        {
          mylist.push_back(vec[0]=0);
        }
        else if (i == 0)
        {
          mylist.push_back(v[i]=j});
          mylist.push_back(v[i]=-j});
        }
        else if (j == 0)
        {
          mylist.push_back({i, j});
          mylist.push_back({-i, j});
        }
        else
        {
          mylist.push_back({i, j});
          mylist.push_back({i, -j});
          mylist.push_back({-i, j});
          mylist.push_back({-i, -j});
        }
      }
    }
  }
  return mylist;
}

int main()
{
  list<vector<int>> mylist;
  int r=2;
  mylist=drawCircle(r);
  for(int i=0; i<15; i++)
  {
    cout<<mylist[i]<<endl;
  }
  return 0;
}
