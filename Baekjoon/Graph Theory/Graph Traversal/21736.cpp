#include <iostream>
#include <queue>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

char board[601][601];
bool visited[601][601];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int N, M, cnt=0; 

void BFS(int x, int y){
  queue<pair<int, int>> q;
  q.emplace(x,y);
  visited[x][y]=true;
  while(!q.empty()){
    pair<int, int> cur=q.front();
    q.pop();
    for(int i=0;i<4;i++){
      int nx=cur.first+dx[i];
      int ny=cur.second+dy[i];
      if(nx>0 && ny>0 && nx<=N && ny<=M && !visited[nx][ny] && board[nx][ny]!='X'){
        if(board[nx][ny]=='P') ++cnt;
        q.emplace(nx,ny);
        visited[nx][ny]=true;
      }
    }
  }
}

void DFS(int x, int y){
  visited[x][y]=true;
  for(int i=0;i<4;i++){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(nx>0 && ny>0 && nx<=N && ny<=M && !visited[nx][ny] && board[nx][ny]!='X'){
        if(board[nx][ny]=='P') ++cnt;
        DFS(nx,ny);
      }
    }
}

int main()
{
  FASTIO;
  cin >> N >> M;
  int s_x, s_y; //시작 좌표
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      cin >> board[i][j];
      if(board[i][j]=='I'){
        s_x=i; s_y=j;
      }
    }
  }
  BFS(s_x,s_y);
  //DFS(s_x,s_y);
  if(!cnt) cout << "TT";
  else cout << cnt;
  return 0;
}