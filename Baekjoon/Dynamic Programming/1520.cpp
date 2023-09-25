#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int graph[500][500];
int dp[500][500]; //DP[r][c] = r행 c열에서 (M-1, N-1)로 가는 경우의 수
int N, M;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

int DFS(int x, int y){
  if(x==M-1 && y==N-1) return 1; //도착점에 도달한 경우
  else if(dp[x][y]==-1){  //처음 방문하는 경우에 계속 탐색
    dp[x][y]=0; //0으로 처리(해당 좌표에서 도착점까지 갈 수 있는 경로는 처음엔 0개로 초기화)
    for(int i=0;i<4;i++){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(nx>=0 && ny>=0 && nx<M && ny<N && graph[nx][ny]<graph[x][y]){ 
        dp[x][y]+=DFS(nx, ny); //항상 내리막길(높이가 더 낮은 지점)인 경우
      }
    }
  }
  return dp[x][y]; //이미 방문한 경우 기존에 저장된 값을 반환 혹은 연산 끝나고 값을 반환
}

int main()
{
  FASTIO;
  cin >> M >> N;
  for(int i=0;i<M;i++){
    for(int j=0;j<N;j++){
      cin >> graph[i][j];
      dp[i][j]=-1; //방문 안한 곳은 -1로 초기화
    }
  }
  cout << DFS(0,0);
  return 0;
}
