#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int N,M;
bool visited[8];
vector<int> v; //입력 숫자
vector<int> res; //출력 숫자
void BackTracking(int depth){
  if(depth==M){ //종료 조건
    for(int i:res) cout << i << ' ';
    cout << '\n';
    return;
  }
  for(int i=0;i<v.size();i++){
    if(!visited[i]){ //promising 조건
      visited[i]=true;
      res.emplace_back(v[i]); //결과에 넣기(v[i] 대신 i넣어서 처음엔 헤맴)
      BackTracking(depth+1);
      visited[i]=false;
      res.pop_back(); //결과에서 꺼내기
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
  sort(v.begin(),v.end());
  BackTracking(0);
  return 0;
}