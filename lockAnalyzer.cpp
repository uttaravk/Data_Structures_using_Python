// Lock Analyzer
#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

vector<string> lockAnalyzer(std::vector<string> &locks) {
  unordered_set<string> lockSet;
  stack<string> lockStack;
  vector<string> locksStatus;
  string lockType = "";
  string currStatus = "";
  for (int i = 0; i < locks.size(); i++) {
    int lockLength = locks[i].length();
    string processId = locks[i].substr(8, lockLength);
    string lockType = locks[i].substr(0, 7);
    switch (lockType[0]) {
    case 'A':
      if (!(lockSet.find(locks[i]) != lockSet.end())) {
        lockSet.insert(locks[i]);
        lockStack.push(locks[i]);
      } else {
        currStatus = "Lock is already acquired Process ID: " + processId;
        locksStatus.push_back(currStatus);
      }
      break;
    case 'R':
      string topLock = lockStack.top();
      string topLockTemp = "RELEASE " + topLock.substr(8, lockLength);
      if (locks[i] == (topLockTemp)) {
        lockStack.pop();
        lockSet.erase(topLock);
      } else {
        currStatus =
            "Lock cannot be release (not in seq) Process ID: " + processId;
        locksStatus.push_back(currStatus);
      }
      break;
    }
  }

  if (!lockStack.empty()) {
    currStatus = "Stack not empty. Number of Dangling Locks: " +
                 to_string(lockStack.size());
    locksStatus.push_back(currStatus);
  }
  return locksStatus;
}

int main() {
  vector<string> locks;
  locks = {"ACQUIRE 1", "RELEASE 1", "ACQUIRE 2", "RELEASE 2"};
  vector<string> locksStatus;
  locksStatus = lockAnalyzer(locks);
  for (int i = 0; i < locksStatus.size(); i++) {
    cout << locksStatus[i] << endl;
  }
  if (locksStatus.size() == 0) {
    cout << "No Dangling Locks, Operation Successful" << endl;
  }
  return 0;
}
