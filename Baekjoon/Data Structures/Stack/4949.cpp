#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  string input;
  while(getline(cin,input) && input!="."){ //'.' 이전까지의 문자열(한 줄)을 str에 통째로 입력받음
    stack<char> s; //왼쪽 괄호만 들어있는 스택
    string result="yes";
    for(char c:input){
      if(c=='['||c=='(') s.emplace(c);
      else if(c==')'){
        if(!s.empty() && s.top()=='(') s.pop();
        else{
          result="no";
          break;
        } 
      }
      else if(c==']'){
        if(!s.empty() && s.top()=='[') s.pop();
        else{
          result="no";
          break;
        }
      }
    }
    if(!s.empty()) result="no";
    cout << result << '\n'; //.은 제외
  }
  return 0;
}