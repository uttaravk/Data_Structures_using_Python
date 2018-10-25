/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:

Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/

#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums) {
  int result = 0;
  int count = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == 1) {
      count++;
    } else {
      count = 0;
    }
    if (result < count) {
      result = count;
    }
  }
  return result;
}

int main() {
  vector<int> nums;
  nums = {1, 1, 0, 1, 1, 1};
  cout << findMaxConsecutiveOnes(nums) << endl;
  return 0;
}
