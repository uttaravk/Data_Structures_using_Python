#include <iostream>
#include <cstring>
using namespace std;

class mydarray
{
  int arr[2];
  Public:
	mydarray
	{	const int isize=10;
		arr=new int[isize];
	}
	int operator[]::(int myindex) const
	{
		return arr[index];
	}
	operator=::(const mydarray &d)
	{
		arr=d.arr;   //da1=da;  da1-this da-argument 
	}
	~mydarray
	{
		delete []arr;
	}

	friend operator << :: (ostream &mf, const mydarray& dy)
	{
		for(int i=0; i<dy.isize(); i++)
		{
			mf<<dy.arr[i];
		}

	}
};

int main()
{

	mydarray da1;
	mydarray da;
	da1=da;

return 0;
}
