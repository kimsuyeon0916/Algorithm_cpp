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
  vector<int> v;
  for(int i=1;i<=N;i++) q.emplace(i);
  int i=1;
  while(!q.empty()){
    if(i==K){
      i=0;
      v.emplace_back(q.front());
    }
    else q.emplace(q.front());
    q.pop();
    i++;
  }

  cout << '<';
  for(int i=0;i<v.size();i++){
    cout << v[i];
    if(i<v.size()-1) cout << ", " ;
  }
  cout << '>';
  return 0;
}