#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

//Flood Fill 이용해서 리팩토링
void DFS(int x, int y); //DFS 풀이
void BFS(int x, int y); //BFS 풀이

int board[25][25]; //인접 행렬 이용
bool visited[25][25]={0,};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
vector<int> result;
int N;
int c=0;
int main()
{
  FASTIO;
  cin >> N;
  for(int i=0;i<N;i++){
    string input; cin >> input;
    for(int j=0;j<N;j++){
      board[i][j]=input[j]-'0'; //char* to int
    }
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(board[i][j]==1 && !visited[i][j]){
        c=0;
        DFS(i,j);
        //BFS(i,j);
        result.emplace_back(c);
      }
    }
  }
  sort(result.begin(),result.end());
  
  cout << result.size() << '\n';
  for(int r : result) cout << r << '\n';
  return 0;
}

void DFS(int x, int y){
  visited[x][y]=true;
  ++c;
  for(int i=0;i<4;i++){
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(nx>=0 && ny>=0 && nx<N && ny<N && board[nx][ny]==1 && !visited[nx][ny])
      DFS(nx,ny);
  }
}

void BFS(int x, int y){
  queue<pair<int,int>> q;
  q.emplace(make_pair(x,y));
  visited[x][y]=true;
  c=0;
  while(!q.empty()){
    pair<int,int> cur=q.front();
    q.pop();
    ++c;
    for(int i=0;i<4;i++){
      int nx=cur.first+dx[i];
      int ny=cur.second+dy[i];
      if(nx>=0 && ny>=0 && nx<N && ny<N && board[nx][ny]==1 && !visited[nx][ny]){
        q.emplace(make_pair(nx,ny));
        visited[nx][ny]=true;
      }
    }
  }
}
