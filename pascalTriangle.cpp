/*Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

vector<vector<int>> generate(int numRows) {

}*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
  int rows = numRows;
  int columns = rows + (rows - 1);

  // Initialising 2D vector representing a pascal triangle
  std::vector<std::vector<int>> pascalTriangle(rows);
  pascalTriangle[0].resize(columns);
  for (int i = 0; i < columns; i++) {
    if (i == columns / 2) {
      pascalTriangle[0][i] = 1;
    } else {
      pascalTriangle[0][i] = 0;
    }
  }
  for (int i = 1; i < rows; i++) {
    pascalTriangle[i].resize(columns);
    for (int j = 1; j < columns; j++) {
      pascalTriangle[i][j] =
          pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j + 1];
    }
  }
  return pascalTriangle;
}

int main() {
  int numRows = 5;
  int rows = numRows;
  int columns = rows + (rows - 1);
  vector<vector<int>> pascalTriangle;
  pascalTriangle = generate(numRows);
  pascalTriangle[rows - 1][0] = 1;
  for (int i = 0; i < rows; i++) {
    cout << "[ ";
    for (int j = 0; j < columns; j++) {
      if (pascalTriangle[i][j] == 0) {
        cout << " ";
      } else {
        cout << pascalTriangle[i][j] << " ";
      }
    }
    cout << "]" << endl;
  }
  return 0;
}
