#include <iostream>
#include <map>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

map<int, int> dist;
int A, B; 

void BFS(int start){
  queue<int> q;
  q.emplace(start);
  while(!q.empty()){
    long long cur=q.front(); //나중에 연산하고 범위가 넘어가는 경우가 존재하므로 long long 으로 해줘야 함
    q.pop();
    if(cur==B) return;
    if(cur*2<=B){
      q.emplace(cur*2);
      dist[cur*2]=dist[cur]+1;
    }
    if(cur*10+1<=B){
      q.emplace(cur*10+1);
      dist[cur*10+1]=dist[cur]+1;
    }
  }
}

int main()
{
  FASTIO;
  cin >> A >> B;
  BFS(A);
  cout << (dist[B]==0 ? -1 : dist[B]+1);
  return 0;
}