//cc file - cmdline_cpp 

#include <iostream>
using namespace std;

#include<cstring>
#include "argParser.h"

/*cmdline argParser(NULL, 0);

cmdline :: cmdline(char **argv, int argc)
{
    int argc1=argc;
    char **argv1=argv;
    setArgs(argv1, argc1);
}*/

 

cmdline * argParser = new cmdline();
//cmdline argParser;	
cmdline :: cmdline()
{
 setArgs(NULL,0);
}

void cmdline :: setArgs(char **argv, int argc)
{
    myargc=argc;
    myargv=argv;
   
}
     
void cmdline :: sortArgs()
{

  int y;
  int argc1;
  char ** argv1;
 // string temp;	
  char* temp;
  
  argc1=myargc;
  argv1=myargv;
  
  for(int i=0; i<argc1-1; i++)
  {
   for(int j=1; j<argc1; j++)
   {
     y = strcmp(argv1[j-1], argv1[j]);
	//cout<<y<<endl;
     if(y>0)
     {
	temp = argv1[j-1];
	//cout<<"temp(before)"<<temp<<endl;
	argv1[j-1] = argv1[j];
	//cout<<"argv1: "<<argv1<<endl;
	argv1[j] = temp;
	//cout<<"temp(after)"<<temp<<endl;
     }		
   }		
 }
	myargc=argc1;
	myargv=argv1;

    /*cout<<"Sorted Array(myargv): "<<endl;
    for(int i=1; i<argc1; i++)
    {
        cout<<myargv[i]<<endl;
    }*/

    /*cout<<"Sorted Array(argv1): "<<endl;
    for(int i=1; i<argc1; i++)
    {
        cout<<argv1[i]<<endl;
    }*/
} 
/*string strarr[50]={};
    string temp;
    string a,b;
    for(int i=1; i<argc; i++)
    {
        strarr[i-1]=argv[i];
    }
    int i, j;
    int count=1;
    for(i=1; i<argc-1; i++)
    { 
        for(j=i; j<argc-1; j++)
        {
           a=argv[i];
           b=strarr[j];
           if((int)a[0]>(int)b[0])
           {
               temp=strarr[j];
               strarr[j]=(string)argv[i];
               argv[i]=const_cast<char*>(temp.c_str());
               int x=i+count;
               argv[x]=const_cast<char*>(strarr[j].c_str());
               count++;
           }
           else if((int)a[0]==(int)b[0])
           {
               if((int)a[1]>(int)b[1])
               {
                    temp=strarr[j];
                    strarr[j]=(string)argv[i];
                    argv[i]=const_cast<char*>(temp.c_str());
                    int x=i+count;
                    argv[x]=const_cast<char*>(strarr[j].c_str());
                    count++;
               }
               
           }
           else
           {
               count++;
           }
            
        }
        count=0;
   }
  
    cout<<"Sorted Array: "<<endl;
    for(int i=1; i<argc; i++)
    {
        cout<<argv[i]<<endl;
    }
}*/
 
void cmdline :: parse(char **argv, int argc)
{
    int argc1;
    char **argv1;
    argc1=argc;
    argv1=argv;
    setArgs(argv1, argc1); 
    sortArgs();
 
}


void cmdline :: printArgs()
{
    for(int i=1; i<myargc; i++)
    {
        cout<<myargv[i]<<" ";
    }
    cout<<endl;
}

cmdline :: ~ cmdline()
{
  //cout<<"Destructor is called"<<endl;
  delete argParser;
};
