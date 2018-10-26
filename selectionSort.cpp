// Implementing Selection Sort

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &nums) {
  int temp = 0;
  int j = 0;
  for (int i = 0; i < nums.size(); i++) {
    j = 0;
    while (j < nums.size()) {
      if (nums[i] < nums[j]) {
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
      j++;
    }
  }
}

int main() {
  std::vector<int> nums{2, 5, 3, 8, 10, 0};
  selectionSort(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
  return 0;
}
