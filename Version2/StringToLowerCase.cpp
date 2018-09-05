#include <iostream>
#include <string>
using namespace std;
string toLowerCase(string str) {

  for (int i = 0; i < str.length(); i++) {
    if (int(str[i]) >= 65 && int(str[i]) <= 90) {
      str[i] = char(int(str[i]) + 32);
    }
  }
  return str;
}

int main() {
  string inputString = "Hello";
  string outputString = toLowerCase(inputString);
  cout << outputString << endl;
}
