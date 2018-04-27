#include <vector>
using namespace std;

/**
   Replaces each element in an array with the difference of its
   neighbors. The first and last element are not changed. Do 
   not declare any arrays or vectors.
   @param a an array
   @param n the length of the array
*/
void neighbordiff(double a[], int n)
{
   int temp;
   int temp2;
   int tempx1=a[0]; 	
   for(int i=1; i<n-1; i++)
   {
    temp=tempx1;  
    temp2=a[i]; 
    a[i]=temp-a[i+1];    
    tempx1=temp2;	
   }
}      

