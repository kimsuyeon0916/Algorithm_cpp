#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void BFS(int start){
  queue<int> q;
  q.emplace(start);
  while(!q.empty()){
    int cur=q.front();
    q.pop();
    for(int v:graph[cur]){
      if(!visited[v]){
        q.emplace(v);
        visited[v]=true;
      }
    }
  }
}

void DFS(int vertex){
  visited[vertex]=true;
  for(int v:graph[vertex]){
    if(!visited[v]) DFS(v);
  }
}

int main()
{
  FASTIO;
  int N, M; cin >> N >> M;
  for(int i=1;i<=M;i++){
    int u, v; cin >> u >> v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  for(int i=1;i<=N;i++) sort(graph[i].begin(), graph[i].end());
  int cnt=0;
  for(int i=1;i<=N;i++){
    if(!visited[i]){
      BFS(i);
      //DFS(i);
      ++cnt;
    }
  }
  cout << cnt;
  return 0;
}