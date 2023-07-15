#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

//Flood Fill(1차원 배열) + BFS(최단 경로)

void BFS(int start);

//0부터 시작할지, 1부터 시작할 지는 문제에 따라 다르니까 유연하게 설정
int graph[101]; //사다리+뱀+나머지 (어차피 최대 1개라서, 그냥 1차원 배열로 해도 충분)
int dist[101]={0,};
int N, M, res=0;
int main()
{
  FASTIO;
  int c=1;
  cin >> N >> M;
  int x,y;
  for(int i=1;i<=100;i++) graph[i]=i; //자기 자신 -> 자기 자신(이게 핵심;이미 문제에 주어진 힌트)
  for(int i=1;i<=N+M;i++){
    cin >> x >> y;
    graph[x]=y;
  }

  BFS(1);

  cout << dist[100];
  return 0;
}

void BFS(int start){
  queue<int> q;
  q.emplace(start);
  while (!q.empty()){
    int cur=q.front();
    q.pop();
    for(int i=1;i<=6;i++){
      int v=cur+i;
      if(v<=100) v=graph[v]; //조건문 안넣으면 인덱스 에러 날 수 있음
      if(v<=100 && dist[v]==0){
        q.emplace(v);
        dist[v]=dist[cur]+1;
      }
    }
  }
}