#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int T; cin >> T;

  for(int i=1;i<=T;i++){
    stack<char> s;
    string input; cin >> input;
    for(char c:input) s.emplace(c);

    int left=0, right=0;
    string result="YES";
    while(!s.empty()){
      if(s.top()=='(') left++;
      else right++;
      
      s.pop();

      if(left>right){
        result="NO";
        break;
      }
    }
    if(left!=right) result="NO";

    cout << result << '\n';
  }
  return 0;
}