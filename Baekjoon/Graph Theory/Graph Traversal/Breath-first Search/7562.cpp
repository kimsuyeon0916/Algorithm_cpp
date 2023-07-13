#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

//Flood Fill + BFS
void BFS(int x, int y);

bool visited[300][300]={0,};
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={-2,-1,1,2,2,1,-1,-2};
int dist[300][300]={0,};
int l;
int main()
{
  int sx, sy, dx, dy;
  FASTIO;
  int T; cin >> T;
  for(int i=1;i<=T;i++){
    cin >> l >> sx >> sy >> dx >> dy;
    
    fill_n(visited[0],90000,false);
    fill_n(dist[0],90000,false);
    BFS(sx,sy);

    cout << dist[dx][dy] << '\n';
  }
  return 0;
}

void BFS(int x, int y){
  queue<pair<int,int>> q;
  q.emplace(make_pair(x,y));
  visited[x][y]=true;
  dist[x][y]=0;
  while (!q.empty()){
    pair<int,int> cur=q.front();
    q.pop();
    for(int i=0;i<8;i++){
      int nx=cur.first+dx[i];
      int ny=cur.second+dy[i];
      if(nx>=0 && ny>=0 && nx<l && ny<l && !visited[nx][ny]){
        q.emplace(make_pair(nx,ny));
        visited[nx][ny]=true;
        dist[nx][ny]=dist[cur.first][cur.second]+1;
      }
    }
  }
}
