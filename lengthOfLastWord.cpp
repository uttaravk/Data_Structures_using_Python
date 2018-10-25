/*
Given a string s consists of upper/lower-case alphabets and empty space
characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters
only.

Example:

Input: "Hello World"
Output: 5
*/
#include <iostream>
using namespace std;

int lengthOfLastWord(string s) {
  int lenCounter = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] != ' ') {
      lenCounter++;
    } else if (lenCounter != 0) {
      return lenCounter;
    }
  }
  return lenCounter;
}

int main() {
  string s = "a";
  cout << "Length of Last Word: " << lengthOfLastWord(s) << endl;
  return 0;
}
