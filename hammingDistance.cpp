/*
The Hamming distance between two integers is the number of positions at which
the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.

*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to convert decimal integer to binary using vector
vector<int> decimalToBinary(int num) {
  vector<int> bits;
  while (num != 0) {
    bits.insert(bits.begin(), (num % 2));
    num = num / 2;
  }
  return bits;
}

// Function to calculate hamming distance
int hammingDistance(int &x, int &y) {
  int counter = 0;
  vector<int> xbits;
  vector<int> ybits;

  // Convert decimal integers to binary
  xbits = decimalToBinary(x);
  ybits = decimalToBinary(y);
  int resizeFactor = 0;

  // Resize the vectors
  if (xbits.size() > ybits.size()) {
    resizeFactor = (xbits.size() - ybits.size());
    for (int i = 0; i < resizeFactor; i++) {
      ybits.insert(ybits.begin(), 0);
    }
  } else {
    resizeFactor = (ybits.size() - xbits.size());
    for (int i = 0; i < resizeFactor; i++) {
      xbits.insert(xbits.begin(), 0);
    }
  }

  // Calculate Hamming Distance
  for (int i = 0; i < xbits.size(); i++) {
    if (xbits[i] ^ ybits[i]) {
      counter++;
    }
  }
  return counter;
}

// Function Calls
int main() {
  int x = 1;
  int y = 4;
  cout << "Distance: " << hammingDistance(x, y) << endl;
  return 0;
}
