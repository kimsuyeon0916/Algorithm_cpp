#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N, K; cin >> N >> K;

  int result=1;
  for(int i=N;i>N-K;i--) result*=i;
  for(int j=1;j<=K;j++) result/=j;
  
  cout << result;
  return 0;
}