/*
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for
the multiples of five output “Buzz”. For numbers which are multiples of both
three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]

*/
#include <iostream>
#include <vector>
using namespace std;

vector<string> fizzBuzz(const int &n) {
  vector<string> fizzBuzzStrs;
  for (int i = 1; i <= n; i++) {
    if (i % 3 == 0) {
      if (i % 5 == 0) {
        fizzBuzzStrs.push_back("FizzBuzz");
      } else {
        fizzBuzzStrs.push_back("Fizz");
      }
    } else if (i % 5 == 0) {
      fizzBuzzStrs.push_back("Buzz");
    } else {
      fizzBuzzStrs.push_back(to_string(i));
    }
  }
  return fizzBuzzStrs;
}

int main() {
  int n = 15;
  vector<string> fizzBuzzStrs;
  fizzBuzzStrs = fizzBuzz(n);
  for (int i = 0; i < fizzBuzzStrs.size(); i++) {
    cout << fizzBuzzStrs[i] << endl;
  }
  return 0;
}
