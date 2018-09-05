// Given a list of non negative integers, arrange them such that they form the
// largest number.
//
// Example 1:
//
// Input: [10,2]
// Output: "210"
// Example 2:
//
// Input: [3,30,34,5,9]
// Output: "9534330"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string largestNumber(vector<int> &myvec) {
  cout << "input" << endl;
  for (int i = 0; i < myvec.size(); i++) {
    char c = to_string(myvec[i])[0];
    cout << c << " ";
  }
  return "hello";
}

int main() {
  vector<int> myvec;
  myvec = {3, 30, 34, 5, 9};

  string res = largestNumber(myvec);
  cout << res << endl;

  return 0;
}
