/*
Given two integers dividend and divisor, divide two integers without using
multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:
Input: dividend = 10, divisor = 3
Output: 3

Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within
the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this
problem, assume that your function returns 231 − 1 when the division result
overflows.
*/
#include <cstdlib>
#include <iostream>
using namespace std;

int divide(int dividend, int divisor) {
  long long int tempQuotient = 0;
  long long int absDividend = llabs(dividend);
  long long int absDivisor = llabs(divisor);
  int quotient = 0;

  if (dividend == divisor) {
    return 1;
  } else if (divisor == 1) {
    return dividend;
  } else if (divisor == -1) {
    tempQuotient = absDividend;
  } else {
    while (absDividend >= absDivisor) {
      absDividend = absDividend - absDivisor;
      tempQuotient++;
    }
  }

  if (tempQuotient <= INT_MIN || tempQuotient >= INT_MAX) {
    return 2147483647;
  } else {
    quotient = int(tempQuotient);
  }
  if (dividend < 0 ^ divisor < 0) {
    quotient = quotient - (quotient + quotient);
  }
  return quotient;
}

int main() {
  int dividend = -6;
  int divisor = -3;
  int quotient = divide(dividend, divisor);
  cout << quotient << endl;
}
