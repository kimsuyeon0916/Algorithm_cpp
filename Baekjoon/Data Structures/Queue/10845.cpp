#include <iostream>
#include <queue>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N; cin >> N;
  queue<int> q;
  for(int i=1;i<=N;i++){
    string input; cin >> input;
    if(input=="push"){
      int x; cin >> x;
      q.emplace(x);
      //cout << x << '\n';
    }
    else if(input=="pop"){
      if(!q.empty()){
        cout << q.front() << '\n';
        q.pop(); //아예 조건문 바깥에 있으면 원소 없어도 빼져서 에러남.
      }
      else cout << -1 << '\n';
    }
    else if(input=="size") cout << q.size() << '\n';
    else if(input=="empty") cout << q.empty() << '\n';
    else if(input=="front") cout << (!q.empty()?q.front():-1) << '\n'; //!q.size()는 왜 안되지
    else if(input=="back") cout << (!q.empty()?q.back():-1) << '\n';
  }
  return 0;
}