#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

bool comp(pair<int,int> v1, pair<int,int> v2){
  if(v1.second==v2.second) return v1.first<v2.first; //return 빼먹어서 처음에 틀림
  return v1.second<v2.second;
}
int main()
{
  FASTIO;
  int N; cin >> N;

  vector<pair<int,int>> v(N);
  for(int i=0;i<N;i++) cin >> v[i].first >> v[i].second;

  sort(v.begin(),v.end(),comp);
  for(pair<int,int> xy:v) cout << xy.first << " " << xy.second <<'\n';
  return 0;
}