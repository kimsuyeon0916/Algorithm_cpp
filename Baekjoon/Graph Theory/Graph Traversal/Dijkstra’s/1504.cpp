#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 200000001
using namespace std;

int N,E; 
vector<pair<int,int>> graph[801];
int dist[801];

int dijkstra(int start, int end){ //인자 변형
  fill_n(dist,N+1,INF); //초기화
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
  pq.emplace(make_pair(0,start));
  dist[start]=0;
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
  return dist[end];
}

int main()
{
  FASTIO;
  cin >> N >> E;
  int a, b, c;
  for(int i=1;i<=E;i++){
    cin >> a >> b >> c;
    graph[a].emplace_back(make_pair(b,c));
    graph[b].emplace_back(make_pair(a,c)); //양방향 그래프(무방향 그래프)
  }
  int u,v; cin >> u >> v;

  int res1=dijkstra(1,u)+dijkstra(u,v)+dijkstra(v,N); //1->u->v->N
  int res2=dijkstra(1,v)+dijkstra(v,u)+dijkstra(u,N); //1->v->u->N
  int min_dist=min(res1,res2);
  cout << (min_dist<INF ? min_dist : -1);
  return 0;
}