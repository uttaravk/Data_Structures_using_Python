/*
You are playing the following Nim Game with your friend: There is a heap of
stones on the table, each time one of you take turns to remove 1 to 3 stones.
The one who removes the last stone will be the winner. You will take the first
turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a
function to determine whether you can win the game given the number of stones in
the heap.

Example:

Input: 4
Output: false
Explanation: If there are 4 stones in the heap, then you will never win the
game; No matter 1, 2, or 3 stones you remove, the last stone will always be
             removed by your friend.
*/
#include <iostream>
using namespace std;
bool canWinNimMethod1(int n) {
  int q = n / 4;
  int result = n - (q * 4);
  if ((result == 1) || (result == 2) || (result == 3)) {
    return true;
  }
  return false;
}

bool canWinNimMethod2(int n) { return n % 4; }

int main() {
  int num = 7;
  if (canWinNimMethod1(num)) {
    cout << "You can win" << endl;
  } else {
    cout << "You cannot win" << endl;
  }
  if (canWinNimMethod2(num)) {
    cout << "You can win" << endl;
  } else {
    cout << "You cannot win" << endl;
  }
  return 0;
}
