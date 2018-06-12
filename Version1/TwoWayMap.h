
#include <iostream>
using namespace std;

#include <map> 
#include <cstring>


#ifndef TWOWAYMAP_H
#define TWOWAYMAP_H

class TwoWayMap
{
  public:
	bool setMapEntry(string a,int b);
	bool setMapEntry(int a,string b);
	string getMapValue(int a);
	int getMapValue(string a);
	TwoWayMap();

  private:
	int myint;
	string mystring;
};

#endif

