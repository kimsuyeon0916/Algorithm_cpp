#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int N, M;
bool visited[8];
vector<int> v; //입력받은 숫자 벡터
vector<int> res;
set<vector<int>> s; //결과 수열

void BackTracking(int depth){
  if(depth == M){
    if(s.find(res) == s.end()){ //중복되지 않는 경우
      s.insert(res);
      for(int i=0;i<res.size();i++) cout << res[i] << ' '; 
      cout << '\n';
    }
    return;
  }
  for(int i=0;i<N;i++){
    if(!visited[i]){
      visited[i]=true;
      res.emplace_back(v[i]);
      BackTracking(depth+1);
      visited[i]=false;
      res.pop_back();
    }
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
  sort(v.begin(), v.end()); //사전 순(오름차순) 출력
  BackTracking(0);
  return 0;
}