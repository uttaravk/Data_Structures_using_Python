/*
We are given two strings, A and B.

A shift on A consists of taking string A and moving the leftmost character to
the rightmost position. For example, if A = 'abcde', then it will be 'bcdea'
after one shift on A. Return True if and only if A can become B after some
number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false
Note:

A and B will have length at most 100.
*/
#include <iostream>
#include <string>
using namespace std;

bool rotateString(string A, string B) {
  int aLen = A.length();
  int bLen = B.length();
  int pos = 0;
  if (aLen != bLen) {
    return 0;
  }
  for (int i = 0; i < aLen; i++) {
    if (A[i] == B[0]) {
      pos = i;
      string temp1 = A.substr(0, pos);
      string temp2 = A.substr(pos + 1, aLen);
      string result = B[0] + temp2 + temp1;
      if (result == B) {
        return 1;
      }
    }
  }
  return 0;
}

int main() {
  cout << rotateString("abcde", "cdeab") << endl;
  return 0;
}
