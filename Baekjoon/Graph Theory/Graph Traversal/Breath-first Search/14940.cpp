#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int board[1001][1001];
int dist[1001][1001];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int n,m; 

void BFS(int x, int y){
  queue<pair<int,int>> q;
  q.emplace(x,y);
  while(!q.empty()){
    pair<int,int> cur=q.front();
    q.pop();
    for(int i=0;i<4;i++){
      int nx=cur.first+dx[i];
      int ny=cur.second+dy[i];
      if(nx>0 && ny>0 && nx<=n && ny<=m && !dist[nx][ny] && board[nx][ny]==1){
        q.emplace(nx,ny);
        dist[nx][ny]=dist[cur.first][cur.second]+1;
      }
    }
  }
}

int main()
{
  FASTIO;
  cin >> n >> m;
  int start_x, start_y;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      cin >> board[i][j];
      if(board[i][j]==2){
        start_x=i; start_y=j;
      }
    }
  }
  BFS(start_x,start_y);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(board[i][j]==1 && !dist[i][j]) //원래 갈 수 있는 땅인 부분 중에서 도달할 수 없는 위치
        dist[i][j]=-1;
      cout << dist[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}