#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

vector<pair<int,int>> period;

int main() {
  FASTIO;
  int N; cin >> N; 
  int max_cnt = 0;
  for (int i = 0; i < N; i++) {
    int s, e; cin >> s >> e;
    period.emplace_back(make_pair(e,s)); //뒤집어서 넣음
  }
  sort(period.begin(), period.end());
  int cnt = 1;
  int next=period[0].first;
  for(int idx=1;idx<N;idx++){
    if(period[idx].second>=next){ //같지 않을 수 있음
      ++cnt;
      next=period[idx].first;
    } 
  }
  cout << cnt;
  return 0;
}