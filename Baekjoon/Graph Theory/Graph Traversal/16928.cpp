#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

//Flood Fill(1차원 배열) + BFS(최단 경로)

void BFS(int start);

vector<int  > graph(100); //사다리+뱀 (어차피 최대 1개라서, 그냥 벡터로만 해도 충분)
bool visited[100]={0,};
int dist[100]={0,};
int N, M, res=0;
int main()
{
  FASTIO;
  int c=1;
  cin >> N >> M;
  int x,y,u,v;
  for(int i=0;i<100;i++) graph[i]=i; //자기 자신 -> 자기 자신(이게 핵심)
  for(int i=1;i<=N;i++){
    cin >> x >> y;
    graph[x-1]=y-1;
  }
  for(int i=1;i<=M;i++){
    cin >> u >> v;
    graph[u-1]=v-1;
  }

  BFS(0);

  cout << dist[99];
  return 0;
}

void BFS(int start){
  queue<int> q;
  q.emplace(start);
  visited[start]=true;
  while (!q.empty()){
    int cur=q.front();
    q.pop();
    for(int i=1;i<=6;i++){
      int v=cur+i;
      if(v<100) v=graph[v];
      if(v<100 && !visited[v]){
        q.emplace(v);
        visited[v]=true;
        dist[v]=dist[cur]+1;
      }
    }
  }
}