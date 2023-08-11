#include <iostream>
#include <queue>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

//Flood Fill 변형 문제

char board[101][101];
bool rg[101][101];
bool visited[101][101];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int N, s_x, s_y;

void DFS(int x, int y, bool flag){
  (flag ? rg[x][y]=true : visited[x][y]=true); //이거 빼먹어서 계속 틀린 것.
  for(int i=0;i<4;i++){
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(nx>0 && ny>0 && nx<=N && ny<=N){
      if(flag){
        if(!rg[nx][ny] && (board[nx][ny]==board[s_x][s_y] || (board[s_x][s_y]=='G' && board[nx][ny]=='R') || (board[s_x][s_y]=='R' && board[nx][ny]=='G'))){
          DFS(nx,ny,flag);
        }
      }
      else{
        if(!visited[nx][ny] && board[nx][ny]==board[s_x][s_y]){
          DFS(nx,ny,flag);
        }
      }
    }
  }
}

void BFS(int x, int y, bool flag){
  queue<pair<int,int>> q;
  q.emplace(x,y);
  (flag ? rg[x][y]=true : visited[x][y]=true); //이거 빼먹어서 계속 틀린 것.
  while(!q.empty()){
    pair<int,int> cur=q.front();
    q.pop();
    for(int i=0;i<4;i++){
      int nx=cur.first+dx[i];
      int ny=cur.second+dy[i];
      if(nx>0 && ny>0 && nx<=N && ny<=N){
        if(flag){
          if(!rg[nx][ny] && (board[nx][ny]==board[s_x][s_y] || (board[s_x][s_y]=='G' && board[nx][ny]=='R') || (board[s_x][s_y]=='R' && board[nx][ny]=='G'))){
            q.emplace(nx,ny);
            rg[nx][ny]=true;
          }
        }
        else{
          if(!visited[nx][ny] && board[nx][ny]==board[s_x][s_y]){
            q.emplace(nx,ny);
            visited[nx][ny]=true;
          }
        }
      }
    }
  }
}

int main()
{
  FASTIO;
  cin >> N;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cin >> board[i][j];
    }
  }
  int cnt1=0, cnt2=0; //일반인, 적록색약
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      s_x=i; s_y=j;
      if(!visited[i][j]){
        //BFS(i,j,false);
        DFS(i,j,false);
        ++cnt1;
      }
      if(!rg[i][j]){ //else if -> if로 바꾸니까 맞음.. 왜지..?
        //BFS(i,j,true);
        DFS(i,j,true);
        ++cnt2;
      }
    }
  }
  cout << cnt1 << ' ' << cnt2;
  return 0;
}