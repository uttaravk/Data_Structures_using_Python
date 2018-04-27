//main.cpp

#include <iostream>
using namespace std;

#include<cstring>
#include "argParser.h"
#include "argParser.cc"

int main(int argc, char **argv)
{
    int argc1;
    char **argv1;
    argc1=argc;
    argv1=argv;  
    //argParser.parse(argv1,argc1);  
    argParser->parse(argv1,argc1);
    argParser->printArgs();
    //argParser.printArgs();
    return 0;
}
