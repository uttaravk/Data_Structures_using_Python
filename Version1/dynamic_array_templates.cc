#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class mydarray
{
  T *arr; 
  int isize;
  Public:
	mydarray()
	{	const int isize=10;
		arr=new int[isize];
	}
	T operator[]::(const int myindex)
	{
		return arr[index];
	}
	mydarray operator=::(const mydarray &d)
	{
		this->arr=d.arr;   //da1=da;  da1-this da-argument 
		return this;
	}
	~mydarray
	{
		delete []arr;
	}

	
};

int main()
{
	mydarray <int> da1;
	typedef mydarray <int> da;
	da1=da;

return 0;
}
