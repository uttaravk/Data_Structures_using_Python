/*
You're given strings J representing the types of stones that are jewels, and S
representing the stones you have.  Each character in S is a type of stone you
have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are
letters. Letters are case sensitive, so "a" is considered a different type of
stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.
*/

#include <iostream>
#include <set>
using namespace std;

// Function to calculate number of jewels
int numJewelsInStones(string J, string S) {
  set<char> charSet;
  int jLength = J.length();
  int sLength = S.length();
  int count = 0;
  for (int i = 0; i < jLength; i++) {
    charSet.insert(J[i]);
  }
  for (int i = 0; i < sLength; i++) {
    if (charSet.find(S[i]) != charSet.end()) {
      count = count + 1;
    }
  }
  return count;
}

// Function Call
int main() {
  cout << numJewelsInStones("aA", "aAAbbbb") << endl;
  return 0;
}
