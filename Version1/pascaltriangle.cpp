/*Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

vector<vector<int>> generate(int numRows) {

}*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int x=5;
  vector <int> vec={0};
  int RR=x; int CC=RR+(RR-1);
  std::vector<std::vector<int>> fvec(RR, std::vector<int>(0));
  fvec[0].resize(CC);
  for(int i=0; i<CC; i++)
  {
    if(i==CC/2)
    {
      fvec[0][i]=1;
    }
    else
    {
      fvec[0][i]=0;
    }

  }
  for (int i = 1 ; i < RR ; i++)
  {
    fvec[i].resize(CC);
    for(int j=1; j<CC; j++)
    {
        fvec[i][j]=fvec[i-1][j-1]+fvec[i-1][j+1];
    }
  }
  fvec[RR-1][0]=1;
  for (int i = 0 ; i < RR ; i++)
  {
    cout<<"[ ";
    for(int j=0; j<CC; j++)
    {
      if(fvec[i][j]==0)
      {
        cout<<" ";
      }
      else
      {
        cout<<fvec[i][j]<<" ";
      }
    }
    cout<<"]"<<endl;
  }
  return 0;
}
