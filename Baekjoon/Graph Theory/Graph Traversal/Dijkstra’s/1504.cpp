#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define INF 200000001
using namespace std;

vector<pair<int,int>> graph[801];
int dist[801];

void dijkstra(int start){
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
}

int main()
{
  FASTIO;
  int N,E; cin >> N >> E;
  int a, b, c;
  for(int i=1;i<=E;i++){
    cin >> a >> b >> c;
    graph[a].emplace_back(make_pair(b,c));
    graph[b].emplace_back(make_pair(a,c)); //양방향 그래프(무방향 그래프)
  }
  int u,v; cin >> u >> v;


  int res1=0,res2=0;
  fill_n(dist,N+1,INF);
  dijkstra(1);
  res1+=dist[u]; //1->u
  res2+=dist[v]; //1->v

  fill_n(dist,N+1,INF);
  dijkstra(v);
  res2+=dist[u]; //1->v + v->u
  res1+=dist[N]; //1->u + v->N

  fill_n(dist,N+1,INF);
  dijkstra(u);
  res1+=dist[v]; //1->u + v->N + u->v => 1->u->v->N
  res2+=dist[N]; //1->v + v->u + u->N => 1->v->u->N
  
  int min_dist=min(res1,res2);
  cout << (min_dist<INF ? min_dist : -1);
  return 0;
}