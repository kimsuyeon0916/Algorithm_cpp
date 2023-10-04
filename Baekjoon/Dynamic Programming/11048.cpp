#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int board[1001][1001];
int dp[1001][1001];

int main()
{
  FASTIO;
  int N, M; cin >> N >> M;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      cin >> board[i][j];
    }
  }
  for(int i=1;i<=N;i++){
    for(int j=1;j<=M;j++){
      //(i,j)까지 오기 바로 직전 좌표의 경우 3가지
      dp[i][j] = max({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + board[i][j];
    } 
  }
  cout << dp[N][M];
  return 0;
}