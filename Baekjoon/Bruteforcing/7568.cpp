#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N; cin >> N;
  vector<pair<int,pair<int,int>>> v(N);
  for(int i=0;i<N;i++) cin >> (v[i].second).first >> (v[i].second).second;
  for(auto p :v) cout << count_if(v.begin(),v.end(), [&p](pair<int,pair<int,int>> j) { return ((j.second).first > (p.second).first && (j.second).second > (p.second).second);})+1 << " ";
  return 0;
}