#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

bool visited[9];
int res[9]; 
int N, M; 

void Backtraking(int depth){
  if(depth==M){
    for(int i=0;i<M;i++) cout << res[i] << " "; //dfs 특성 상 결과는 한번에 이렇게 배열에 넣어놓는게 좋음.
    cout << '\n';
    return;
  }  
  for(int i=1;i<=N;i++){
    if(!visited[i]){
      visited[i]=true;
      res[depth]=i;
      Backtraking(depth+1); //depth++ 혹은 ++depth 이렇게 하면, for문 내에서 증가해서 잘못됨.
      visited[i]=false;
    } 
  }
}

int main()
{
  FASTIO;
  cin >> N >> M;
  Backtraking(0);
  return 0;
}