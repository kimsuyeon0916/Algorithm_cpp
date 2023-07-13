#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

void BFS(int x, int y);
void DFS(int x, int y);
//Flood Fill(Seed Fill) 문제
int board[50][50]={0,};
bool visited[50][50]={0,};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int M, N, K;
int c;
int main()
{
  FASTIO;
  int T; cin >> T;
  for(int t=1;t<=T;t++){
    cin >> M >> N >> K;
    fill_n(board[0],2500,0); //테케마다 초기화
    fill_n(visited[0],2500,false); //테케마다 초기화
    int X, Y;
    for(int i=1;i<=K;i++){
      cin >> Y >> X;
      board[X][Y]=1;
    }

    c=0;
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        if(board[i][j]==1 && !visited[i][j]){
          //DFS(i,j);
          BFS(i,j);
          ++c;
        }
      }
    }
    cout << c << '\n';
  }
  return 0;
}

void DFS(int x, int y){
  visited[x][y]=true;
  for(int i=0;i<4;i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(nx>=0 && ny>=0 && nx<N && ny<M && board[nx][ny]==1 && !visited[nx][ny]){
      DFS(nx, ny);
    }
  }
}

void BFS(int x, int y){
  queue<pair<int,int>> q;
  q.emplace(make_pair(x,y));
  visited[x][y]=true;
  while(!q.empty()){
    pair<int,int> cur=q.front();
    q.pop();
    for(int i=0;i<4;i++){
    int nx = cur.first+dx[i];
    int ny = cur.second+dy[i];
    if(nx>=0 && ny>=0 && nx<N && ny<M && board[nx][ny]==1 && !visited[nx][ny]){
      q.emplace(make_pair(nx,ny));
      visited[nx][ny]=true;
    }
  }
  }
}