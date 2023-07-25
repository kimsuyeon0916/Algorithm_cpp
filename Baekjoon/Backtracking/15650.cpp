#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int N, M;
int num[9];

void Backtraking(int n, int depth){
  if(depth==M){
    for(int i=0;i<M;i++) cout << num[i] << ' ';
    cout << "\n";
    return;
  }
  for(int i=n;i<=N;i++){
    num[depth]=i;
    Backtraking(i+1,depth+1); //오름차순이므로 i+1, 굳이 visited 방문 필요 X 어차피 증가하는 순
  }
}

int main()
{
  FASTIO;
  cin >> N >> M;
  Backtraking(1,0); //숫자, 뎁스
  return 0;
}