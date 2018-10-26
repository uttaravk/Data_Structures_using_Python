/*
A self-dividing number is a number that is divisible by every digit it contains.

For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0,
and 128 % 8 == 0.

Also, a self-dividing number is not allowed to contain the digit zero.

Given a lower and upper number bound, output a list of every possible self
dividing number, including the bounds if possible.

Example 1:
Input:
left = 1, right = 22
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
Note:

The boundaries of each input argument are 1 <= left <= right <= 10000.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> selfDividingNumbers(const int left, const int right) {
  vector<int> nums;
  int num = 0;
  int rem = 0;
  for (int i = left; i <= right; i++) {
    num = i;
    rem = 0;
    while (num != 0) {
      rem = num % 10;
      if (rem != 0) {
        if ((i % rem) != 0) {
          rem = 1;
          break;
        }
        rem = 0;
        num = num / 10;
      } else {
        rem = 1;
        break;
      }
    }
    if (rem == 0) {
      nums.push_back(i);
    }
  }
  return nums;
}

int main() {
  int left = 1;
  int right = 22;
  vector<int> nums;
  nums = selfDividingNumbers(left, right);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
  return 0;
}
