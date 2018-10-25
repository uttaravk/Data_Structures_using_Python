// main.cpp : argumentParser

#include <iostream>
using namespace std;

#include "argumentParser.cpp"
#include "argumentParser.h"
#include <cstring>

int main(int argc, char **argv) {
  int argc1;
  char **argv1;
  argc1 = argc;
  argv1 = argv;
  argParser->parse(argv1, argc1);
  argParser->printArgs();
  return 0;
}
