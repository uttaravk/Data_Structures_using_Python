/**
   This program reads in the name of a file from stdin.
   Then it opens the file and reads all lines of the file.
   Each line has the form 

   label     value

   The label is a nonempty string without spaces. The value
   is a floating-point number. 

   Print out the label with the smallest and largest value, 
   in a left-justified, field of width 50, followed by the value
   in a right-justified field of width 12, with two digits after
   the decimal point.
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
   cout << "Input file:" << endl;
   double myfloat=0.0; 
   string mystring="NULL";
   string input_file;
   cin>>input_file;
   double tempmax=0.0;
   double tempmin=0.0;
 
  ifstream in(input_file);
 
  while(in>>mystring>>myfloat)
  {
 
 	 if(tempmax<myfloat)
         {
    		tempmax=myfloat;
  	 } 
  }
  tempmin=tempmax;
  in.close();
  in.open(input_file);
  while(in>>mystring>>myfloat)
  {
  
 	 if(tempmin>myfloat)
         {
    		tempmin=myfloat;
  	 } 
  }
  in.close();
  in.open(input_file);
  
  while(in>>mystring>>myfloat)
  {
 	 if(myfloat==tempmin)
         {        
    		cout<<std::left<<setw(50)<<mystring;
                cout<<std::right<<setw(12)<<std::fixed<<std::showpoint<<setprecision(2)<<myfloat<<endl;
  	 } 
  }
   	
  in.close();
in.open(input_file);
  
  while(in>>mystring>>myfloat)
  {
 	 if(myfloat==tempmax)
         {        
    		cout<<std::left<<setw(50)<<mystring;
                cout<<std::right<<setw(12)<<std::fixed<<std::showpoint<<setprecision(2)<<myfloat<<endl;
  	 } 
  }
   	
  in.close();
  return 0;
}
