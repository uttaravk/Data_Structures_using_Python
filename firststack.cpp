#include<iostream>
#include<stack>
#include<list>
using namespace std;
int main()
{
  list<int> mylist1;
  stack<int> mystack;

  list<int> mylist2;
  list<int> :: iterator it;
  mylist1.insert(mylist1.begin(), 3);
  mylist1.insert(mylist1.begin(), 4);
  mylist1.insert(mylist1.begin(), 2);
  for(it=mylist1.begin(); it!=mylist1.end(); it++)
  {
    mystack.push(*it);
  }
  while(!mystack.empty())
  {
    cout<<mystack.top();

    mystack.pop();
  }
  cout<<endl;
  return 0;
}
