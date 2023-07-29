#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N, K; cin >> N >> K;
  int coin[10];
  int cnt=0;
  for(int i=0;i<N;i++) cin >> coin[i];
  int num=K;
  for(int i=N-1;i>=0;i--){
    if(num/coin[i]>0){
      cnt+=num/coin[i];
      num%=coin[i];
    } 
  }
  cout << cnt;
  return 0;
}