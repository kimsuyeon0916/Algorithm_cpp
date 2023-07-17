#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

//Flood Fill(2차원 배열) + BFS(최단경로)
int BFS(int x,int y,int wall); //매번 void일 필요 X

int board[1001][1001]={0,}; //C++에서 전역 변수와 정적 변수는 프로그램이 시작될 때 0 또는 널(null)로 초기화
int dist[1001][1001][2];//dist 쓸 땐, 굳이 visited 필요 X (벽을 부순 상태도 추가로 저장)
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int N,M;
int main()
{
  FASTIO;
  cin >> N >> M;
  string input;
  for(int i=1;i<=N;i++){
    cin >> input;
    for(int j=1;j<=M;j++){
      board[i][j]=input[j-1]-'0'; //1부터 시작할 땐 j-1(이것땜에 시간 많이 소비)
    }
  }

  cout << BFS(1,1,1); //아직 벽을 부수지 않은 상태

  return 0;
}


int BFS(int x,int y,int wall){
  queue<pair<pair<int,int>,int>> q;
  q.emplace(make_pair(make_pair(x,y),wall));
  dist[x][y][wall]=1;
  while(!q.empty()){
    pair<pair<int,int>,int> cur=q.front();
    q.pop();
    if ((cur.first).first == N && (cur.first).second == M) //목표에 도착했을 경우
      return dist[(cur.first).first][(cur.first).second][cur.second];
    for(int i=0;i<4;i++){
      int nx=(cur.first).first+dx[i];
      int ny=(cur.first).second+dy[i];
      int nwall=cur.second;
      if(nx>=1 && ny>=1 && nx<=N && ny<=M){
        if(board[nx][ny]==1 && nwall){ //다음 칸이 벽이고, 부술 수 있는 경우
          q.emplace(make_pair(make_pair(nx,ny),nwall-1));
          dist[nx][ny][nwall-1]=dist[(cur.first).first][(cur.first).second][nwall]+1;
        }
        else if(board[nx][ny]==0 && !dist[nx][ny][nwall]) //다음 칸이 벽이 아니고, 아직 방문하지 않은 경우
        q.emplace(make_pair(make_pair(nx,ny),nwall));
        dist[nx][ny][nwall]=dist[(cur.first).first][(cur.first).second][nwall]+1;
      }
    }
  }
  return -1;
}