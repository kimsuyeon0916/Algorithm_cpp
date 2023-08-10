#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int dist[101][101]={0,}; // 인접 행렬 이용

int main()
{
  FASTIO;
  int N; cin >> N;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){ 
      cin >> dist[i][j];
      if (dist[i][j] == 0) dist[i][j] = 1e9;
    }
  }

  for(int k = 1; k<=N; k++){ 
    for(int i = 1; i<=N; i++){ 
      for(int j = 1; j<=N; j++){ 
          dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
      }
	  }
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if(dist[i][j] == 1e9) cout << 0 << ' ';
			else cout << 1 << ' ';
		}
		cout << '\n';
	}
  return 0;
}
