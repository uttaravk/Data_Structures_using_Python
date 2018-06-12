#include <iostream>
#include <map>
using namespace std;

// static inline string intToRoman(int num)
//     {
//         static const string M[] = {"","M","MM","MMM"};
//         static const string C[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
//         static const string X[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
//         static const string I[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
//         return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[(num % 10)];
//     }


// string intToRoman(int num) {
//         string res="";
//         vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
//         vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
//         for(int i=0;i<val.size();++i){
//             while(num>=val[i]){
//                 res+=str[i];
//                 num-=val[i];
//             }
//         }
//         return res;
//     }


string intToRoman(int num)
{
  map<int, string> m = {{1000, "M"}, {500, "D"}, {100, "C"}, {50, "L"}, {10, "X"}, {5, "V"},
  {900, "CM"}, {400, "CD"}, {90, "XC"}, {40, "XL"}, {9, "IX"}, {4, "IV"}, {1, "I"}};
  int arr[]={1000,900,500,400,100,90,50,40,10,9,5,4,1,0};
  string res;
  int i=0;
  int y=arr[i];
  while(y>=1)
  {
    if(num>=y)
    {
      num=num-y;
      res=res+m[y];
    }
    else
    {
        y=arr[i++];
    }
  }
  return res;
}


int main()
{
  int x=78;
  cout<<"Roman: "<<intToRoman(x)<<endl;
  return 0;
}
