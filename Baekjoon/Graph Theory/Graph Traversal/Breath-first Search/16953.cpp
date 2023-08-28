#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

vector<int> dist(1000000001,-1);
int A, B; 

void BFS(int start){
  queue<int> q;
  q.emplace(start);
  while(!q.empty()){
    int cur=q.front();
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
// 2 4 21 8 41 42 16 81 82 84 32 161 162
int main()
{
  FASTIO;
  cin >> A >> B;
  BFS(A);
  cout << dist[B]+2;
  return 0;
}