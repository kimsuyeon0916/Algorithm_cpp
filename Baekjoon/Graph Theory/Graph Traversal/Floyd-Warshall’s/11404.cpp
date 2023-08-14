#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int dist[101][101];

int main()
{
  FASTIO;
  int n,m; cin >> n >> m;
  fill_n(&dist[0][0],101*101,1e9); //2차원 벡터로 바로 초기화해도 좋았을 듯
  for(int i=1;i<=m;i++){
    int a, b, c;
    cin >> a >> b >> c;
    dist[a][b]=min(dist[a][b],c); //시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
  }

  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
      }
    }
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(dist[i][j]==1e9 || i==j) cout << 0 << ' '; //시작 도시와 도착 도시가 같은 경우는 없다.
      else cout << dist[i][j] <<' ';
    }
    cout << '\n';
  }
  return 0;
}