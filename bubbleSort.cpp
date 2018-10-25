// Program to implement Bubble Sort using C++

#include <iostream>
#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> &vec) {
  int temp;
  int j = 0;
  for (int i = 0; i < vec.size(); i++) {
    j = 0;
    while (j < vec.size() - 1) {
      if (vec[j] > vec[j + 1]) {
        temp = vec[j];
        vec[j] = vec[j + 1];
        vec[j + 1] = temp;
      }
      j++;
    }
  }
  return vec;
}

int main() {
  vector<int> vec;
  vector<int> sortedVec;
  vec = {2, 5, 3, 8, 10, 0};
  sortedVec = bubbleSort(vec);
  for (int i = 0; i < sortedVec.size(); i++) {
    cout << sortedVec[i] << " ";
  }
  cout << endl;
  return 0;
}
