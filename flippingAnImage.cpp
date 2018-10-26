/*
Given a binary matrix image, we want to flip the image horizontally, then invert
it, and return the resulting image. To flip an image horizontally means that
each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally
results in [0, 1, 1]. To invert an image means that each 0 is replaced by 1, and
each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
*/

#include <iostream>
#include <vector>
using namespace std;

void flipImage(vector<vector<int>> &image) {
  int imgSize = image.size();
  int rowSize = 0;
  int limit = 0;
  for (int i = 0; i < imgSize; i++) {
    rowSize = image[i].size();
    if (rowSize % 2 == 0) {
      limit = rowSize / 2;
    } else {
      limit = (rowSize / 2) + 1;
    }
    for (int j = 0; j < limit; j++) {
      if (image[i][j] == image[i][rowSize - (j + 1)]) {
        if (image[i][j] == 0) {
          image[i][j] = 1;
          image[i][rowSize - (j + 1)] = 1;
        } else {
          image[i][j] = 0;
          image[i][rowSize - (j + 1)] = 0;
        }
      }
    }
  }
}

int main() {
  vector<vector<int>> image;
  image = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
  flipImage(image);
  int imgSize = image.size();
  int rowSize = 0;
  for (int i = 0; i < imgSize; i++) {
    rowSize = image[i].size();
    for (int j = 0; j < rowSize; j++) {
      cout << image[i][j];
    }
    cout << endl;
  }
  return 0;
}
