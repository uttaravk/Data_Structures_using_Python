#include <string>
using namespace std;

/**
   Return a string that mixes the characters in strings a and b.
   If one string is longer than the other, append the suffix.
   For example, mixing "San" and "Francisco" yields "SFarnancisco".
*/
string mix(string a, string b)
{
   char arr[50]={};
   int alen = a.length();
   int blen = b.length();
   int flen=0;
   int f1; 
   if(alen<blen)
   {
    flen=alen;
    f1=blen;
   } 
   else
   {
    flen=blen;
    f1=alen;
   } 
   int it=flen*2;
   int i1;
   int j=0;
   for(i1=0; i1<it; i1++)
   {
     arr[i1]=a[j];
     arr[i1+1]=b[j];
     i1=i1+1;
     j=j+1;
   }

   string finalstring;  
   char arr2[20]={}; 
   for(int i=0; i<(f1+flen); i++)
   {
	if(alen>blen)
	{
         arr2[i]=a[i+flen];
	}
	else
	{
  	 arr2[i]=b[i+flen];
	}
   }
   string arr_1=arr;
   string arr_2=arr2;
   finalstring = arr_1 + arr_2;
   return finalstring;
}

