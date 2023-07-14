#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

void BFS(int x, int y);

int board[1000][1000];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int dist[1000][1000]={0,};
queue<pair<int,int>> q;
int M, N; //y,x
int result=0;
int main()
{
  FASTIO;
  cin >> M >> N;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> board[i][j];
      dist[i][j]=-1; //아직 방문 안한 토마토
      if(board[i][j]==1){
        q.emplace(make_pair(i,j));
        dist[i][j]=0;
      }    
    }
  }

  BFS(q.front().first,q.front().second);

  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      if(board[i][j]==0){
        cout << -1; //토마토가 모두 익지 못하는 상황
        return 0;
      } 
    }
  }
  cout << result;
  return 0;
}

void BFS(int x, int y){
  while(!q.empty()){
    pair<int,int> cur=q.front();
    q.pop();
    for(int i=0;i<4;i++){
      int nx=cur.first+dx[i];
      int ny=cur.second+dy[i];
      if(nx>=0 && ny >=0 && nx<N && ny<M && board[nx][ny]==0 && dist[nx][ny]==-1){
        q.emplace(make_pair(nx,ny));
        board[nx][ny]=1;
        dist[nx][ny]=dist[cur.first][cur.second]+1;
        result=max(dist[nx][ny],result);
      }
    }
  }
}