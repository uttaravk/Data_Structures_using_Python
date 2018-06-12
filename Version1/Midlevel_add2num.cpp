#include <iostream>
#include <list>
#include <stack>
#include <cmath>
using namespace std;
int main()
{
  list<int> mylist1;
  stack<int> mystack;
  int x1=0; int x2=0; int count=0;
  list<int> mylist2;
  list<int> myres;
  list<int> :: iterator it;

  mylist1.insert(mylist1.begin(), 3);
  mylist1.insert(mylist1.begin(), 4);
  mylist1.insert(mylist1.begin(), 2);

  mylist2.insert(mylist2.begin(), 4);
  mylist2.insert(mylist2.begin(), 6);
  mylist2.insert(mylist2.begin(), 5);

  cout<<"List 1: ";
  for(it=mylist1.begin(); it!=mylist1.end(); it++)
  {
    cout<<(*it);
  }
  cout<<endl;
  cout<<"List 2: ";
  for(it=mylist2.begin(); it!=mylist2.end(); it++)
  {
    cout<<(*it);
  }
  cout<<endl;
  for(it=mylist1.begin(); it!=mylist1.end(); it++)
  {
    mystack.push(*it);
  }
  count=mylist1.size();
  while(!mystack.empty())
  {
    x1=x1+((pow(10,(count-1)))*mystack.top());
    mystack.pop();
    count--;
  }
  cout<<"Num 1: "<<x1<<endl;
  for(it=mylist2.begin(); it!=mylist2.end(); it++)
  {
    mystack.push(*it);
  }
  count=mylist2.size();
  while(!mystack.empty())
  {
    x2=x2+((pow(10,(count-1)))*mystack.top());
    mystack.pop();
    count--;
  }
  cout<<"Num 2: "<<x2<<endl;
  x1=x1+x2; //Addition
  cout<<"Sum: "<<x1<<endl;
  int rem=0;
  while(x1!=0)
  {
    rem=x1%10;
    myres.insert(myres.end(), rem);
    x1=x1/10;
  }
  cout<<"Result (List): ";
  for(it=myres.begin(); it!=myres.end(); it++)
  {
    cout<<(*it);
  }
  cout<<endl;
  return 0;
}
