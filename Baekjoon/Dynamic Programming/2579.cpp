#include <iostream>
#include <algorithm>

using namespace std;

int dp[301][2]={0,}; int input[301];

int main(){
  int n; cin >> n;
  for(int i=1;i<=n;i++) cin >> input[i];

  int result=0; 
  dp[1][0]=input[1]; dp[2][0]=dp[1][0]+input[2]; dp[2][1]=input[2]; //boundary condition
  for(int i=3;i<=n;i++){
    dp[i][0]=input[i]+max(dp[i-1][0],dp[i-1][1]);
    if(dp[i-2][0]+input[i-1]==dp[i-1][0]||dp[i-2][1]+input[i-1]==dp[i-1][0]) dp[i][0] = input[i]+dp[i-1][1];
    dp[i][1]=input[i]+max(dp[i-2][0],dp[i-2][1]);
  }

  cout << max(dp[n][0],dp[n][1]);
  return 0;
}
