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
    Backtraking(i,depth+1); //i+1이면 그냥 오름차순, i넣으면 비내림차순
  }
}

int main()
{
  FASTIO;
  cin >> N >> M;
  Backtraking(1,0);
  return 0;
}