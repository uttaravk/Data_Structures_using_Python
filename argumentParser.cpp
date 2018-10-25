// cpp file - argumentParser

#include <iostream>
using namespace std;

#include "argumentParser.h"
#include <cstring>

cmdline *argParser = new cmdline();
cmdline ::cmdline() { setArgs(NULL, 0); }

void cmdline ::setArgs(char **argv, int argc) {
  myargc = argc;
  myargv = argv;
}

void cmdline ::sortArgs() {

  int y;
  int argc1;
  char **argv1;
  char *temp;

  argc1 = myargc;
  argv1 = myargv;

  for (int i = 0; i < argc1 - 1; i++) {
    for (int j = 1; j < argc1; j++) {
      y = strcmp(argv1[j - 1], argv1[j]);
      if (y > 0) {
        temp = argv1[j - 1];
        argv1[j - 1] = argv1[j];
        argv1[j] = temp;
      }
    }
  }
  myargc = argc1;
  myargv = argv1;
}

void cmdline ::parse(char **argv, int argc) {
  int argc1;
  char **argv1;
  argc1 = argc;
  argv1 = argv;
  setArgs(argv1, argc1);
  sortArgs();
}

void cmdline ::printArgs() {
  for (int i = 1; i < myargc; i++) {
    cout << myargv[i] << " ";
  }
  cout << endl;
}

cmdline ::~cmdline() { delete argParser; };
