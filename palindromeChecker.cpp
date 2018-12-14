#include <iostream>
using namespace std;

// Case Sensitive Palindrome checker
bool checkPalindromeCS(string inputStr) {
  int strLen = inputStr.length();
  if (strLen == 0) {
    return true;
  }
  for (int i = 0; i < strLen / 2; i++) {
    if (inputStr[i] != inputStr[(strLen - 1) - i]) {
      return false;
    }
  }
  return true;
}

// Case Insensitive Palindrome checker
bool checkPalindromeCIS(string inputStr) {
  int strLen = inputStr.length();
  if (strLen == 0) {
    return true;
  }
  for (int i = 0; i < strLen / 2; i++) {
    if (toupper(inputStr[i]) != toupper(inputStr[(strLen - 1) - i])) {
      return false;
    }
  }
  return true;
}

int main() {
  cout << checkPalindromeCS("Level") << endl;
  cout << checkPalindromeCIS("levex") << endl;
  return 0;
}
