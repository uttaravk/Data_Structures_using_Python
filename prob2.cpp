/**
   Computes the average of all odd elements in the given array.
   @param a an array of integers
   @param alen the number of elements in a
   @return the average of all odd elements in a, or 0 if there are none.
*/
double oddavg(int a[30], int alen)
{
 double sum=0.0;
 double avg=0.0; 
 int count=0;
 for(int i=0; i<alen; i++)
 {
  if((a[i]%2)!=0)
  {
    sum = sum + a[i];
    count=count+1;
  }
 }
 
 if(count==0)
 {
    return 0;
 }
 else 
 {
 avg=(sum/count);
 return avg;
 }
}
