#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> graph[101]; //인접 리스트(벡터 배열)
int dist[101];
int law[101];

void BFS(int start){
  queue<int> q;
  q.emplace(start);
  while(!q.empty()){
    int cur=q.front();
    q.pop();
    for(int v:graph[cur]){
      if(!dist[v]){
        q.emplace(v);
        dist[v]=dist[cur]+1; //케빈 베이컨 단계 수
        law[v]+=dist[v]; //케빈 베이컨 단계 총합
      }
    }
  }
}

int main()
{
  FASTIO;
  int N, M; cin >> N >> M;
  for(int i=1;i<=M;i++){
    int A, B; cin >> A >> B;
    graph[A].emplace_back(B);
    graph[B].emplace_back(A);
  }
  
  for(int i=1;i<=N;i++) sort(graph[i].begin(), graph[i].end());
  for(int i=1;i<=N;i++){
    fill_n(dist,101,0);
    BFS(i);
  }

  int idx, min_res=500000;
  for(int i=1;i<=N;i++){
    if(min_res>law[i]){
      min_res=law[i]; //케빈 베이컨의 수가 가장 작은 사람 고르기
      idx=i;
    }
  }
  cout << idx;
  return 0;
}