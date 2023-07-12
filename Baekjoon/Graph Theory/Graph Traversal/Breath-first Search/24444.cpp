#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

void BFS(int vertex);

vector<int> graph[100001];
int visited[100001]={0,};
queue<int> q;

int main()
{
  FASTIO;
  int N, M, R;
  cin >> N >> M >> R;
  int u, v;
  for(int i=1;i<=M;i++){
    cin >> u >> v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }

  for(int i=1;i<=N;i++) sort(graph[i].begin(),graph[i].end());
  BFS(R);

  for(int i=1;i<=N;i++) cout << visited[i] << '\n';
  return 0;
}

int s=0;
void BFS(int start){
  q.emplace(start);
  visited[start]=++s;
  while(!q.empty()){
    int cur=q.front();
    q.pop();
    for(int vertex : graph[cur]){
      if(!visited[vertex]){
        q.emplace(vertex);
        visited[vertex]=++s;
      }
    }
  }
}