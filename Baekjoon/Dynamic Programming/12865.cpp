#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0)
using namespace std;

int dp[101][100001]; //dp[i][w] => i번째 물건까지 이용해서 w를 채우는 가치의 최댓값
vector<pair<int, int>> v; //무게(W), 가치(V)를 저장

int main()
{
  FASTIO;
  int N, K; cin >> N >> K;
  v.emplace_back(0,0); //for boundary condition
  for(int i=1;i<=N;i++){
    int W, V; cin >> W >> V;
    v.emplace_back(W,V); //push_back({W,V})
  }

  sort(v.begin(), v.end()); //무게 순 정렬
  for(int i=1;i<=N;i++){
    for(int j=1;j<=K;j++){
      dp[i][j]= dp[i-1][j]; //해당 물건을 담든 안담든, (위의 가치)로 업데이트
      if(j>=v[i].first){ //해당 물건을 담을 수 있는 경우
        dp[i][j]= max(dp[i][j], v[i].second+ dp[i-1][j-v[i].first]); //(위의 가치)와 (해당 물건 가치 + 나머지 용량을 채우는 경우의 가치) 중 큰 것 업데이트 
      }
    }
  }

  cout << dp[N][K]; //dp 자체가 계속 누적 업데이트 되므로, 가장 마지막 물건까지 고려한 것이 정답
  return 0;
}

