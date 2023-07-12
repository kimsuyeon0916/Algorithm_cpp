#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

void BFS(int start);

vector<int> graph[101];
bool visited[101]={0,};
int num=-1;
int main()
{
  FASTIO;
  int N, M;
  cin >> N >> M;
  int u, v;
  for(int i=1;i<=M;i++){
    cin >> u >> v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  
  for(int i=1;i<=N;i++) sort(graph[i].begin(),graph[i].end());
  BFS(1);

  cout << num;
  return 0;
}

void BFS(int start){
  queue<int> q;
  q.emplace(start);
  visited[start]=true;
  while (!q.empty()){
    int cur=q.front();
    q.pop();
    ++num; //원래 여기가 맞는 위치
    for(int v:graph[cur]){
      if(!visited[v]){
        q.emplace(v);
        visited[v]=true;
        //++num; //잘못된 위치
      }
    }
  }
}