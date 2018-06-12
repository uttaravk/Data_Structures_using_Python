#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// vector<int> array_left_rotation(vector<int> a, int n, int k)
// {
//   int temp;
//   for(int i=1; i<=k; i++)
//   {
//     temp=a[0];
//     for(int i=1; i<n; i++)
//     {
//       a[i-1]=a[i];
//     }
//     a[n-1]=temp;
//   }
//   return a;
// }

vector<int> array_left_rotation(vector<int> a, int n, int k)
{
  vector<int> myvec;
  myvec.resize(k);
  for(int i=0; i<k; i++)
  {
    myvec[i]=a[0];
    a.erase(a.begin());
  }
  for(int i=0; i<k; i++)
  {
    a.push_back(myvec[i]);
  }
return a;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotation(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}
