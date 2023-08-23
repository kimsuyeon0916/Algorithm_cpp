#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int N, M;
vector<int> v;
int res[8];
bool visited[8];

void BackTracking(int depth, int idx){
  if(depth==M){
    for(int i=0;i<M;i++) cout << res[i] << ' ';
    cout << '\n';
    return;
  }
  for(int i=idx;i<N;i++){
    res[depth]=v[i];
    BackTracking(depth+1, i);
  }
}

int main()
{
  FASTIO;
  cin >> N >> M;
  for(int i=0;i<N;i++){
    int x; cin >> x;
    v.emplace_back(x);
  }
  sort(v.begin(), v.end());
  BackTracking(0, 0);
  return 0;
}