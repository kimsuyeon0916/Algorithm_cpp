#include <iostream>
#include <vector>
using namespace std;

void DFS(int i);

void init(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}

int n, m, r;
vector<vector<int>> edge(n + 1, vector<int>(n + 1));
bool visited[100001]={0,};

int main(){
  init();
  cin >> n >> m >> r;
  int x, y;
  for(int i=1;i<=m;i++){
    cin >> x >> y;
    edge[x][y]=1; edge[y][x]=1;
  }

  DFS(1);
  return 0;
}

void DFS(int i){
  for(int j=1;j<=n;j++){
    if(visited[j]==1) return;
    else if(edge[i][j]==1 && visited[j]==0){
      visited[j]=true;
      cout << j << '\n';
      DFS(j);
    }
  }
}