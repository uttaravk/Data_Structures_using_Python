#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
  vector <string> words={"put", "Dad", "Man"};
    vector <string> res;
  std::map<int, std::vector<char>> mymap
    {
      {1,{'q','Q','w','W','e','E','r','R','t','T','y','Y','u','U','i','I','o','O','p','P'}},{2,{'a','A','S','s','d','D','f','F','g','G','H','h','j','J','k','K','l','L'}},
      {3,{'z','Z','x','X','c','C','v','V','b','B','n','N','m','M'}}
    };
    string temp;
    int flag=2;
    std::map<int, std::vector<char>>::iterator itr;
    itr=mymap.find(1);
    auto x=itr->second.begin();
    for(int i=0; i<words.size(); i++)
    {
      temp=words[i];
      itr=mymap.find(1);
      x=itr->second.begin();
      for(int i=0; i<temp.length(); i++)
      {
        if(flag!=0)
        {
          x=itr->second.begin();
          while(x!=itr->second.end())
          {
              if(temp[i]==*x)
              {
                flag=1;
                break;
              }
              else
              {
                flag=0;
                advance(x,1);
              }
            }
          }
          else
          {
            break;
          }
        }
        if(flag==1)
        {
          res.insert(res.end(),temp);
        }
        else
        {
          flag=2;
          itr=mymap.find(2);
          x=itr->second.begin();
          for(int i=0; i<temp.length(); i++)
          {
            if(flag!=0)
            {
              x=itr->second.begin();
              while(x!=itr->second.end())
              {
                  if(temp[i]==*x)
                  {
                    flag=1;
                    break;
                  }
                  else
                  {
                    flag=0;
                    advance(x,1);
                  }
                }
              }
              else
              {
                break;
              }
            }
            if(flag==1)
            {
              res.insert(res.end(),temp);
            }
            else
            {
              flag=2;
                itr=mymap.find(3);
          x=itr->second.begin();
          for(int i=0; i<temp.length(); i++)
          {
            if(flag!=0)
            {
              x=itr->second.begin();
              while(x!=itr->second.end())
              {
                  if(temp[i]==*x)
                  {
                    flag=1;
                    break;
                  }
                  else
                  {
                    flag=0;
                    advance(x,1);
                  }
                }
              }
              else
              {
                break;
              }
            }
            if(flag==1)
            {
              res.insert(res.end(),temp);
            }
                else
                {
                    flag=2;
                }
            }
          }
      }
      for(int i=0; i<res.size(); i++)
      {
        cout<<res[i]<<endl;
      }
  return 0;
}
