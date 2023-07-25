#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

vector<pair<int,int>> graph[20001]; //pair<정점, 가중치>
int dist[20001];

void dijkstra(int start){
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; //pair<최단 거리, 정점>
  pq.emplace(make_pair(0, start));
  dist[start]=0; //시작점 자기 자신은 0
  while(!pq.empty()){
    int cost=pq.top().first;
    int cur=pq.top().second;
    pq.pop();
    for(auto v : graph[cur]){
      if(dist[v.first]>cost+v.second){
        dist[v.first]=cost+v.second;
        pq.emplace(make_pair(dist[v.first],v.first));
      }
    }
  }
}

int main()
{
  FASTIO;
  int V,E,K; cin >> V >> E >> K;
  int u,v,w;
  for(int i=1;i<=E;i++){
    cin >> u >> v >> w;
    graph[u].emplace_back(make_pair(v,w)); //방향 그래프
  }

  fill_n(dist,V+1,2e9); //초기화
  dijkstra(K);

  for(int i=1;i<=V;i++){
    if(dist[i]==2e9) cout << "INF" <<'\n';
    else cout << dist[i] << '\n';
  }
  return 0;
}