// Simple Palindrome Integer Checker

#include <iostream>
using namespace std;

// O(n) Solution
bool checkPalindromeMethod1(int num) {
  string testNumber = to_string(num);
  if (testNumber[0] == '-') {
    testNumber.erase(testNumber.begin());
  }
  for (int i = 0; i < testNumber.length(); i++) {
    if (testNumber[i] != testNumber[(testNumber.length() - (i + 1))]) {
      return false;
    }
  }
  return true;
}

// O(1) Solution
bool checkPalindromeMethod2(int num) {
  string testNumber = to_string(num);
  if (testNumber[0] == '-') {
    testNumber.erase(testNumber.begin());
  }
  int strLength = testNumber.length() / 2;
  string part1 = testNumber.substr(0, (strLength / 2) + 1);
  string part2 = testNumber.substr((strLength / 2) + 1);
  std::reverse(part2.begin(), part2.end());
  if (testNumber.length() % 2 != 0) {
    part2.erase(part2.end() - 1);
  }
  if (part1 == part2) {
    return true;
  }
  return false;
}

int main() {
  int num = -121;
  if (checkPalindromeMethod1(num)) {
    cout << "Test Number is a Palindrome Number" << endl;
  } else {
    cout << "Test Number is not a Palindrome Number" << endl;
  }
  if (checkPalindromeMethod2(num)) {
    cout << "Test Number is a Palindrome Number" << endl;
  } else {
    cout << "Test Number is not a Palindrome Number" << endl;
  }
}
