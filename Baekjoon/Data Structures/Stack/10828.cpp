#include <iostream>
#include <vector>
#include <string>
using namespace std;

void init(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

string input[10002];
vector<string> stack;

int main(){
  init();
  int n; cin >> n;
  for(int i=1;i<=n+1;i++) getline(cin, input[i]);
  
  for(int i=1;i<=n+1;i++){
    if(input[i].substr(0,4)=="push") stack.emplace_back(input[i].substr(5));
    else if(input[i]=="pop"){
      if(stack.empty()) cout << "-1\n";
      else{
        cout << stack.back() <<'\n';
        stack.pop_back();
      } 
    }
    else if(input[i]=="size") cout << stack.size() << '\n';
    else if(input[i]=="empty") cout << stack.empty() << '\n';
    else if(input[i]=="top"){
      if(stack.empty()) cout << "-1\n";
      else cout << stack.back() <<'\n';
    } 
  }
  return 0;
}