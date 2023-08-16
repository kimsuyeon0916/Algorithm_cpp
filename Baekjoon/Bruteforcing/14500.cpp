#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int board[500][500];
bool visited[500][500];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int N, M, sum, res;
bool flag;

void BackTracking(int x, int y, int depth){
  if(depth==4){ 
    res=max(res, sum);
    return;
  }
  for(int i=0;i<4;i++){
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(nx>=0 && ny>=0 && nx<N && ny<M){
      if(!visited[nx][ny]){
        visited[nx][ny]=true;
        sum+=board[nx][ny];
        BackTracking(nx,ny,depth+1);
        sum-=board[nx][ny];
        visited[nx][ny]=false; //BackTracking
      } 
      else if(visited[nx][ny] && flag){
        flag=false;
        BackTracking(nx,ny,depth);
        flag=true;
      } 
    }
  }
}

int main()
{
  FASTIO;
  cin >> N >> M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> board[i][j];
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      visited[i][j]=true;
      sum=board[i][j]; //이미 1개 골랐다 가정=>3개만 고르면 됨(depth==3까지)
      flag=true;
      BackTracking(i,j,1);
      fill_n(&visited[0][0], 500*500, 0);
    }
  }
  cout << res;
  return 0;
}
