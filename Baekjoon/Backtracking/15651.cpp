#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int num[9]; 
int N, M; 

void Backtraking(int depth){
  if(depth==M){
    for(int i=0;i<M;i++) cout << num[i] << ' '; //dfs 특성 상 결과는 한번에 이렇게 배열에 넣어놓는게 좋음.
    cout << '\n';
    return;
  }  
  for(int i=1;i<=N;i++){ //수 중복 가능. => 조건 필요 X
      num[depth]=i;
      Backtraking(depth+1);
  }
}

int main()
{
  FASTIO;
  cin >> N >> M;
  Backtraking(0);
  return 0;
}