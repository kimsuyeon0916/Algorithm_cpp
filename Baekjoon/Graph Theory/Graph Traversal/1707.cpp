#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

void DFS(int parent,int v);

vector<int> graph[20001];
int visited[20001];
int main()
{
  FASTIO;
  int K; cin >> K;
  int V,E;
  for(int i=1;i<=K;i++){
    string result="YES";
    fill_n(visited,20001,0); //테케마다 초기화
    for(int i=0;i<=20000;i++) graph[i].clear();
    cin >> V >> E;
    int u, v;
    for(int i=1;i<=E;i++){
      cin >> u >> v;
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }
    for(int i=1;i<=V;i++) sort(graph[i].begin(), graph[i].end());

    visited[0]=-1;
    for(int i=1;i<=V;i++){ //모든 정점 확인해야 함
      if(visited[i]==0){
        DFS(0,i);
      }
    }
 
    for(int i=1;i<=V;i++){
      for(int vertex:graph[i]){
        if(visited[vertex]==visited[i]){ //처음에 i대신 복붙한 그대로 적어서 계속 틀림;;
          result = "NO";
          break;
        } 
      }
      if(result=="NO") break;
    }
    cout << result << '\n';
  }
  return 0;
}

void DFS(int parent,int v){
  visited[v]=-visited[parent];
  for(int vertex:graph[v]){
    if(!visited[vertex]){
      DFS(v,vertex);
    }
  }
}