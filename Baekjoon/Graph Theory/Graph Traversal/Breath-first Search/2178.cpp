#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

//Flood Fill 문제
void BFS(int x,int y);
int board[101][101];
bool visited[101][101]={0,};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
int dist[101][101]={0,}; 
int N, M; //x, y
int depth;
int main()
{
  FASTIO;
  cin >> N >> M;
  for(int i=1;i<=N;i++){
    string input; cin >> input;
    for(int j=1;j<=M;j++){
      board[i][j]=input[j-1]-'0';
    }
  }

  BFS(1,1);
  cout << dist[N][M];
  return 0;
}

void BFS(int x,int y){
  queue<pair<int,int>> q;
  q.emplace(make_pair(x,y));
  visited[x][y]=true;
  dist[x][y]=1; //출발지 거리는 1
  while(!q.empty()){
    pair<int,int> cur=q.front();
    int qs=q.size();
    q.pop();
    if(q.size()==0) ++depth;
    for(int i=0;i<4;i++){
      int nx=cur.first+dx[i];
      int ny=cur.second+dy[i];
      if(nx>0 && ny>0 && nx<=N && ny<=M && board[nx][ny]==1 &&!visited[nx][ny]){    
        q.emplace(make_pair(nx,ny));
        visited[nx][ny]=true;
        dist[nx][ny]=dist[cur.first][cur.second]+1; //최단 거리 업데이트 (방문 노드에서 +1 하면 최단거리; 일종의 dp)
      }
    }
  }
}