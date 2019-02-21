// Implementing Selection Sort

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &nums) {
  int temp = 0;
  int j = 0;
  int pos = 0;
  for (int i = 0; i < nums.size(); i++) {
    j = i + 1;
    pos = i;
    while (j < nums.size()) {
      if (nums[pos] > nums[j]) {
        pos = j;
      }
      j++;
    }
    temp = nums[pos];
    nums[pos] = nums[i];
    nums[i] = temp;
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
