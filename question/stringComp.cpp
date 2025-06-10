#include <algorithm>
#include<iostream>
#include <string>


using namespace std;




int main(){
  int n;
  cin >> n;
  
  string s = ""; 
  char ch;
 while (s.size() < n && cin >> ch) {
        s += ch;
    }
  
  int count = 1;
  string newS ="";
  char c = s[0];

  for(int i = 1;i < s.length();++i){
    if(s[i] == c){
      count++;
    }else{
      newS += c + to_string(count);
      c = s[i];
      count = 1;
    }
  };
   newS += c + to_string(count);
  cout << newS;
  return 0;
}
