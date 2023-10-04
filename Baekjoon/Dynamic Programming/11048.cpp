#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int board[1001][1001];
int dp[1001][1001];
int dx[3]={0,-1,-1};
int dy[3]={-1,0,-1};

int main()
{
  FASTIO;
  int N, M; cin >> N >> M;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      cin >> board[i][j];
    }
  }
  dp[1][1]=board[1][1]; //boundary condition
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      for(int k=0;k<3;k++){
        int x=i+dx[k], y=j+dy[k]; //(i,j)까지 오기 바로 직전 좌표(x,y)의 경우 3가지
        if(x>=1 && y>=1 && x<=N && y<=M){
          dp[i][j]=max(dp[i][j], dp[x][y]+board[i][j]); //이전 경로에서 해당 지점까지 온 경우 중, 가장 큰 사탕 개수로 업데이트
        }
      } 
    }
  }
  cout << dp[N][M];
  return 0;
}