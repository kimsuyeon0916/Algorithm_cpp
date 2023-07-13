#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

//Flood Fill 문제(1차원 배열)+BFS(최단거리 문제)

void BFS(int x);

int line[100001];
bool visited[100001];
int dx[3]={-1,1,2}; //좌,우,순간이동
int dist[100001]={0,};
int N, K;
int main()
{
  FASTIO;
  cin >> N >> K;

  BFS(N);

  cout << dist[K];
  return 0;
}

void BFS(int x){
  queue<int> q;
  q.emplace(x);
  visited[x]=true;
  while(!q.empty()){
    int cur=q.front();
    q.pop();
    for(int i=0;i<3;i++){
      int nx=(i!=2?cur+dx[i]:dx[i]*cur);
      if(nx>=0 && nx<=100000 && !visited[nx]){ //처음에 여기 nx<=100000 등호 안들어가서 틀림
        q.emplace(nx);
        visited[nx]=true;
        dist[nx]=dist[cur]+1;
      }
    }
  }
}