#include <iostream>
#include <unordered_set>
#include <vector>
#include <stack>
using namespace std;

int main()
{
  vector<string>myvec;
  unordered_set<string>myset;
  stack<string>mystack;
  myvec={"ACQUIRE 1","RELEASE 1","ACQUIRE 2"};
  string temp;
  for(int i=0; i<myvec.size(); i++)
  {
    int vsize=myvec[i].length();
    string x=myvec[i].substr(8,vsize);
    string temp=myvec[i].substr(0,7);
    if(temp=="ACQUIRE")
    {
      if(!(myset.find(myvec[i]) != myset.end()))
      {
        myset.insert(myvec[i]);
        mystack.push(myvec[i]);
      }
      else
      {
        cout<<"Lock is already acquired"<<endl;
        cout<<"Element Present (ID): "<<x<<endl;
        break;
      }
    }
    else if(temp=="RELEASE")
    {
      string temp2=mystack.top();
      string mytemp="RELEASE "+temp2.substr(8,vsize);
      if(myvec[i]==(mytemp))
      {
        mystack.pop();
        myset.erase(temp2);
      }
      else
      {
        cout<<"Lock cannot be release (not in seq)"<<endl;
        cout<<"Element Absent (ID): "<<x<<endl;
      }
    }
  }
  if(!mystack.empty())
  {
    cout<<"Stack not empty"<<endl;
    cout<<"Dangling Locks: "<<mystack.size()<<endl;
  }
  return 0;
}
