#include <iostream>

using namespace std;

long long dp[101]; long long input[101];
int main(){
  int n; cin >> n;
  for(int t=1;t<=n;t++) cin >> input[t];

  dp[1]=1; dp[2]=1; dp[3]=1; dp[4]=2; dp[5]=2; //boundary condition

  for(long long t=1;t<=n;t++){
    for(long long i=6;i<=input[t];i++) dp[i]=dp[i-1]+dp[i-5];
  }

  for(int t=1;t<=n;t++) cout << dp[input[t]] << endl;
  return 0;
}

