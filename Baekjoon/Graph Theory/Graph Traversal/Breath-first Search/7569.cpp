#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

void BFS(int z, int x, int y);

int board[100][100][100];
int dz[6]={1,-1,0,0,0,0};
int dx[6]={0,0,1,-1,0,0};
int dy[6]={0,0,0,0,-1,1};
int dist[100][100][100]={0,};
queue<pair<int,pair<int,int>>> q;
int M, N, H; //y,x,z
int result=0;
int main()
{
  FASTIO;
  cin >> M >> N >> H;
  for(int k=0;k<H;k++){
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        cin >> board[k][i][j];
        dist[k][i][j]=-1; //아직 방문 안한 토마토
        if(board[k][i][j]==1){
          q.emplace(make_pair(k,make_pair(i,j)));
          dist[k][i][j]=0;
        } 
      }
    }
  }

  BFS(q.front().first,(q.front().second).first,(q.front().second).second);

  for(int k=0;k<H;k++){
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(board[k][i][j]==0){
          cout << -1; //토마토가 모두 익지 못하는 상황
          return 0;
        } 
      }
    }
  }
  
  cout << result;
  return 0;
}

void BFS(int z, int x, int y){
  while(!q.empty()){
    pair<int,pair<int,int>> cur=q.front();
    q.pop();
    for(int i=0;i<6;i++){
      int nz=cur.first+dz[i];
      int nx=(cur.second).first+dx[i];
      int ny=(cur.second).second+dy[i];
      if(nz>=0 && nx>=0 && ny >=0 && nz<H && nx<N && ny<M && board[nz][nx][ny]==0 && dist[nz][nx][ny]==-1){
        q.emplace(make_pair(nz,make_pair(nx,ny)));
        board[nz][nx][ny]=1;
        dist[nz][nx][ny]=dist[cur.first][(cur.second).first][(cur.second).second]+1;
        result = max(dist[nz][nx][ny],result);
      }
    }
  }
}