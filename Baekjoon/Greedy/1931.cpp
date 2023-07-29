#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
  if(a.second==b.second) return a.first < b.first; //오름차순
  return a.second < b.second; //오름차순
}

int main() {
  FASTIO;
  int N; cin >> N; 
  int max_cnt = 0;
  vector<pair<int,int>> period;
  for (int i = 0; i < N; i++) {
    int s, e; cin >> s >> e;
    period.emplace_back(make_pair(s,e));
  }
  sort(period.begin(), period.end(),cmp);
  int cnt = 1;
  int next=period[0].second;
  for(int idx=1;idx<N;idx++){
    if(period[idx].first>=next){ //같지 않을 수 있음
      ++cnt;
      next=period[idx].second;
    } 
  }
  cout << cnt;
  return 0;
}
