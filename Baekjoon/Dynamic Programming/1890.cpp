#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int N;
int board[101][101];
long long dp[101][101];
int dx[2]={0,1}; //우, 하
int dy[2]={1,0};

/* 풀이2: DFS + DP */
long long DFS(int x, int y){
  if(x==N && y==N) return 1; //도착점에 도달한 경우
  else if(dp[x][y]==-1){  //처음 방문하는 경우에 계속 탐색
    dp[x][y]=0; //0으로 처리(해당 좌표에서 도착점까지 갈 수 있는 경로는 처음엔 0개로 초기화)
    for(int i=0;i<2;i++){
      int nx=x+board[x][y]*dx[i];
      int ny=y+board[x][y]*dy[i];
      if(nx>=1 && ny>=1 && nx<=N && ny<=N){ 
        dp[x][y] += DFS(nx, ny);
      }
    }
  }
  return dp[x][y]; //이미 방문한 경우 기존에 저장된 값을 반환 혹은 연산 끝나고 값을 반환
}

/* 풀이1: DP */
int main()
{
  FASTIO;
  cin >> N;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      cin >> board[i][j];
      //dp[i][j]=-1;
    }
  }
  //cout << DFS(1,1);
  dp[1][1]=1; //boundary condition
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(!board[i][j]) continue; //갈 수 있는 거리가 0인 경우, 여기서 더 이상 경로 존재 X => dp[i][j]==0
      for(int k=0;k<2;k++){
      int nx=i+board[i][j]*dx[k];
      int ny=j+board[i][j]*dy[k];
        if(nx>=1 && ny>=1 && nx<=N && ny<=N){ 
          dp[nx][ny]+=dp[i][j];
        }
      }
    }
  }
  cout << dp[N][N];
  return 0;
}
