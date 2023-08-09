#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N, M; cin >> N >> M;
  vector<int> prefix_sum(N+1);
  for(int i=1;i<=N;i++){
    int x; cin >> x;
    prefix_sum[i]=prefix_sum[i-1]+x; //누적 => 일종의 DP
  } 
  for(int i=1;i<=M;i++){
    int x, y; cin >> x >> y;
    cout << prefix_sum[y]-prefix_sum[x-1] << '\n';
  }
  return 0;
}