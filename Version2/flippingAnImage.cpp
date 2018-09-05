// Flipping an Image (Ref.:
// https://leetcode.com/problems/flipping-an-image/description/) Given a binary
// matrix A, we want to flip the image horizontally, then invert it, and return
// the resulting image. To flip an image horizontally means that each row of the
// image is reversed.  For example, flipping [1, 1, 0] horizontally results in
// [0, 1, 1]. To invert an image means that each 0 is replaced by 1, and each 1
// is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].
//
// Input: [[1,1,0],[1,0,1],[0,0,0]]
// Output: [[1,0,0],[0,1,0],[1,1,1]]
// Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
// Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
#include <iostream>
#include <vector>
using namespace std;
int main() {
  vector<vector<int>> A;
  A = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
  int mysize = A.size();
  int temp = 0;
  int x = 0;
  for (int i = 0; i < mysize; i++) {
    temp = A[i].size();
    if (temp % 2 == 0) {
      x = temp / 2;
    } else {
      x = (temp / 2) + 1;
    }
    for (int j = 0; j < x; j++) {
      if (A[i][j] == A[i][temp - (j + 1)]) {
        if (A[i][j] == 0) {
          A[i][j] = 1;
          A[i][temp - (j + 1)] = 1;
        } else {
          A[i][j] = 0;
          A[i][temp - (j + 1)] = 0;
        }
      }
    }
  }

  for (int i = 0; i < mysize; i++) {
    temp = A[i].size();
    for (int j = 0; j < temp; j++) {
      cout << A[i][j];
    }
    cout << endl;
  }
  return 0;
}
