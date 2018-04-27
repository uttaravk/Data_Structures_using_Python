#include <iostream>
using namespace std;
  bool canWinNim(int n)
  {
            cout<<"method 1: "<<endl;
            int q=n/4;
            int ans=n-(q*4);
            if((ans==1)||(ans==2)||(ans==3))
            {
                return true;
            }
            return false;

            // cout<<"method 2: "<<endl;
            // return n%4;
    }

    int main()
    {
      bool x;
      int num=7;
      x=canWinNim(num);
      if(x==true)
      {
        cout<<"You can win"<<endl;
      }
      else
      {
        cout<<"You cannot win"<<endl;
      }

    }
