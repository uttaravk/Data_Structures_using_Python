// Implement two way map
#include "twoWayMap.h"
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> stringtoint;
map<int, string> inttostring;

TwoWayMap ::TwoWayMap() {
  setMapEntry("Default", 0);
  setMapEntry(0, "Default");
}

bool TwoWayMap ::setMapEntry(string a, int b) {
  mystring = a;
  myint = b;
  bool x1 = true;
  if (stringtoint.find(mystring)->second != 0) {
    x1 = true;

  } else {
    x1 = false;
  }

  if (mystring == inttostring[myint]) {
    inttostring[myint] = "NULL";
    stringtoint[mystring] = myint;
  } else {
    stringtoint[mystring] = myint;
    inttostring[myint] = mystring;
  }

  return x1;
}

bool TwoWayMap ::setMapEntry(int a, string b) {
  myint = a;
  mystring = b;
  bool x1 = true;

  if (inttostring.find(myint)->second != "NULL") {
    x1 = true;

  } else {
    x1 = false;
  }

  if (myint == stringtoint[mystring]) {
    stringtoint[mystring] = 0;
    inttostring[myint] = mystring;
  } else {
    inttostring[myint] = mystring;
    stringtoint[mystring] = myint;
  }

  return x1;
}

string TwoWayMap ::getMapValue(int a) {
  int x;
  x = a;
  if (stringtoint.find(mystring)->second == x) {
    if (inttostring[x] != "NULL") {
      return inttostring[x];
    }
  } else {
    inttostring[x] = "NULL";
    return inttostring[x];
  }
}

int TwoWayMap ::getMapValue(string a) {
  string x = "NULL";
  x = a;
  int y = 0;
  if (inttostring.find(myint)->second == x) {
    if (stringtoint[x]) {
      y = (int)(stringtoint[x]);
      return y;
    }
  } else {
    stringtoint[x] = 0;
    return stringtoint[x];
  }
}
