#include <vector>
using namespace std;

/**
   Swaps the second and second-to-last value of a.
   For example, if a is {3, 1, 4, 1, 5, 9, 2, 6}
   after calling this method it is {3, 2, 4, 1, 5, 9, 1, 6}.
   If the array has length < 2, do nothing.
   @param a a vector of integers      
*/
void swap2(vector<int>& a)
{
   
   int x;
   x=a.size();
   if(x<2)
   {
   } 
   else
   {
	   int temp;
	   temp=a[1];
	   for(int i=0; i<x; i++)
	   {
	    if(i==(x-2))
	    { 
	    a[1]=a[i];
	    a[i]=temp;
	    }
	   } 
   }   
}
