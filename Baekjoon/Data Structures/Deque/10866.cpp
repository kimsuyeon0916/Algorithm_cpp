#include <iostream>
#include <algorithm>
#include <deque>  
#include <string> //사실 쓸 필요 X
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  deque<int> dq;
  int N; cin >> N;
  string input;
  cin.ignore();
  for(int i=1;i<=N;i++){
    getline(cin,input);
    if(input.substr(0,10)=="push_front") dq.emplace_front(stoi(input.substr(11)));
    else if(input.substr(0,9)=="push_back") dq.emplace_back(stoi(input.substr(10)));
    else if(input.substr(0,9)=="pop_front"){
      if(dq.empty()) cout << -1 <<'\n';
      else{
        cout << dq.front() << '\n';
        dq.pop_front();
      }
    }
    else if(input.substr(0,8)=="pop_back"){
      if(dq.empty()) cout << -1 <<'\n';
      else{
        cout << dq.back() << '\n';
        dq.pop_back();
      }
    }
    else if(input=="size") cout << dq.size() << '\n';
    else if(input=="empty") cout << dq.empty() << '\n';
    else if(input=="front") cout << (dq.empty() ? -1 : dq.front()) << '\n';
    else cout << (dq.empty() ? -1 : dq.back()) <<'\n'; //삼항연산자 쓸 땐, 소괄호 꼭 해주기
  }
  return 0;
}