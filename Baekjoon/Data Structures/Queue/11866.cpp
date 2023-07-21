#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N,K; cin >> N >> K;

  queue<int> q;
  for(int i=1;i<=N;i++) q.emplace(i);
  int i=0;
  cout << '<';
  while(!q.empty()){
    if(++i==K){
      i=0;
      cout << q.front();
      if(i<q.size()-1) cout << ", " ;
    }
    else q.emplace(q.front());
    q.pop();
  }
  cout << '>';
  return 0;
}