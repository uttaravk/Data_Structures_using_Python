/*
Write a function to find the longest common prefix string amongst an array of
strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs) {
  string longestPrefix = "";
  int minLength = strs[0].length();
  string smallestString = "";
  int previousLength = 0;

  // Finding smallest string and its length from an array of strings
  for (int i = 1; i < strs.size(); i++) {
    previousLength = minLength;
    minLength = std::min<int>(minLength, strs[i].length());
    if (previousLength != minLength) {
      smallestString.resize(minLength);
      smallestString = strs[i];
    }
  }

  // Finding longest prefix string
  int flag = 1;
  for (int i = 0; i < minLength; i++) {
    for (int j = 0; j < strs.size(); j++) {
      if (strs[j][i] != smallestString[i]) {
        flag = 0;
        break;
      }
    }
    if (flag == 1) {
      longestPrefix.push_back(smallestString[i]);
    }
    flag = 1;
  }
  return longestPrefix;
}

// Function call
int main() {
  vector<string> strs = {"flower", "flow", "flight"};
  string longestPrefix = longestCommonPrefix(strs);
  cout << "Longest Prefix: " << longestPrefix << endl;
  return 0;
}
