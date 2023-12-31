#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

long long dp[1001];

int main()
{
  FASTIO;
  int n; cin >> n;
  dp[1]=1; dp[2]=3; //boundary condition
  for(int i=3;i<=n;i++){
    dp[i]=(dp[i-1])%10007+(2*dp[i-2])%10007;
  }
  cout << dp[n]%10007;
  return 0;
}