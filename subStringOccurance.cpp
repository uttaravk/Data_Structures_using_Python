/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle
is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Solution using substring technique
int strStr(string haystack, string needle) {
  int needleLength = needle.length();
  int hayLength = haystack.length();
  if (needleLength == 0) {
    return 0;
  }

  string tempString = "";
  for (int i = 0; i < hayLength; i++) {
    tempString = haystack.substr(i, needleLength);
    if (needle == tempString) {
      return i;
    }
  }

  return -1;
}

// Function Call
int main() {
  string haystack = "hello";
  string needle = "ll";
  int occurrence = strStr(haystack, needle);
  cout << occurrence << endl;
  return 0;
}
