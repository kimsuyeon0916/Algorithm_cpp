#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
  FASTIO;
  int N, K; cin >> N >> K;
  int psum[100001]={0,};
  for(int i=1;i<=N;i++){
    cin >> psum[i];
    psum[i]+=psum[i-1];
  }
  int res=-10000000;
  for(int i=K;i<=N;i++) res=max(res,psum[i]-psum[i-K]); 
  cout << res;
  return 0;
}