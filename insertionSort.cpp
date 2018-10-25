// Implementing Insertion Sort in C++

#include <iostream>
#include <vector>
using namespace std;

// Function to sort the array of numbers using insertion sort
void insertionSort(vector<int> &nums) {
  int temp;
  int j = 0;
  for (int i = 1; i < nums.size(); i++) {
    j = 0;
    while (j <= i) {
      if (nums[i] < nums[j]) {
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
      }
      j++;
    }
  }
}

// Function Call
int main() {
  vector<int> nums;
  nums = {2, 5, 3, 8, 10, 0};
  insertionSort(nums);
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
  return 0;
}
