//header file - cmdline_header

#include <iostream>
using namespace std;

#include <cstring>


#ifndef CMDLINE_H
#define CMDLINE_H

class cmdline
{
    public:
           void parse(char **argv, int argc);
           void printArgs();
           void setArgs(char **argv, int argc);
	   //cmdline(char **argv, int argc); 
           cmdline();
           ~cmdline();
     
    private:     
            char **myargv;
            int myargc;
            void sortArgs();
};

#endif

