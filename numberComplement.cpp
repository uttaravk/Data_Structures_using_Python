/*
Given a positive integer, output its complement number. The complement
strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed
integer. You could assume no leading zero bit in the integer’s binary
representation. Example 1: Input: 5 Output: 2

Explanation: The binary representation of 5 is 101 (no leading zero bits),
and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits),
and its complement is 0. So you need to output 0.
*/

#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int findComplementMethod1(int num) {
  vector<int> binaryNum;
  while (num != 0) {
    if (num % 2 == 0) {
      binaryNum.insert(binaryNum.begin(), 1);
    } else if (num % 2 == 1) {
      binaryNum.insert(binaryNum.begin(), 0);
    }
    num = num / 2;
  }
  int index = binaryNum.size() - 1;
  int complmentNum = 0;
  for (int i = 0; i < binaryNum.size(); i++) {
    complmentNum = complmentNum + (binaryNum[i] * (pow(2, index)));
    index = index - 1;
  }
  return complmentNum;
}

int findComplementMethod2(int num) {
  int complmentNum = 0;
  int power = 1, numBck = num;
  if (num == 1) {
    return complmentNum;
  }
  while (num != 0) {
    num = num / 2;
    // generating power
    power = power * 2;
  }
  /// binary exor and converted into decimal
  complmentNum = numBck ^ (power - 1);
  return complmentNum;
}

int main() {
  int num = 9;
  cout << findComplementMethod1(num) << endl;
  cout << findComplementMethod2(num) << endl;
  return 0;
}
