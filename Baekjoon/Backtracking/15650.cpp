#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int N, M;
bool visited[9];
int num[9];

void Backtraking(int n, int depth){
  if(depth==M){
    for(int i=0;i<M;i++) cout << num[i] << ' ';
    cout << "\n";
    return;
  }
  for(int i=n;i<=N;i++){
    if(!visited[i]){
      visited[i]=true;
      num[depth]=i;
      Backtraking(i,depth+1);
      visited[i]=false;
    }
  }
}

int main()
{
  FASTIO;
  cin >> N >> M;
  Backtraking(1,0); //숫자, 뎁스
  return 0;
}