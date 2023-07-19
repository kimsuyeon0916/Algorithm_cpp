#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

bool comp(pair<int,int> v1, pair<int,int> v2){
  if(v1.first==v2.first) return v1.second<v2.second;
  return v1.first<v2.first;
}

int main()
{
  FASTIO;
  int N; cin >> N;
  vector<pair<int,int>> v; //크기 설정 안해놔서, 인덱스 접근 X
  int x,y;
  for(int i=0;i<N;i++){
    cin >> x >> y;
    v.push_back({x,y}); //v.emplace_back(make_pair(x,y));
  }
  sort(v.begin(),v.end(),comp);
  for(pair<int,int> xy:v) cout << xy.first << " " << xy.second << '\n';
  return 0;
}