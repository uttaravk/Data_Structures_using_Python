// Implementing Shell Sort

#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int> &nums) {
  int temp = 0;
  int n = nums.size() / 2;
  while (n != 0) {
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j <= (nums.size() / 2); j++) {
        if (nums[j] > nums[j + n]) {
          temp = nums[j];
          nums[j] = nums[j + n];
          nums[j + n] = temp;
        }
      }
    }
    n = n / 2;
  }
}

int main() {
  vector<int> nums{12, 4, 54, 2, 3};
  shellSort(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
  return 0;
}
